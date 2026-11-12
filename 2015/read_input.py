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


    print(num_lines)
    #Open input file
    f = open(filename)

    #Loops and reads in input line by line, lines read in as strings and include a new line at the end
    for i in range(0,num_lines):
        input = f.readline()
        print(input)

    #Close file
    f.close()

    
if __name__ == '__main__':
    main()
