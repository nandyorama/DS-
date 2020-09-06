import sys 
import os 


class T:
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None
    
def In(cur):
    root = cur
    while root:
        if root.left is None:
            print (root.data)
            root = root.right
        else:
            prev = (root.left);
            while prev.right is not None and prev.right is not root:
                prev=prev.right
                
            if prev.right is None:
                prev.right = root
                root = root.left
            else:
                prev.right = None
                print (root.data)
                root = root.right
  
    
root = T(5)
root.left = T(3)
root.right = T(7)
root.left.left = T(2)
root.left.right = T(4)
root.right.left = T(6)
root.right.right = T(8)
In(root)


