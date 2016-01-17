#!/usr/bin/python3
import sys

sum=0
string=str(sys.argv[1])
for i in string:
	sum=sum+ord(i)
print(sum)
