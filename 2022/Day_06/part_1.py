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
    
    parser.add_argument('-i', '--input', action='store', type=str, help='The input string, required', required='true')
    
    #Set filename and num_lines to commandline argument
    data_buff = parser.parse_args().input

    length = len(data_buff)

    s = data_buff[0]
    
    i = 1
    
    while True:
        x = data_buff[i]
        index = s.find(x) 
        
        if (index==-1):
            s += x
        else:
            s = s[index+1:]+x
        
        if (len(s)==4):
            break
        else:
            i+=1

    print(i+1, s)
    
if __name__ == '__main__':
    main()
