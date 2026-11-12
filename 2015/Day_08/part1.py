#!/bin/python

import argparse
import numpy as np
import re

#Patrick Williams
#p.williams5@newcastle.ac.uk
#patrick.williams.1396@gmail.com

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

    sum_lit = 0
    sum_mem = 0
    #Loops and reads in input line by line, lines read in as strings and include a new line at the end
    for i in range(0,num_lines):
        lit_str = f.readline().split("\n")[0]
        sum_lit += len(lit_str)
        
        mem_str = lit_str[1:len(lit_str)-1]
#        print(len(mem_str))
        #print(mem_str)
        mem_str = re.sub(r'\\"', "X", mem_str)
        mem_str = re.sub(r'\\\\', "X", mem_str)
        mem_str = re.sub(r"\\x[0-9|a-f]{2}", "X", mem_str)
        #print(mem_str)
        
        sum_mem += len(mem_str)

        #
        #print(mem_str)
        #print()

        #print(len(inpt))

    #Close file
    f.close()
    print(sum_lit)
    print(sum_mem)
    print(sum_lit-sum_mem)
                       
    
if __name__ == '__main__':
    main()
