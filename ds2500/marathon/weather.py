#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Mar  1 10:40:46 2024
    DS2500
    Spring 2024
    JSON data, 2 ways:
        1. read in xxx.json, print out upcoming temps
        2. call API function, print out upcoming temps
@author: tjkalapatapu
"""

import json
import requests

FILENAME = "/Users/tjkalapatapu/Desktop/ds2500/marathon/forecast.json"
API_KEY = "459291d7a88e45e535150f4ede9bffad"
URL = "https://api.openweathermap.org/data/2.5/forecast"

def main():
    #Part one - read in JSON data from a file
    #with open(FILENAME, "r") as jfile:
        #data = json.load(jfile)
        
    #what are the upcoming temps?
    #for d in data["list"]:
      #  print(d["main"]["temp"])
       # print(d["weather"][0]["description"])

    #how can we specify the location?
    #paramaters = lat, lon
    #how an we make the temps in farenheit?
    #paramater: units (imperial)
    lat = float(input("What latitude?: "))
    lon = float(input("What longitude?: "))
    
    #get the weather in that location
    params = {"lat": lat,
              "lon": lon,
              "appid": API_KEY,
              "units": "imperial"}
    response = requests.get(URL, params = params)
    data = response.json()

    #what are the upcoming temps in a location   
    for d in data["list"][:10]:
        print(d["main"]["temp"])
        print(d["weather"][0]["description"])
        
if __name__ == "__main__":
    main()