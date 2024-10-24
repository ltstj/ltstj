
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Apr  2 10:56:48 2024

@author: tjkalapatapu
"""
from tatte import Tatte
import random

def main():
    #create a Tatte object
    tatte_hunt = Tatte("small", 106000, 5000)
    tatte_fenway = Tatte("medium", 39000, 7500)
    tatte_dot = Tatte("extra small", 65000, 3000)
    
    #generate coffee prices for all locations
    tatte_hunt.generate_prices("coffee", 2.50)
    tatte_fenway.generate_prices("coffee", 2.50)
    tatte_dot.generate_prices("coffee", 2.50)
    
    #how much do we make in daily sales at our locations?
    hunt_sales = tatte_hunt.daily_sales(random.randint(500,1000))
    print(f"Huntington sales: ${hunt_sales}")
    
    fenway_sales = tatte_fenway.daily_sales(random.randint(300,3000))
    print(f"Fenway sales: ${fenway_sales}")
    
    dot_sales = tatte_dot.daily_sales(random.randint(500,1000))
    print(f"Dot sales: ${dot_sales}")
    
if __name__ == "__main__":
    main()