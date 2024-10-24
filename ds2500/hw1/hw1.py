#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Jan 24 21:19:43 2024

@author: tjkalapatapu
"""
#proper packages needed
import csv
import matplotlib.pyplot as plt

#the datasets
BORROWERS = "num_borrowers_per_state.csv"
LOANS = "total_loans_per_state.csv"

#var to skip the unnecessary headers 
start = 6


def read_file(filename):
    ''' given the name of a csv file (string), read in the contents and return as a 2d list of strings'''
    data = []
    with open(filename, "r") as infile:
        csvfile = csv.reader(infile)
        for row in csvfile:
            data.append(row)
    return data

def total_sum(lst, col = 0):
    '''given a list and column number adds up all the values of that column adn returns it as an int'''
    total = 0
    for row in lst:
        if row and row[0] != 'state/area':  
            num = row[col]
            if num:
                total += int(num)
    return total

def clean_number(s):
    ''' given a string, remove, and $ and return the float version of the string '''
    s = s.replace(",", "")
    s = s.replace("$", "")
    return float(s)

def clean_data(lst):
    ''' given a 2d list of strings, convert row[1] and row[2]
    to float and return a cleaned-up version of the list'''
    cleaned = []
    for row in lst:
        for i in range(1, len(row)):
            row[i] = clean_number(row[i])
        cleaned.append(row)
    return cleaned

def lst_to_dct(lst):
    '''given a list, converts it into a dictionary and returns it'''
    dct = {}
    for row in lst:
        dct[row[0]] = row[1:]
    return dct

def greatest_lowest(dct, num):
    '''given a dictionary and either max or min, it will return either the greatest number or the least number'''
    lst_avg = []
    for key, value in dct.items():
        avg = (sum(value) / (len(value)))
        lst_avg.append(avg)
    greatest_or_lowest = num(lst_avg)
    indx = lst_avg.index(greatest_or_lowest)
    return (list(dct.keys())[indx], greatest_or_lowest)

def avg_change(lst, state):
    ''' given the borrowers and state, will return the average change between 1 year'''
    avg_change = 0
    count = 0
    for row in lst:
        if row[0].lower() == state.lower():
            for i in range(2, len(row)):
                diff = abs(row[i] - row[i-1])
                avg_change += diff
                count +=1 
    if count > 0:
        avg_change /= count
    return avg_change
        
def avg_hist(b_lst, l_lst, col):
    '''given the borrowers, loans, and column number (year) to return a histogram'''
    borrowers = [row[col] for row in b_lst]
    loans = [row[col] for row in l_lst]
    avg = [loans[i] / borrowers[i] for i in range(len(borrowers))]
    metric = " $ millions"
    plt.hist(avg, color = "green")
    plt.xlabel(f"Outstanding Balance ({metric})")
    plt.ylabel("Number of States")
    plt.title("Outstanding Student Loan Balance in 2021")
    plt.show()
    
def line_comparison(state1, state2, loan_dct, borrower_dct):
    '''given 2 states and the loan + borrower, will create a line plot comaparing the 2'''
    loans_lst = loan_dct[state1]
    borrower_lst = borrower_dct[state1]
    loans_lst2 = loan_dct[state2]
    borrower_lst2 = borrower_dct[state2]
    avg_lst = [loans_lst[i] / borrower_lst[i] for i in range(len(borrower_lst))]
    avg_lst2 = [loans_lst2[i] / borrower_lst2[i] for i in range(len(borrower_lst))]
    plt.plot(avg_lst, color = "red")
    plt.plot(avg_lst2, color = "blue")
    plt.xlabel("Year")
    plt.ylabel("Average Outstanding Balance")
    plt.title(f"Outstanding Student Loan Balance in 2021: {state1} and {state2}")
    plt.show()    


def main():
    lst = read_file(BORROWERS)
    lst2 = read_file(LOANS)
    
    #How many borrowers had student loans in 2019?
    clean_lst = clean_data(lst[start:])
    sum_borrowers_2019 = total_sum(clean_lst, 4)
    print(f"The total sum of borrowers in 2019 was {sum_borrowers_2019}.")
    
    #What is the total outstanding balance for all students as of 2021?
    clean_lst2 = clean_data(lst2[start:])
    sum_loans_2021 = total_sum(clean_lst2, 7)
    print(f"The total sum of loans in 2021 was {sum_loans_2021} (in millions).")
    
    #What is the average outstanding balance per student in 2016?
    sum_borrowers_2016 = total_sum(clean_lst, 1)
    sum_loans_2016 = total_sum(clean_lst2, 1)
    avg_2016 = (sum_loans_2016) / sum_borrowers_2016
    print(f"The average outstanding balance per student in 2016 is {avg_2016}")

    #What is Nevada’s average outstanding balance over all years in the dataset?
    state = input("Pick a state: ")
    lst2_dct = lst_to_dct(clean_lst2)
    sum_state = sum(lst2_dct[state])/7 
    print(f"The average outstanding balance over all years in {state} is {sum_state} (in millions).")

    #Which state had the greatest balance on average over all years in the dataset, and how much was it?
    print(f"The state that had the greatest average balance over all years was {greatest_lowest(lst2_dct, max)}")
    
    #Which state had the lowest balance on average over all years in the dataset, and how much was it?
    print(f"The state that had the lowest average balance over all years was {greatest_lowest(lst2_dct, min)}")

    #On average, how much did the number of borrowers in a given state change per year? 
    #(Assume that, in the first year, the number of borrowers did not change. 
    #Compute your first value as the change from 2016 to 2017. 
    #Negatives/positives don’t matter here. Going from 10 borrowers to 11, or from 10 to 9, is a change of 1 person.)
    state = input("Enter a State: ")
    print(f"The number of borrowers per year changed by an average of {round(avg_change(clean_lst, state))} people in {state}.")
    
    #plot 1
    avg_hist(clean_lst, clean_lst2, 2)
    
    #plot 2
    newLst = lst_to_dct(lst)
    line_comparison("Nevada", "California", lst2_dct, newLst)

if __name__ == "__main__":
    main()

