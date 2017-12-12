import sys 
import os 
import copy

class T:
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None
    
def KthSmallestNumber(root,n,k):
    cur = root
    result = 0
    while cur:
        if cur.left is None:
            n += 1 
            if n == k:
                result = cur.data
            cur = cur.right
        else:
            prev = (cur.left);
            while prev.right is not None and prev.right is not cur:
                prev=prev.right
                
            if prev.right is None:
                prev.right = cur
                cur = cur.left
            else:
                prev.right = None
                n += 1 
                if n == k:
                    result = cur.data
                cur = cur.right
    return result
  
    
root = T(5)
root.left = T(3)
root.right = T(7)
root.left.left = T(2)
root.left.right = T(4)
root.right.left = T(6)
root.right.right = T(8)
print("Kth Smallest Number in Tree is ")
print(KthSmallestNumber(root,0,4))


