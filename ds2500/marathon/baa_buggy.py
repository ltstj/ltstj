'''
    DS2500
    Spring 2024

    Python week! This week we'er focusing on some python skills including:
        * creating/writing files
        * using the os library to navigate your directory structure
        * plotting with seaborn on top of matplotlib
        * dictionaries deep-dive
        * overview of other data structures (tuples, sets)
        * deep vs shallow copies

'''

import csv
import os
import seaborn as sns
import matplotlib.pyplot as plt

from utils import read_csv, lst_to_dct, median

FILENAME = "files/boston_marathon_2022.csv"
BIB_HEADER = "BibNumber"
AGE_HEADER = "AgeOnRaceDay"
RANK_HEADER = "RankOverall"
GENDER_HEADER = "Gender"
TIME_HEADER = "OfficialTime"
DIR = "files"
NAME_HEADER = "FullName"

def filter_age(target_age, ages, times):
    ''' given a target age, a list of ages, and a list of times,
        filter and return a list of times for runners who are the given
        age OR OLDER
    '''
    filtered_times = []
    for i in range(len(ages)):
        if ages[i] >= target_age:
            filtered_times.append(times[i])
    return filtered_times

def get_filenames(dirname, ext = ".csv"):
    ''' given a directory name(string), return the full path and name for every
    non-directory file in the directory (list of strings)'''
    filenames = []
    files = os.listdir(dirname)
    for file in files:
        if not os.path.isdir(file) and file.endswith(ext):
            filenames.append(dirname + "/" + file)
    return filenames            

def main():
    # Gather data - read in the MBTA speed restrictions as a 2d list
    # and then convert to a dictionary where keys come from the header
    data = read_csv(FILENAME)
    dct = lst_to_dct(data)
    print(dct)
    
    # pull out a list of ages
    ages = dct[AGE_HEADER]
    for i in range (len(ages)):
        ages[i] = int(ages[i])
    #print(f"Ages of runners in 2022: {ages}")
    
    #iterate by value:
    #for age in ages:
        #print(f"Someone is {age} years old.")
    
    #What is the median age of runners in top 1000
    med = median(ages)
    mean = sum(ages) / len(ages)
    #print(f"Median Age: {med}, Mean Age: {round(mean,3)}")
    
    # filter to keep everyone older than me
    master_times = filter_age(45, ages, dct[TIME_HEADER])
    #print(f"Times of everyone 45 or older: {master_times}")
    
    
    #what if we want all data from multiple files without having to know its name
    filenames = get_filenames(DIR)
    print(filenames)
    
    #all names over all years
    names = []
    for filename in filenames:
        print(f"reading {filename}")
        lst = read_csv(filename)
        dct = lst_to_dct(lst)
        names += dct[NAME_HEADER]
    print(f"{len(names)} finishers over 2 years")
    print(f"{len(set(names))} individuals over 2 years")
        

if __name__ == "__main__":
    main()
