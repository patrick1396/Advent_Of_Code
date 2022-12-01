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

    #Set calories and max_calories to 0
    calories=0
    max_calories=0
    
    #Loops and reads in input line by line
    for i in range(0,num_lines):
        input = f.readline()

        #If the line is blank
        if (input == "\n"):
            #Check whether calories is larger than max calories and replace if true
            if (calories > max_calories):
                max_calories = calories
                
            #print(calories)
            #Reset calories counter to 0
            calories = 0

        #If the line isn't blank then it must have a number, convert to string and add to calories
        else:
            calories += int(input)

    #Close file
    f.close()

    #Output max calories
    print("Max calories: ", max_calories)

    
if __name__ == '__main__':
    main()
