#!/bin/python

import argparse
import numpy as np

#Routine to read in info from file for Advent of Code 2022

#Patrick Williams
#p.williams5@newcastle.ac.uk
#patrick.williams.1396@gmail.com
#30/11/2022

def main():
    #Read in the command line arguments
    parser = argparse.ArgumentParser(description='Read input file')
    
    parser.add_argument('-f', '--filename', action='store', type=str, help='The name of the file from which the data on the electrons is read, required', required='true')
    
    parser.add_argument('-n', '--numlines', action='store', type=int, help='The number of lines in the input file, required', required='true')
    
    #Set filename and num_lines to commandline argument
    filename = parser.parse_args().filename
    num_lines = parser.parse_args().numlines

    groups = int(num_lines/3)

    #Open input file
    f = open(filename)

    priority_sum = 0
    
    #Loops and reads in input line by line
    for i in range(0,groups):
        input0 = (f.readline().split()[0])
        input1 = (f.readline().split()[0])
        input2 = (f.readline().split()[0])
        
        priority_sum += badge_search(input0, input1, input2)
        
        
    #Close file
    f.close()

    print(priority_sum)

def badge_search(input0, input1, input2):
    length0 = len(input0)
    length1 = len(input1)
    length2 = len(input2)

    for j in range(0, length0):
        for k in range(0, length1):
            if (input0[j]==input1[k]):
                
                for l in range(0, length2):
                    if (input0[j]==input2[l]):
                        if (ord(input0[j])>=97):
                            return(ord(input0[j])-96)
                        else:
                            return(ord(input0[j])-38)
    
if __name__ == '__main__':
    main()
