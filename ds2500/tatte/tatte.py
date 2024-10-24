#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Apr  2 10:48:23 2024
@author: tjkalapatapu
DS2500

Sample code from lecture -- Tatte class
    Attributes:
        - Size of store
        - hours of operation
        - proximiity to other tattes
        - proxmimity to competitors
        - number of employees
        - median income in neighborhood
        - foot traffic
        - cost of real estate
        - daily sales
        - price list
    
    Methods:
        - compute number of employees
        - compute prices to charge
        - how long till we break even/ make $?
"""
import random

LOW_MEDIAN = 45000
HIGH_MEDIAN = 100000

class Tatte:
    def __init__(self, sqft, median, lease_amount):
        self.sqft = sqft = sqft
        self.median_income = median
        self.lease_amount = lease_amount

    def generate_prices(self, menu, base_price):
        self.prices = {menu: [base_price, base_price + 1, base_price + 2]}
        if self.median_income < LOW_MEDIAN:
            self.prices[menu] = [item - 0.5 for item in self.prices[menu]]
        elif self.median_income > HIGH_MEDIAN:
            self.prices[menu] = [item + 0.5 for item in self.prices[menu]]
    
    def daily_sales(self, num_ppl):
        #assume every person who comes in buys one thing
        #randomly choose which item they buy, and which size
        return num_ppl * self.prices["coffee"][0] 