#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Jan 23 11:13:56 2024

@author: tjkalapatapu
"""

def filter_line(str, lst, newlst):
    filtered = [value for line, value in zip(lst, newlst) if str.lower() in line.lower()]
    return filtered