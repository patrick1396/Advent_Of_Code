#!/bin/python

import argparse
import numpy as np

#Routine to read in info from file for Advent of Code 2015

#Patrick Williams
#patrick.williams.1396@gmail.com
#17/11/2015

def look_and_say(init):

    val = ""
    out = ""
    for i in range(0, len(init)):
        if (init[i] != val):
            val = init[i]
            count = 1
        else:
            count += 1

        if ((i==len(init)-1)or(init[i+1] != val)):
            out += str(count) + val

    return(out)
    
        

def main():
    #Read in the command line arguments
    parser = argparse.ArgumentParser(description='Read input file')
    
    parser.add_argument('-i', '--value', action='store', type=str, help='Then input for the look and say process', required='true')
    parser.add_argument('-n', '--number_applications', action='store', type=int, help='Number of times to apply the process', required='true')
    
    #Set filename and num_lines to commandline argument
    val = parser.parse_args().value
    num = parser.parse_args().number_applications

    
    for i in range(0, num):
        val = look_and_say(val)
    print(len(val))


    
if __name__ == '__main__':
    main()
