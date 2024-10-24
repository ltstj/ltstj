#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Feb  9 11:00:32 2024

@author: tjkalapatapu
"""

'''
    DS2500
    Spring 2024
    Week 5 - code from class
    
    Data for this week:
        * Info about northeastern over the last several years
        * For 2013-2021, we have: Selectiveness Rating, Admission Rate,
            % of admitted students w/identity markers, tuition
    
    Starter code for Friday:
        * Right where we left off from Tuesday...
        * We read in and cleaned up the data we needed
        * And then plotted tuition vs admission rate
        * it looked skewed, so we normalized the data and tried again
        * normalize function is moved into utils.py
        
    
    During the lecture on Friday, we'll cover
        * Meaningful distances
        * Variance and std deviation
    
    And then we'll code that stuff into this starter code, as well as the
    PPP which is about moving average.
        
'''

import csv
import matplotlib.pyplot as plt
import seaborn as sns
import statistics
import sys

# just for funsies, not required, but this way
# you don't need to copy/paste or rewrite your
# utils.py file and it can always live in the same place
# customize this path to fit your own file structure :)
sys.path.insert(0, "../utils")
from utils import get_filenames, read_csv, lst_to_dct, normalize

DIRECTORY = "data"
YEAR_HEADER = "Year"
TUITION_HEADER = "Living On Campus"
ADM_HEADER = "Admission Rate (Total)"

                       
def clean_numeric(s):
    ''' given a string with extra characters $ or , or %, remove them
        and return the value as a float
    '''
    s = s.replace("$", "")
    s = s.replace("%", "")
    s = s.replace(",", "")
    return float(s)

    
def clean_data(dct):
    ''' given a dictionary that includes currency and
        numbers in the form x,xxx, clean them up and convert
        to int/float
    '''
    for key, value in dct.items():
        for i in range(len(value)):
            if not value[i].replace(" ", "").isalpha():
                value[i] = clean_numeric(value[i])

def plot_lines(x, ys, labels):
    ''' given a list of x values, a 2d list of y values, and a
        corresponding list of labels (strings)
        plot all the ys against the same list of x's
    '''
    for i in range(len(ys)):
        sns.lineplot(x = x, y = ys[i], label = labels[i])
    plt.show()
    
def moving_avg(lst, win = 2):
    ''' given a list of numbers and a window '''
    mvg_avg = []
    for i in range(win-1, len(lst)):
        num = 0
        for j in range(win):
            num += lst[i-j]
        mvg_avg.append(num/win)

def main():
    # gather data - gernate a list of files and read in each one
    filenames = get_filenames(DIRECTORY)
    all_dct = {}
    for file in filenames:
        data = read_csv(file)
        if "demographics" in file:
            demo_header = data[0][1:]
        dct = lst_to_dct(data)
        all_dct = {**all_dct, **dct}
    
    print(demo_header)
    
    # clean up the data
    clean_data(all_dct)
    
    # Plot tuition vs admission rate... but oh no, they look wrong :(
    # because data is on different scales
    plot_lines(all_dct[YEAR_HEADER], [all_dct[TUITION_HEADER], 
                                      all_dct[ADM_HEADER]],
               ["Tuition", "Admission Rate"])
    
    # normalize tuition/admission values, and try again
    normal_tuition = normalize(all_dct[TUITION_HEADER])
    normal_adm = normalize(all_dct[ADM_HEADER])
    plot_lines(all_dct[YEAR_HEADER], [normal_tuition, normal_adm],
               ["Tuition", "Admission Rate"])

    #demographic info?
    print(demo_header)
    for demo in demo_header:
        sns.lineplot(data = all_dct, x = YEAR_HEADER, y = demo)
        mvg = moving_avg(all_dct[demo])
        sns.lineplot(x = all_dct[YEAR_HEADER][1:], y = mvg, color = "magenta")
        plt.title(demo)
        plt.show()

        #what is the mean of the demographic info?
        mean = sum(all_dct[demo]) / len(all_dct[demo])
        print(f"Mean of {demo}: {mean}")
        stddev = statistics.stdev(all_dct[demo])
        print(f"STD dev: {stddev}\n")

if __name__ == "__main__":
    main()

