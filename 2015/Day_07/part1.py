#!/bin/python

import argparse
import numpy as np

#Routine to read in info from file for Advent of Code 2022

#Patrick Williams
#p.williams5@newcastle.ac.uk
#patrick.williams.1396@gmail.com


class wire:
    value = 0
    dependencies = []
    instruction  = []
    

def main():
    #Read in the command line arguments
    parser = argparse.ArgumentParser(description='Read input file')
    
    parser.add_argument('-f', '--filename', action='store', type=str, help='The name of the file from which the data on the electrons is read, required', required='true')
    
    parser.add_argument('-n', '--numlines', action='store', type=int, help='The number of lines in the input file, required', required='true')
    
    #Set filename and num_lines to commandline argument
    filename = parser.parse_args().filename
    num_lines = parser.parse_args().numlines


#    print(num_lines)
    #Open input file
    f = open(filename)

    lst_inpt = []
    ord_inpt = {}
    #Loops and reads in input line by line, lines read in as strings and include a new line at the end
    for i in range(0,num_lines):
        inpt = f.readline().split("\n")[0].split("->")
        check = inpt[0].split(" ")
        if(len(check)==2 and check[0].isdigit()):
            # hold_wire = wire()
            # hold_wire.value = int(check[0])
            ord_inpt[inpt[1].split(" ")[1]] = int(check[0]) 
        elif(check[0].isdigit()):
            # hold_wire = wire()
            # hold_wire.value = int(check[0])
            ord_inpt[check[0]] = int(check[0])
            lst_inpt.append(inpt)
        else:
            lst_inpt.append(inpt)
        

    #Close file
    f.close()
    # print(lst_inpt)
    #print(ord_inpt)

    
    #    while (len(ord_inpt)<len(lst_inpt)):
    while(len(lst_inpt)>0):
        #print(len(lst_inpt))
        for inpt in lst_inpt:
            instructions = inpt[0].split(" ")
            key = inpt[1].split(" ")[1]
            
            if (instructions[0] == "NOT"):
                if (instructions[1] in ord_inpt):
                    value = ~ord_inpt[instructions[1]]&0xffff
                    ord_inpt[key] = value
                    lst_inpt.remove(inpt)
                    

            elif (instructions[1] == "OR"):
                if(instructions[0] in ord_inpt and instructions[2] in ord_inpt):
                    value = ord_inpt[instructions[0]]|ord_inpt[instructions[2]]
                    ord_inpt[key] = value
                    lst_inpt.remove(inpt)
                    
            elif (instructions[1] == "AND"):
                if(instructions[0] in ord_inpt and instructions[2] in ord_inpt):
                    value = ord_inpt[instructions[0]]&ord_inpt[instructions[2]]
                    ord_inpt[key] = value
                    lst_inpt.remove(inpt)
                
                
            elif (instructions[1] == "RSHIFT"):
                if(instructions[0] in ord_inpt):
                    value = ord_inpt[instructions[0]]>>int(instructions[2])
                    ord_inpt[key] = value
                    lst_inpt.remove(inpt)

                    
            elif (instructions[1] == "LSHIFT"):
                if(instructions[0] in ord_inpt):
                    value = ord_inpt[instructions[0]]<<int(instructions[2])
                    ord_inpt[key] = value
                    lst_inpt.remove(inpt)


            elif (len(instructions) == 2):
                if (instructions[0] in ord_inpt):
                    ord_inpt[key] = ord_inpt[instructions[0]]
                    lst_inpt.remove(inpt)
                
    print(ord_inpt["a"])
                    
if __name__ == '__main__':
    main()
