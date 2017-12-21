import sys
from array import *

def findWindow(ip):
    n = len(ip)
    print(n)
    #visit= array('i',[0,0,0,0,0,0,0,0,0,0])
    visit = [0] * n
    count = 0
    c = 0
    for i in range(n):
        tmp = ord(ip[i]) - ord('a')
        if visit[tmp]==0:
            visit[tmp] = 1 
            count+=1 
            
    start = 0
    startIndex = 0
    maxWindow = sys.maxsize
    ccount = [0] * 256
    for i in range(n):
        tmp = ord(ip[i]) - ord('a')
        ccount[tmp] += 1 
        if ccount[tmp] == 1:
            c += 1
        if c == count:
            while ccount[tmp] > 1:
                if ccount[tmp] > 1:
                    ccount[tmp]-= 1 ;
                start += 1 
            nw = i - start+1 
            if nw < maxWindow:
                maxWindow = nw 
                startIndex = start 
    return ip[startIndex:]
    
                
ip = "aabcbcdbac"
print("Smallest Substring z ", findWindow(ip))
