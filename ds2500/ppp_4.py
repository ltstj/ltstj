#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Feb 20 11:58:14 2024

@author: tjkalapatapu
"""
def mse(predicted, actual):
    errors_squared = [(p - a) ** 2 for p, a in zip(predicted, actual)]
    return sum(errors_squared) / len(errors_squared)