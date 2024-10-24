#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Feb  5 14:18:21 2024

@author: tjkalapatapu
"""

#Question 1
def sum_distinct(lst):
    newlst = []
    for item in lst:
        totalSum = sum(set(item))
        newlst.append(totalSum)
    lst.clear()
    lst.extend(newlst)

#Question 3 
def combine_dcts(lst):
    newDct = {}
    for sublist in lst:
        headers = sublist[0]
        for i, header in enumerate(headers):
            if header in newDct and sublist is not lst[0]:
               newDct[header] = [row[i] for row in sublist[1:]]
            elif header not in newDct:
                newDct[header] = [row[i] for row in sublist[1:]]
            else:
                newDct[header].extend([row[i] for row in lst[1:]])
    return newDct

#Question 4
def clean_means(tupl):
    newlst = []
    for row in tupl:
        count = 0
        sums = 0
        for value in row:
            if value != "":
                sums += float(value)
                count += 1
        if count != 0:
            mean = sums / count
            newlst.append(mean)
    return newlst
