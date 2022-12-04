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


    #Open input file
    f = open(filename)

    priority_sum = 0
    
    #Loops and reads in input line by line
    for i in range(0,num_lines):
        input = (f.readline().split()[0])
        priority_sum += search(input)
        
        
    #Close file
    f.close()

    print(priority_sum)

def search(input):
    length = len(input)

    for j in range(0,int(length/2)):
        for k in range(int(length/2),length):
            if (input[j]==input[k]):
                if (ord(input[j])>=97):
                    return(ord(input[j])-96)
                else:
                    return(ord(input[j])-38)
    
if __name__ == '__main__':
    main()
