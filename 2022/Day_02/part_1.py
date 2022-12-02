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

    score = 0

    #Open input file
    f = open(filename)

    #Loops and reads in input line by line and splits into columns
    for i in range(0,num_lines):
        input = f.readline().split()

        #Check first character for opponent move and player move
        #Nested if because I'm too lazy to think of something smarter
        #ABC is rock paper scissors for opponent
        #XYZ is rock paper scissors for player
        if (input[0] == 'A'):
            if (input[1] == 'X'):
                score += 1+3
            elif (input[1] == 'Y'):
                score += 2+6
            elif (input[1] == 'Z'):
                score += 3+0
                
        elif (input[0] == 'B'):
            if (input[1] == 'X'):
                score += 1+0
            elif (input[1] == 'Y'):
                score += 2+3
            elif (input[1] == 'Z'):
                score += 3+6
                
        elif (input[0] == 'C'):
            if (input[1] == 'X'):
                score += 1+6
            elif (input[1] == 'Y'):
                score += 2+0
            elif (input[1] == 'Z'):
                score += 3+3        

    #Close file
    f.close()

    #Output score
    print("Score: ", score)

    
if __name__ == '__main__':
    main()
