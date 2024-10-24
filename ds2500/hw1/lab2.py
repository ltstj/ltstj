#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jan 29 14:47:01 2024

@author: tjkalapatapu
"""

import statistics
import csv

MBTA_FILE = "speed_restrictions.csv"
SPEED_HEADER = "Restriction_Speed_MPH"
DISTANCE_HEADER = "Restriction_Distance_Feet"
LINE_HEADER = "Line"
PRI_HEADER = "Priority"
PRI_NAMES = ["LOW", "MED", "HIGH"]
LINE_NAMES = ["Green", "Red", "Orange", "Blue"]

def read_csv(filename):
    ''' given the name of a csv file, return its contents as a 2d list,
        including the header.'''
    data = []
    with open(filename, "r") as infile:
        csvfile = csv.reader(infile)
        for row in csvfile:
            data.append(row)
    return data

def lst_to_dct(lst):
    ''' given a 2d list, create and return a dictionary where header '''
    dct = {}
    for row in lst:
        dct[row[0]] = row[1:]
    return dct

def filter_line(str, lst, newlst):
    filtered = [value for line, value in zip(lst, newlst) if str.lower() in line.lower()]
    return filtered
    
def main():
    data = read_csv(MBTA_FILE)
    
    #Question 1: What is the median restricted speed on the orange line?
    

if __name__ == "__main__":
    main()