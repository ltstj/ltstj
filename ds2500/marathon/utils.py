'''
    DS2500
    Spring 2024
    
    Utility functions file. Add on to this whenever you like, and you 
    can import it into whatever .py file you're working on'

'''


import os
import csv
import seaborn as sns
import matplotlib.pyplot as plt

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
    ''' given a 2d list, create and return a dictionary.
        keys of the dictionary come from the header (first
                                                     row)
        , values are corresponding columns, saved as lists
        Ex: [[1, 2, 3], [x, y, z], [a, b, c]]
        should return {1 : [x, a], 2 : [y, b], 3 : [z, c]}
    '''
    dct = {}
    for h in lst[0]:
        dct[h] = []
    for row in lst[1:]:
        for i in range(len(row)):
            dct[lst[0][i]].append(row[i])
    return dct

def median(orig_lst):
    ''' given a list of numbers, compute and return median'''
    lst = orig_lst.copy()
    lst.sort()
    mid = len(lst) // 2
    if len(lst) % 2 == 1:
        return lst[mid]
    else:
        avg = (lst[mid] + lst[mid - 1]) / 2
        return avg
    
def get_filenames(dirname, ext = ".csv"):
    ''' given a directory name(string), return the full path and name for every
    non-directory file in the directory (list of strings)'''
    filenames = []
    files = os.listdir(dirname)
    for file in files:
        if not os.path.isdir(file) and file.endswith(ext):
            filenames.append(dirname + "/" + file)
    return filenames   

    
def normalize(lst):
    ''' given a '''
    mn = min(lst)
    mx = max(lst)
    normal = []
    for x in lst:
        normal_x = (x-mn) / (mx-mn)
        normal.append(normal_x)
    return normal


def main():
    print("Utils file is operational")
    

if __name__ == "__main__":
   main() 