#!/bin/python

import argparse
import numpy as np

#Routine to read in info from file for Advent of Code 2022

#Patrick Williams
#p.williams5@newcastle.ac.uk
#patrick.williams.1396@gmail.com

def separate(st):
    coord = st.split(",")
    return(int(coord[0]), int(coord[1]))

def main():
    #Read in the command line arguments
    parser = argparse.ArgumentParser(description='Read input file')
    
    parser.add_argument('-f', '--filename', action='store', type=str, help='The name of the file from which the data on the electrons is read, required', required='true')
    
    parser.add_argument('-n', '--numlines', action='store', type=int, help='The number of lines in the input file, required', required='true')
    
    #Set filename and num_lines to commandline argument
    filename = parser.parse_args().filename
    num_lines = parser.parse_args().numlines

    lights = np.zeros((1000,1000)).astype(int)

    #Open input file
    f = open(filename)

    #Loops afnd reads in input line by line, lines read in as strings and include a new line at the end
    for i in range(0,num_lines):
        inpt = f.readline().split()
        ninstr = len(inpt)
        
        if (ninstr==4): #toggle
            x1,y1 = separate(inpt[1])
            x2,y2 = separate(inpt[3])

            for j in range(x1,x2+1):
                for k in range(y1,y2+1):
                    if (lights[j,k]==1):
                        lights[j,k]=0
                        
                        
                    elif (lights[j,k]==0):
                        lights[j,k]=1
                        
                        
        elif (ninstr==5 and inpt[1]=="on"):
            x1,y1 = separate(inpt[2])
            x2,y2 = separate(inpt[4])
            
            for j in range(x1,x2+1):
                for k in range(y1,y2+1):
                    lights[j,k] = 1
                    
        elif (ninstr==5 and inpt[1]=="off"):
            x1,y1 = separate(inpt[2])
            x2,y2 = separate(inpt[4])
            
            for j in range(x1,x2+1):
                for k in range(y1,y2+1):
                    lights[j,k] = 0

            
    #Close file
    f.close()

    print(sum(sum(lights)))

    
if __name__ == '__main__':
    main()
