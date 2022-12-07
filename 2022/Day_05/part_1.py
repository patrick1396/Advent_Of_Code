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
    

    parser.add_argument('-c', '--numcolumns', action='store', type=int, help='The number of stack columns, required', required='true')
        
    #Set filename and num_lines to commandline argument
    filename = parser.parse_args().filename
    num_columns = parser.parse_args().numcolumns

    stacks=[]
    for i in range(0,num_columns):
        
        stacks.append("")


    length = num_columns*4-1
    
    #Open input file
    f = open(filename)

    while True:
        #    for i in range(0,num_lines):
        input = f.readline().split("\n")[0]

        if (input==''):
            break
        
        for i in range(0, length, 4):
            if (input[i]=='['):
                stacks[int(i/4)] += input[i+1]
        


    while True:
        #print(stacks)
        input = f.readline().split("\n")[0]
        if (input==''):
            break
        
        mv, st, ed = Instructions(input)

        #print(mv, st, ed)

        
        stacks[ed-1] = stacks[st-1][0:mv][::-1]+stacks[ed-1]
        stacks[st-1] = stacks[st-1][mv:]
        

    #Close file
    f.close()

    for i in range(0,num_columns):
        print(stacks[i][0])
    
def Instructions(input):

    fst_space = 0
    scn_space = 0
    mv = 0
    st = 0
    ed = 0
        
    length = len(input)
        
    fst_space = input.find(" ")
    scn_space = input[fst_space+1:length].find(" ")+fst_space+1
    mv = int(input[fst_space:scn_space])
    
    fst_space = input[scn_space+1:length].find(" ")+scn_space+1
    scn_space = input[fst_space+1:length].find(" ")+fst_space+1
    st = int(input[fst_space:scn_space])
    
    fst_space = input[scn_space+1:length].find(" ")+scn_space+1
    #scn_space = input[fst_space+1:length].find(" ")+fst_space+1
    ed = int(input[fst_space:length])

    return(mv, st, ed)
    
if __name__ == '__main__':
    main()
