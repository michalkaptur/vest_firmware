#!/usr/bin/python3
import sys

sum=0
string=str(sys.argv[1])
for i in string:
	sum=sum+ord(i)
print(sum%100)
print('[D#'+string+'#'+str((sum+ord('D'))%100).zfill(2)+']')
print('[C#'+string+'#'+str((sum+ord('C'))%100).zfill(2)+']')
