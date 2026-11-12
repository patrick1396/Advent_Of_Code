#!/bin/python

import numpy as np
import hashlib #Be lazy, can't be bothered to implement md5 process

#AoC 2015 day 4 part 1

#Patrick Williams
#p.williams5@newcastle.ac.uk
#patrick.williams.1396@gmail.com
#patrick.j.williams@durham.ac.uk

def main():
    secret_key = "bgvyzdsv"
    buff = 1

    while True :

        
        inpt = secret_key + str(buff)
        res = hashlib.md5(inpt.encode()).hexdigest()
        #print(str(buff) + " " + str(res))
        if (res[0:5] == "00000"):
            break

        buff += 1
        
    print(res)
    print(buff)



    #Loop until number is found

    
if __name__ == '__main__':
    main()
