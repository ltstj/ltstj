#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Feb  6 12:16:51 2024

@author: tjkalapatapu
"""
def moving_avg(lst, num=2):
    avglst = []
    for i in range(len(lst) - num + 1):
        values = lst[i:i + num]
        avg = sum(values) / num
        avglst.append(avg)
    return avglst