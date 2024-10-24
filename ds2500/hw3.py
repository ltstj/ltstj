"""
Created on Tue Apr 2 3:23:12 2024
@author: tjkalapatapu
DS2500
"""

import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split, KFold, cross_validate
from sklearn.neighbors import KNeighborsClassifier
from sklearn.preprocessing import LabelEncoder
from sklearn import metrics


def main():
    #loading the datasets
    elections = pd.read_csv("/Users/tjkalapatapu/Desktop/ds2500/1976-2020-president.tab", delimiter='\t')
    demographics = pd.read_csv("/Users/tjkalapatapu/Desktop/ds2500/demographics.csv")
   
    #cleaning the data sets and making them more usable
    demographics["state"] = demographics["STNAME"].str.upper()
    demographics = demographics.drop(columns=['STNAME'])
    elections_2000 = elections[elections['year'] == 2000]
    elections_2004 = elections[elections['year'] == 2004]
    elections_2000['winner'] = elections_2000.groupby('state')['candidatevotes'].transform(max) == elections_2000['candidatevotes']
    elections_2004['winner'] = elections_2004.groupby('state')['candidatevotes'].transform(max) == elections_2004['candidatevotes']
    elections_2000_winners = elections_2000[elections_2000['winner']][['state', 'party_detailed']]
    elections_2004_winners = elections_2004[elections_2004['winner']][['state', 'party_detailed']]
    
    #getting the specific demographics
    demographics['percent_female'] = demographics['TOT_FEMALE'] / demographics['TOT_POP'] * 100
    demographics['percent_male'] = demographics['TOT_MALE'] / demographics['TOT_POP'] * 100
    demographics['percent_black'] = demographics['Black'] / demographics['TOT_POP'] * 100
    demographics['percent_white'] = (demographics['WA_MALE'] + demographics['WA_FEMALE']) / demographics['TOT_POP'] * 100
    demographics['percent_hispanic'] = demographics['Hispanic'] / demographics['TOT_POP'] * 100
    d_features = demographics[['state', 'percent_male', 'percent_female', 'percent_white', 'percent_black', 'percent_hispanic']]
    
    #merging the data
    merged_2000 = pd.merge(elections_2000_winners, d_features, on='state')
    merged_2004 = pd.merge(elections_2004_winners, d_features, on='state')
    merged_2000 = merged_2000.sort_values(by='state')
    merged_2004 = merged_2004.sort_values(by='state')

    label_encoder = LabelEncoder()
    merged_2000['party_encoded'] = label_encoder.fit_transform(merged_2000['party_detailed'])
    
    X_2000 = merged_2000[['percent_male', 'percent_female', 'percent_white', 'percent_black', 'percent_hispanic']]
    y_2000 = merged_2000['party_encoded']
    
    merged_2004['party_encoded'] = label_encoder.transform(merged_2004['party_detailed'])
    
    X_2004 = merged_2004[['percent_male', 'percent_female', 'percent_white', 'percent_black', 'percent_hispanic']]
    y_2004 = merged_2004['party_encoded']
    
    k_recall = None
    k_precision = None
    recall_highest = 0
    recall_lowest = np.inf
    precision_highest = 0
    precision_lowest = np.inf
    
    recall_scores = []
    precision_scores = []
    
    for k in range(4, 11):
        knn = KNeighborsClassifier(n_neighbors=k)
        cv_results = cross_validate(knn, X_2000, y_2000, cv=KFold(n_splits=5, random_state=0, shuffle=True), scoring=['recall_macro', 'precision_macro'])
    
        recall = np.mean(cv_results['test_recall_macro'])
        precision = np.mean(cv_results['test_precision_macro'])
    
        recall_scores.append(recall)
        precision_scores.append(precision)

        #calculating lowest mean recall
        if recall > recall_highest:
            recall_highest = recall
            k_recall = k
        if recall < recall_lowest:
            recall_lowest = recall

        #calcuating highest mean precision
        if precision > precision_highest:
            precision_highest = precision
            k_precision = k
        if precision < precision_lowest:
            precision_lowest = precision
    
    print(f"The optimal k value for recall is {k_recall} and the lowest mean recall is {recall_lowest}")
    print(f"The optimal k value for precision is {k_precision} and the highest mean precision is {precision_highest}")
    
    X_train, X_test, y_train, y_test = train_test_split(X_2004, y_2004, random_state=0)
    
    #optimal K value
    k = 5
    
    knn = KNeighborsClassifier(n_neighbors=k)
    knn.fit(X_train, y_train)
    
    y_pred = knn.predict(X_test)
    
    #predicted f1 score for Republican
    f1 = metrics.f1_score(y_test, y_pred, pos_label=2)
    print("F1 Score for Republican label:", f1)
    predicted_republican = (y_pred == 1).sum()
    print("Number of states predicted to vote Republican:", predicted_republican)
    
    #ohio predicted vote
    ohio_pred = knn.predict(X_test)
    ohio = ohio_pred.sum()
    votes = False
    if ohio >= 1:
        votes = True
    print("Ohio's predicted vote:", votes)
    
    #1st plot for confusion matrix heatmap
    conf_matrix = metrics.confusion_matrix(y_test, y_pred)
    sns.heatmap(conf_matrix, annot=True, fmt='d', cmap='magma')
    plt.xlabel('Predicted Label')
    plt.ylabel('True Label')
    plt.title('Confusion Matrix Heatmap')
    plt.show()
    
    k_vals = range(4, 11)
    #2nd plot for precision and recall vs K vals
    plt.figure(figsize=(8, 6))
    plt.plot(k_vals, recall_scores, marker='o', linestyle='-', color='blue', label='recall')
    plt.plot(k_vals, precision_scores, marker='o', linestyle='-', color='red', label='precision')
    plt.xlabel('K Val')
    plt.ylabel('Score')
    plt.title('Precision and Recall vs. K Values')
    plt.legend()
    plt.show()
if __name__ == "__main__":
    main()