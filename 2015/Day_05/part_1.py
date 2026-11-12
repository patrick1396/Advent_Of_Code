#!/bin/python

import argparse
import numpy as np
import re

#Routine to read in info from file for Advent of Code 2022

#Patrick Williams
#p.williams5@newcastle.ac.uk
#patrick.williams.1396@gmail.com
#30/11/2022

def main():
    vowel = "aeiou"
    illgl = ["ab","cd","pq","xy"]
    #Read in the command line arguments
    parser = argparse.ArgumentParser(description='Read input file')
    
    parser.add_argument('-f', '--filename', action='store', type=str, help='The name of the file from which the data on the electrons is read, required', required='true')
    
    parser.add_argument('-n', '--numlines', action='store', type=int, help='The number of lines in the input file, required', required='true')
    
    #Set filename and num_lines to commandline argument
    filename = parser.parse_args().filename
    num_lines = parser.parse_args().numlines

    #Open input file
    f = open(filename)

    #Loops and reads in input line by line, lines read in as strings and include a new line at the end
    nice_count = 0
    for i in range(0,num_lines):
        cntn_vl = False
        cntn_db = False
        cntn_il = False
        inpt = f.readline()

        #vowel count
        vl_count = 0
        for v in vowel:
            x = re.findall(v, inpt)
            vl_count += len(x)
        cntn_vl = (vl_count >= 3)
        #print(cntn_vl)

        #double character check
        x = re.findall(r'([a-z])\1', inpt)
        cntn_db = len(x)>0

        #illegal character check
        il_count = 0
        for l in illgl:
            x = re.findall(l, inpt)
            il_count += len(x)
        cntn_il = il_count>0

        if(cntn_vl and cntn_db and not cntn_il):
            nice_count +=1
            
        

    #Close file
    f.close()
    print(nice_count)

    
if __name__ == '__main__':
    main()
