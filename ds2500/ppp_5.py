#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Mar 14 18:21:37 2024

@author: tjkalapatapu
"""
def find_majority_class(classes, tuples_list):
    class_counter = {name: 0 for name in classes}
    for tupl in tuples_list:
        for element in tupl:
            if element in classes:
                class_counter[element] += 1
                break
    highest_class = max(class_counter, key=class_counter.get)
    return highest_class