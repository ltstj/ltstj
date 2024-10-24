#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Jan 16 10:25:38 2024
DS 2500
Spring 2024
Code from class -- student loan data from one month

Questions to ask/answer:
    - avg amount owed per person, overall
    - avg amount ower per person, in a given state
    - state with min/max # borrowers
    - state with min/max total balance
    - avg # borrowers over all states
    - avg balance over all state
    - correlation between num borrowers and balance
    
Functions sketch:
    - read file
    - iterate over the dataset
    - clean (string ==> floats)
    - min/max function
    - total function. separately compute avg
    
@author: tjkalapatapu
"""

import csv
import matplotlib.pyplot as plt

FILENAME = "2016_balances_borrowers.csv"

def read_file(filename):
    ''' given the name of a csv file (string), read in the contents and return as a 2d list of strings'''
    data = []
    with open(filename, "r") as infile:
        csvfile = csv.reader(infile)
        for row in csvfile:
            data.append(row)
    return data

def clean_number(s):
    ''' given a string, remove, and $ and return the float version of the string '''
    s = s.replace(",", "")
    s = s.replace("$", "")
    return float(s)

def clean_data(lst):
    '''given a 2d list of strings, convert to number where appropriate and return a new 2d list'''
    cleaned = []
    for row in lst:
        row[1] = clean_number(row[1])
        row[2] = clean_number(row[2])
        cleaned.append(row)
ˇ    return cleaned

def clean_lst(lst):
    ''' given a 2d list of strings, convert row[1] and row[2]
    to float and return a cleaned-up version of the list'''
    cleaned = []
    for row in lst:
        for i in range(1, len(row)):
            row[i] = convert_string(row[i])
        cleaned.append(row)
    return cleaned

def sum_column(lst, index=0):
    sum = 0
    for i in range(0, len(lst)):
        sum += lst[i][index]
    return sum

def twod_to_dict(lst):
    ''' given a 2d list, create and return a dictionary where key = row[0]
    and value = row[1:] for every row in 2d list'''
    dct = {}
    for row in lst:
        dct[row[0]] = row[1:]
    return dct

def plot_comparison(val1, state1, val2, state2):
    ''' create a bar plot that compares the values of 2 states'''
    plt.bar([0,1], [val1, val2])
    plt.xlabel("States")
    plt.ylabel("Total Outstanding Balance ($ million)")
    plt.title(f"{state1} vs {state2} outstanding student loan balance, 2016")
    plt.xticks([0,1], [state1, state2])

def main():
    #step 1: read file into a 2d list of strings
    lst = read_file(FILENAME)
    #cleans the data and prints it    
    cleaned = clean_data(lst[6:])
    #create a dictionary version of the 2d lisst
    data_dct = twod_to_dict(cleaned)   
    #print(data_dct)
    #how many total borrowers across all states?
    total_borrowers = sum_column(cleaned, 1)
    print(f"{round(total_borrowers)} people have student loans in US in 2016")
    #user inputs state for that states total borrowers
    state1 = input("which state?: ")
    state2 = input("Compared to which other state?: ")
    
    plot_comparison(data_dct[state1][1], state1,
                    data_dct[state2][1], state2)

    #state = input("which state?: ")
    #print(f"{state} has {round(data_dct[state][0])} borrowers")
    #avg_per_borrower = data_dct[state][1] / data_dct[state][0]
    #print(f"{state} has an average balance per borrower of ${avg_per_borrower}")


if __name__ == "__main__":
    main()


#import pandas as pd
#df1 = pd.read_csv("/Users/tjkalapatapu/Desktop/ds2500/2016_balances_borrowers.csv")
#df1.drop(index = df1.index[0:4], axis = 0, inplace= True)
#df1.replace("$", " ")
#df1.replace(",", " ")
#print(df1)