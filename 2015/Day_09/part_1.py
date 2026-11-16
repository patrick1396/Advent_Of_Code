#!/bin/python

import argparse
import numpy as np

#Routine to read in info from file for Advent of Code 2022

#Patrick Williams
#patrick.williams.1396@gmail.com
#13/11/2026

def Triangle_Inverse(t):
    return int((np.sqrt(1+8*t)-1)/2)

def TSP(curr_node, num_nodes, nodes, edges, shortest_length, shortest_path, curr_length, curr_path):
    nodes[curr_node] = False

    #If all the nodes have been visited then check whether shortest length should be updated.
    if(np.all(nodes==False)):
        #Not sure if this check is necessary as if we've made it this far then the path can't be longer than shortest path.
        if (curr_length < shortest_length):
            shortest_length = curr_length
            shortest_path = curr_path.copy()
            return (shortest_length, shortest_path)

    #print(edges)
    for i in range(0, num_nodes+1):
        if (nodes[i]== False):
            continue
        curr_path.append(i)
        curr_length += edges[curr_node, i]
        if (curr_length <= shortest_length):
            shortest_length, shortest_path = TSP(i, num_nodes, nodes.copy(), edges, shortest_length, shortest_path, curr_length, curr_path)

        curr_path.pop()
        curr_length -= edges[curr_node, i]
        

    return (shortest_length, shortest_path)
    
def main():
    #Read in the command line arguments
    parser = argparse.ArgumentParser(description='Read input file')
    
    parser.add_argument('-f', '--filename', action='store', type=str, help='The name of the file from which the data on the electrons is read, required', required='true')
    
    parser.add_argument('-n', '--numlines', action='store', type=int, help='The number of lines in the input file, required', required='true')
    
    #Set filename and num_lines to commandline argument
    filename = parser.parse_args().filename
    num_lines = parser.parse_args().numlines


    #Add 1 to Traingle inverse of number of lines as lines show conncetions between nodes and there are 1 more nodes than connections (Assuming all nodes are connected to each other)
    num_nodes = Triangle_Inverse(num_lines)+1


    edges = np.zeros((num_nodes+1,num_nodes+1), dtype=np.int32)
    nodes = np.zeros((num_nodes+1), dtype=bool)
    nodes[1:num_nodes+1] = True
    
    #Open input file
    f = open(filename)

    #Calculate the not possible worst case scenario as if all edges were the longest edge 
    shortest_length = 0
    #Loops and reads in input line by line, lines read in as strings and include a new line at the end
    for i in range(1,num_nodes):
        for j in range(i+1, num_nodes+1):
            edges[i,j] = int(f.readline().split("\n")[0].split(" ")[4])
            if(edges[i,j] > shortest_length):
                shortest_length = edges[i,j]
            #input = f.readline().split("\n")[0]#.split(" ")[4]
            #print(j, edges[i,j])

    #Close file
    f.close()
    shortest_length *= (num_nodes-1)
    
    edges += np.transpose(edges)
    print(edges)
    print(nodes)
    print(shortest_length)
    shortest_path = []
    print()
    
    shortest_length, shortest_path = TSP(0, num_nodes, nodes.copy(), edges, shortest_length, shortest_path, 0, [])
    print(nodes)
    print(shortest_length)
    print(shortest_path)
    
if __name__ == '__main__':
    main()
