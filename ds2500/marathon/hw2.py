#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Feb  4 21:38:40 2024

@author: tjkalapatapu
"""
import seaborn as sns
import matplotlib.pyplot as plt
from utils import read_csv, lst_to_dct, median, normalize
import os
from scipy import stats
import statistics

FILENAME_2013 = "/Users/tjkalapatapu/Desktop/ds2500/marathon/marathon_data/baa_results_2013.csv"
FILENAME_2010 = "/Users/tjkalapatapu/Desktop/ds2500/marathon/marathon_data/baa_results_2010.csv"
FILENAME_2023 = "/Users/tjkalapatapu/Desktop/ds2500/marathon/marathon_data/boston_marathon_2023.csv"
FILENAME_2021 = "/Users/tjkalapatapu/Desktop/ds2500/marathon/marathon_data/boston_marathon_2021.csv"
BIB_HEADER = "BibNumber"
AGE_HEADER = "AgeOnRaceDay"
RANK_HEADER = "RankOverall"
GENDER_HEADER = "Gender"
TIME_HEADER = "OfficialTime"
NAME_HEADER = "FullName"
COUNTRY_HEADER = "CountryOfResAbbrev"
DIR = "marathon_data"

#skips headers
start = 1

def convert_time(lst):
    '''given a list of time strings in the format HH:MM:SS, returns the total seconds.'''
    seconds = []
    for time in lst:
        if ':' in time:
            h, m, s = map(int, time.split(":"))
            total_seconds = h * 3600 + m * 60 + s
            seconds.append(total_seconds)
    return seconds

def normalized_format(seconds):
    '''given the seconds, returns the HH:MM:SS format.'''
    h = seconds // 3600
    m = (seconds % 3600) // 60
    s = seconds % 60
    return f"{int(h):02d}:{int(m):02d}:{int(s):02d}"

def country_counter(lst):
    '''given a list, returns the country with the most runners besides USA.'''
    counter = {}
    for row in lst[start:]:  
        country = row[lst[0].index("CountryOfResAbbrev")]
        if country != 'USA':  
            if country in counter:
                counter[country] += 1
            else:
                counter[country] = 1
    second_most = max(counter, key=counter.get)
    return second_most

def women_counter(dct):
    '''given a dictionary, returns the number of woman participated in the race'''
    genders = dct[GENDER_HEADER]
    counter = 0
    for gender in genders:
        if gender == "F":
            counter +=1
    return counter 
        
def get_filenames(dirname, ext = ".csv"):
    ''' given a directory name(string), return the full path and name for every
    non-directory file in the directory (list of strings)'''
    filenames = []
    files = os.listdir(dirname)
    for file in files:
        if not os.path.isdir(file) and file.endswith(ext):
            filenames.append(dirname + "/" + file)
    return filenames

def total_mean(dct, header, val):
    ''' given a dictonary, header, and value, returns mean finish times for
    every year'''
    time = []
    for year in dct:
        lst = []
        main = dct[year]
        header_info = main[header]
        time_dct = main[TIME_HEADER]
        for count, info in enumerate(header_info):
            if info == val:
                lst.append(time_dct[count])
        mean = sum(convert_time(lst)) / len(convert_time(lst))
        time.append(mean)
    return time

def linear_reg_plot(xlst, ylst):
    ''' given 2 lists, returns a linear regression plot'''
    plt.title("Year vs. Mean Finish Time of the Top 1000 American Runners")
    plt.xlabel("Year")
    plt.ylabel("Avg Finish Time (in min)")
    y_min = [(sec/60) for sec in ylst]
    sns.regplot(x = xlst, y = y_min, line_kws={"color":"blue"})
    plt.show()

def plots(xlst, ylst, label_lst):
    ''' given a list for x and y values along with another list with labels,
    return plots for x vs y'''
    for i in range(len(ylst)):
        sns.lineplot(x = xlst, y = ylst[i], label = label_lst[i])
        plt.title("Median Age and Average Finish Times Over the Years")
        plt.xlabel("Year")
        plt.ylabel("Ages/Times")
        plt.show()

def main():    
    #dictionary for all the years
    total_dct = {}
    #Each dataset converted into a list
    lst2013 = read_csv(FILENAME_2013)
    lst2010 = read_csv(FILENAME_2010)
    lst2023 = read_csv(FILENAME_2023)
    lst2021 = read_csv(FILENAME_2021)
        
    #In 2013, what was the mean finish time of the top 1000 runners?
    time_lst = [row[lst2013[0].index(TIME_HEADER)] for row in lst2013[start:]] 
    time_in_seconds = convert_time(time_lst)
    mean_finishTime = sum(time_in_seconds) / len(time_in_seconds)
    normalFormat = normalized_format(mean_finishTime)
    print(f"The mean finish time of the top 1000 runners in 2013 is {normalFormat} hours.")
    
    #What is the median age of the top 1000 runners in 2010?
    dct2010 = lst_to_dct(lst2010)
    ages = dct2010[AGE_HEADER]
    for i in range (len(ages)):
        ages[i] = int(ages[i])
    med = median(ages)
    print(f"The median age of the top 1000 runnners in 2010 is {med}.")
    
    #Apart from the US, which country had the most runners in 2023?
    second_place = country_counter(lst2023)
    print(f"Apart from the US, the country that had the most runners in 2023 is {second_place}.")
    
    #How many women finished in the top 1000 in 2021?
    dct2021 = lst_to_dct(lst2021)
    women = women_counter(dct2021)
    print(f"{women} women finished in the top 1000 in 2021.")

    #get all years of data and store it in a dictionary
    filenames = get_filenames(DIR)    
    for filename in filenames:
        lst = read_csv(filename)
        dct = lst_to_dct(lst)
        finder = filename.find("20")
        filename = filename[finder : finder+4]
        total_dct[filename] = dct

    #What is the correlation (r-value) of year vs. the mean finish time of women in the top 1000?
    years = [int(year) for year in total_dct.keys()]
    year_time_corr = statistics.correlation(total_mean(total_dct, GENDER_HEADER, "F"), years)
    print(f"The correlation of the year vs. the mean finish time of women in the top 100 is {year_time_corr}")
    
    #What is the correlation (r-value) of year vs. the mean finish time of American runners in the top 1000?
    usa_mean = total_mean(total_dct, COUNTRY_HEADER, "USA")
    usa_year_time_corr = statistics.correlation(usa_mean, years)
    print(f"The correlation of the year vs. the mean finish time of American runnners in the top 100 is {usa_year_time_corr}")
    
    #If the 2020 race had actually happened, what would you predict to be the mean finish time of Americans in the top 1000?
    usa_lin_reg = stats.linregress(years, total_mean(total_dct, COUNTRY_HEADER, "USA"))
    usaslope = usa_lin_reg.slope
    usaintercept = usa_lin_reg.intercept
    y_predicted = usaslope * 2020 + usaintercept
    print(f"If the 2020 race had actually happened, I would predict the mean finish time pf Americans in the top 1000 to be {normalized_format(y_predicted)}.")
    
    #Plot #1: A linear regression plot  modeling the relationship between year and mean finish times of American runners in the top 1000.
    linear_reg_plot(years, usa_mean)

    #Plot #2: A plot showing how median age and average finish times have changed over time.
    sorted_yrs = sorted(int(key) for key in total_dct.keys())
    median_ages = []
    times = []
    for yr in sorted_yrs:
        yr = str(yr)
        ages = [int(age) for age in total_dct[yr][AGE_HEADER]]
        median_ages.append(median(ages))
        times.append(sum(convert_time(total_dct[yr][TIME_HEADER])) / len(convert_time(total_dct[yr][TIME_HEADER])))
    normalized_ages = normalize(median_ages)
    normalized_times = normalize(times)
    plots(sorted_yrs, [normalized_ages, normalized_times], ["Median Ages", "Mean Finish Time (HH:MM:SS)"])
        
if __name__ == "__main__":
    main()