#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Jan 16 11:20:42 2024

DS 2500
Spring 2024

Write the following function:
    - name: sum_column
    - parameter: 2d list of anything, int for column number - optional 
      If no column number is given, use 0
      (data type in that column must be numeric)
    - returns: sum of all values in the given column

@author: tjkalapatapu
"""

def sum_column(lst, index=0):
    sum = 0
    for i in range(0, len(lst)):
        sum += lst[i][index]
    return sum

