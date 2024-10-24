#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jan 22 15:32:29 2024

#lab 1

@author: tjkalapatapu
"""
#question 1
def lst_to_dct(lst):
    dct = {}
    for row in lst:
        dct[row[0]] = row[1:]
    return dct

#question 2
def col_to_lst(lst, index):
    newlst = []
    for i in range(0, len(lst)):
        newlst.append(lst[i][index])
    return newlst

#question 3
def sum_cols(lst):
    newlst = lst[0]
    print(newlst)
    for i in range(1, len(lst)):
        numCol = len(lst[i])
        for j in range(0, numCol):
            newlst[j] = newlst[j] + lst[i][j] 
    return newlst