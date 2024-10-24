'''
    DS2500
    Spring 2024
    
    Starter code for working with the MBTA data -- speed restrctions
    
    We have for starter code:
        * constants for the name of the file, and some of the headers
          we care about
        * read_csv to read the CSV file and return a 2d list
        
    Privacy/ethical concerns about the data:
        * Provided by the MBTA itself
        * None of it is personal or identifiable
        * Some if it might be out-of-date
        * They're incentivized to lie, but face big consequences
    
    Questions about today's dataset:
        * Mean - mean MPH, mean distance (feet/miles)
        * Range - min/max distance or MPH
        * median MPH
        * mode line  with most restrictions most common priority
        
    Questions about specific lines
        * same mean, median, range... red blue orange green
'''

import csv
import statistics
from scipy import stats

MBTA_FILE = "speed_restrictions.csv"
SPEED_HEADER = "Restriction_Speed_MPH"
DISTANCE_HEADER = "Restriction_Distance_Feet"
LINE_HEADER = "Line"
PRI_HEADER = "Priority"
PRI_NAMES = ["LOW", "MED", "HIGH"]
LINE_NAMES = ["Green", "Red", "Orange", "Blue"]

def read_csv(filename):
    ''' given the name of a csv file, return its contents as a 2d list,
        including the header.'''
    data = []
    with open(filename, "r") as infile:
        csvfile = csv.reader(infile)
        for row in csvfile:
            data.append(row)
    return data

def lst_to_dct(lst):
    ''' given a 2d list, create and return a dictionary where header '''
    dct = {}
    for row in lst:
        dct[row[0]] = row[1:]
    return dct


def filter_line(str, lst, newlst):
    filtered = [value for line, value in zip(lst, newlst) if str.lower() in line.lower()]
    return filtered
    
def convert_mph(s):
    mph = s.split()[0]
    return int(mph)

def main():
    # read in the speed restrictions data into a 2d list
    data = read_csv(MBTA_FILE)
    
    # want to compute the median distance (feet) and mean distance (feet)
    data_dct = lst_to_dct(data)
    print(data_dct)
    
    #convert feet from strings to int
    feet = [int(item) for item in data_dct[DISTANCE_HEADER]]

    #sanity check 
    print()
    print(feet)

    #what is mean distance in feet
    mean_feet = sum(feet) / len(feet)
    print(f"Mean distance in feet: {round(mean_feet, 3)}")
    
    #what is median distance in feet
    med_feet = statistics.median(feet)
    print(f"Median distance in feet: {med_feet}")

    #what line has the most restrictions
    most_restrictions = statistics.mode(data_dct[LINE_HEADER])
    print(f"{most_restrictions} has the most restrictions")
    
    print()
    
    #Get the mean distance of restrictions on green line
    green_dist = filter_line("green", data_dct[LINE_HEADER], feet)
    mean_green = sum(green_dist) / len(green_dist)
    print(f"Mean distance on the green line is {mean_green} feet")
    
    #Correlation between distance and MPH -- overall and for individual lines
    #if we find a strong correlation, we can do a linear regression
    print()
    print(data_dct[SPEED_HEADER])
    
    #clean up and convert our MPH into "x mph" --> x    
    mph = [convert_mph(item) for item in data_dct[SPEED_HEADER]]
    print()
    print(mph)
    
    #what is the correlation between feet and mph
    corr = statistics.correlation(feet, mph)
    print()
    print(f"Correlation between feet and mph is {corr}")
    
    #what is the correlation between feet and mph on individual lines
    for line in LINE_NAMES:
        line_dist = filter_line(line, data_dct[LINE_HEADER], feet)
        line_mph = filter_line(line, data_dct[LINE_HEADER], mph)
        if line_dist and line_mph:
            corr = statistics.correlation(line_dist, line_mph)
            print(f"{line} correlation: {corr}")
    
    #we have a decent correlation on the green line -- let's try a linear regression
    green_mph = filter_line("green", data_dct[LINE_HEADER], mph)
    lr = stats.linregress(green_dist, green_mph)
    
    #given an x value, compute the y value, using y= mx+b
    x = int(input("Enter a length of restriction, in feet\n"))
    y = lr.slope * x + lr.intercept
    print(f"The MPH on that length of track would be... {y}")
    
    #visualize the line of best fit for the green line
    sns.regplot(x = green_dist, y = green_mph)
    
    
if __name__ == "__main__":
    main()