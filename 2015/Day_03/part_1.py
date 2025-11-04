#!/bin/python

import argparse
import numpy as np

#Advent of code 2015 day 3 part 1.

#Patrick Williams
#p.williams5@newcastle.ac.uk
#patrick.williams.1396@gmail.com
#30/11/2022

def main():
    #Read in the command line arguments
    parser = argparse.ArgumentParser(description='Read input file')
    
    parser.add_argument('-f', '--filename', action='store', type=str, help='The name of the file from which the data on the electrons is read, required', required='true')
    
    
    #Set filename and num_lines to commandline argument
    filename = parser.parse_args().filename


    
    #Open input file
    f = open(filename)

    instructions = f.readline()

    #Close file
    f.close()

    x = 0
    y = 0

    pos_list = [(x,y)]

    print(len(instructions))
          
    for c in instructions:
        if (c=="^"):
            y += 1
        elif (c=="v"):
            y -= 1
        elif (c==">"):
            x += 1
        elif (c=="<"):
            x -= 1

        if ((x,y) not in pos_list):
            pos_list.append((x,y))

    print(len(pos_list))
            
#    print(pos_list.len)
if __name__ == '__main__':
    main()
