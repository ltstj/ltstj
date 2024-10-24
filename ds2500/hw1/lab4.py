#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Feb 12 15:33:00 2024

@author: tjkalapatapu
"""
import statistics

#question 1
def normalize(lst):
    min_val = min(lst)
    max_val = max(lst)
    if max_val == min_val:
        return [0 for i in lst]
    normalized = [(val - min_val) / (max_val - min_val) for val in lst]
    return normalized

#Question 2
def z_score(lst):
    mean = statistics.mean(lst)
    std_dev = statistics.stdev(lst)
    if std_dev == 0:  
        return [0 for i in lst]
    z_score = [(x - mean) / std_dev for x in lst]
    return z_score

#Question 3
def hamming(str1, str2):
    return sum(letter1 != letter2 for letter1, letter2 in zip(str1, str2))