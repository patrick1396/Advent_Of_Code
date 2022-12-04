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

    useless_elves = 0
    
    #Loops and reads in input line by line
    for i in range(0,num_lines):
        allocation = np.zeros((2,2), dtype=int)
        
        
        input = f.readline().split()[0]
        
        hold = input.split(",")
        allocation[0][0] = int(hold[0].split("-")[0])
        allocation[0][1] = int(hold[0].split("-")[1])
        allocation[1][0] = int(hold[1].split("-")[0])
        allocation[1][1] = int(hold[1].split("-")[1])

        # print(allocation[0][0], allocation[0][1])
        # print(allocation[1][0], allocation[1][1])

        elf0 = ""
        elf1 = ""
        
        for j in range(allocation[0][0], allocation[0][1]+1):
            elf0 += " "+str(j)

        for j in range(allocation[1][0], allocation[1][1]+1):
            elf1 += " "+str(j)

        elf0+=" "
        elf1+=" "
        
        if ((elf0.find(elf1)>=0)or(elf1.find(elf0)>=0)):
            useless_elves+=1

    print("Number of pairs with overlap: ", useless_elves)
        
    #Close file
    f.close()

    
if __name__ == '__main__':
    main()
