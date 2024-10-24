#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Jan 24 21:19:43 2024

@author: tjkalapatapu
"""

import csv
import matplotlib.pyplot as plt

FILENAME = "num_borrowers_per_state.csv"
FILENAME_2 = "total_loans_per_state.csv"


def read_file(filename):
    ''' given the name of a csv file (string), read in the contents and return as a 2d list of strings'''
    data = []
    with open(filename, "r") as infile:
        csvfile = csv.reader(infile)
        for row in csvfile:
            data.append(row)
    return data

def main():
    lst = read_file(FILENAME)
    lst = read_file(FILENAME_2)
    #How many borrowers had student loans in 2019?
    



if __name__ == "__main__":
    main()

