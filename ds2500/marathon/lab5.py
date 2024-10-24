#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Mar 11 15:10:22 2024

@author: tjkalapatapu
"""
import requests
from bs4 import BeautifulSoup

#question 1
def construct_links(url):
    response = requests.get(url)
    soup = BeautifulSoup(response.text, 'html.parser')
    links = []
    for link in soup.find_all('a'):
        href = link.get('href')
        label = link.text.strip()
        if href:
            links.append((href, label))
    return links

#question 2
def count_missing_alt(url):
    response = requests.get(url)
    soup = BeautifulSoup(response.text, 'html.parser')
    imgs = soup.find_all('img')
    if not imgs:
        return 0
    missing_alt = sum(1 for img in imgs if 'alt' not in img.attrs)
    return missing_alt / len(imgs)

#question 4
def get_weather_json(lat, lon, api):
    url = f"http://api.openweathermap.org/data/2.5/weather?lat={lat}&lon={lon}&appid={api}&units=imperial"
    response = requests.get(url)
    return response.json()