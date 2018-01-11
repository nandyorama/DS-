'''
Python Program For Different Functionality of Tree related.
'''

class T:
    def __init__(self,data):
        self.data = data
        self.l = None
        self.r = None
        
#Max Value Function        
def maxValue(a,b):
    if a < b:
        return b 
    else:
        return a
        
#Height Of Tree        
def height(root):
    if root is None:
        return 0
    if root.l is None and root.r is None:
        return 1 
    else:
        return 1+ maxValue(height(root.l),height(root.l))

#label Util Order Traversal of Tree
def labelUtil(root,i):
    if i == 0:
        print(root.data)
    else:
        labelUtil(root.l,i-1)
        labelUtil(root.r,i-1)
        
#label Order Traversal of Tree        
def label(root):
    h = height(root)
    for i in range(h):
        print("----")
        labelUtil(root,i)

#Reverse Label Order Traversal
def relabelUtil(root,i,flag):
    if i == 0:
        print(root.data)
    else:
        if flag:
            relabelUtil(root.l,i-1,flag)
            relabelUtil(root.r,i-1,flag)
        else:
            relabelUtil(root.r,i-1,flag)
            relabelUtil(root.l,i-1,flag)
        
def relabel(root):
    h = height(root)
    flag = 0
    for i in range(h):
        print("----")
        relabelUtil(root,i,flag)
        flag ^= 1

#Inorder Traversal Without stack and Recursion
def inorder(root):
    cur = root
    while cur:
        if cur.l is None:
            print(cur.data,end=" ")
            cur = cur.r
        else:
            prev = cur.l 
            while prev.r is not None and prev.r is not cur:
                prev = prev.r
                
            if prev.r is None:
                prev.r = cur
                cur = cur.l 
            else:
                prev.r = None
                print(cur.data,end=" ")
                cur = cur.r
                
#inorder with Stack                
def inorderWithStack(root):
    cur = root
    flag = 1
    lst = []
    #print(type(lst))
    #print(dir(lst))
    while flag:
        if cur is not None:
            lst.append(cur)
            cur = cur.l
        else:
            if len(lst)>0:
                cur = lst.pop()
                print(cur.data,end="--") 
                cur = cur.r
            else:
                flag = 0

#Merge Two BST Tree            
def mergeTwoBST(root1,root2):
    done1 = 1
    done2 = 1
    cur1 = root1
    cur2 = root2
    lst1 = []
    lst2 = []
    result1 = 0
    result2 = 0
    while 1:
        while done1:
            result1 = 0
            if cur1 is not None:
                lst1.append(cur1)
                cur1 = cur1.l
            else:
                if len(lst1)>0:
                    cur1 = lst1.pop()
                    #print(cur.data,end="--") 
                    result1 = cur1.data
                    cur1 = cur1.r
                    done1 = 0 
                else:
                    done1 = 0

        while done2:
            result2 = 0
            if cur2 is not None:
                lst2.append(cur2)
                cur2 = cur2.l
            else:
                if len(lst2)>0:
                    cur2 = lst2.pop()
                    #print(cur.data,end="--")
                    result2 = cur2.data
                    cur2 = cur2.r
                    done2 = 0 
                else:
                    done2 = 0
                
        if result1 == 0 and result2 == 0:
            break
        elif result1 == 0 and result2 is not 0:
            print(result2,end=" && ")
            done2 = 1 
        elif result2 == 0 and result1 is not 0:
            print(result1,end=" && ")
            done1 = 1 
        elif result2 < result1 and result1 is not 0:
            print(result2,end=" && ")
            done2 = 1 
        elif result2 > result1 and result2 is not 0:
            print(result1,end=" && ")
            done1 = 1 
    
                
#Kth Smallest node in BST
def KthSmallest(root,k):
    cur = root
    count = 0
    result = 0
    while cur:
        if cur.l is None:
            count += 1
            if count == k:
                result = cur.data
            cur = cur.r
        else:
            prev = cur.l 
            while prev.r is not None and prev.r is not cur:
                prev = prev.r
                
            if prev.r is None:
                prev.r = cur
                cur = cur.l 
            else:
                prev.r = None
                count += 1
                if count == k:
                    result = cur.data
                cur = cur.r
    return result

#Swap Two Numbers
def swap(a,b):
    a ,b = b, a


#Find Common Acestor of Two given Values
def LCA(root,a,b):
    if root is None:
        return None
    if root.data == a or root.data == b:
        return root 
    nodel = LCA(root.l,a,b)
    noder = LCA(root.r,a,b)
    
    if nodel is not None and noder is not None:
        return root 
    else:
        return nodel if noder is None else noder
    
def findValue(root,a,value):
    if root is None:
        return 0 
    if root.data == a:
        return value 
    lv = findValue(root.l,a,value+1)
    if lv == 0:
        return findValue(root.r,a,value+1)
    else:
        return lv

#Distance between two given elements of Tree
def distanceBetweenNodes(root,a,b):
    if root is None:
        return 0 
    lca = LCA(root,a,b)    
    avalue = findValue(lca,a,0)
    bvalue = findValue(lca,b,0)
    return avalue+bvalue

#Find Diameter of Tree
def diameter(root):
    if root is None:
        return 0 
    
    lh = height(root.l)
    rh = height(root.r)
    
    ld = diameter(root.l)
    rd = diameter(root.r)
    return max(lh+rh+1,max(ld,rd))
    
#Find Pair in given Tree whose sum is same to given Input Number
def findPairInBST(root,sum):
    done1 = 1
    done2 = 1
    cur1 = root
    cur2 = root
    lst1 = []
    lst2 = []
    result1 = 0
    result2 = 0
    while 1:
        while done1:
            if cur1 is not None:
                lst1.append(cur1)
                cur1 = cur1.l
            else:
                if len(lst1)>0:
                    cur1 = lst1.pop()
                    #print(cur.data,end="--") 
                    result1 = cur1.data
                    cur1 = cur1.r
                    done1 = 0 
                else:
                    done1 = 0

        while done2:
            if cur2 is not None:
                lst2.append(cur2)
                cur2 = cur2.r
            else:
                if len(lst2)>0:
                    cur2 = lst2.pop()
                    #print(cur.data,end="--")
                    result2 = cur2.data
                    cur2 = cur2.l
                    done2 = 0 
                else:
                    done2 = 0
        
        if result1 != result2 and result1+result2 == sum:
            print("Found two Nodes",result1,"--", result2," whose sum z ",sum)
            return 1
        elif result1+result2 > sum:
            done2 = 1 
        elif result1+result2 < sum:
            done1 = 1 
        
        if result1 > result2:
            return 0 

import queue
#Level Order Traversal Using Iterative method i.e using Queue 
def labelOrderTraversal(root):
    #print("labelOrderTraversal")
    if root is None:
        return
    q = queue.Queue()
    q.put(root)
    while not q.empty():
        temp = q.get()
        print(temp.data,end = "**&**")
        if temp.l is not None:
            q.put(temp.l)
            
        if temp.r is not None:
            q.put(temp.r)

#Util function for Converting BST to Double Link List                
def b2dUtil(root):
    if root is None:
        return root
    ls = b2dUtil(root.left)
    if ls is not None:
        while ls.right is not None:
            ls = ls.right
            
        ls.right = root
        root.left = ls
        
    rs = b2dUtil(root.right)
    if rs is not None:
        while rs.left is not None:
            rs = rs.left
            
        rs.left = root
        root.right = rs
    return root

#Convert BST to Double Link List    
def b2d(root):
    cur = b2dUtil(root)
    while cur.left is not None:
        cur = cur.left
    
    while cur is not None:
        print(cur.data,end="*&*")
        cur = cur.right
        
                
        
        
#Driver Functions call
root = T(5)
root.l = T(3)
root.r = T(7)
root.l.l = T(2)
root.l.r = T(4)
root.r.l = T(6)
root.r.r = T(8)
print("Inorder Traversal of given Tree z")
inorder(root)
lcaResult = LCA(root,2,8)
#lcaResult1 = LCA(root,6,8)
print("\nLCA of Two nodes i.e 2 and 8 z", lcaResult.data)
#print("\nLCA of Two nodes i.e 6 and 8 z", lcaResult1.data)
print("\n Disatnce Between Two Nodes in Tree z ",distanceBetweenNodes(root,6,8))
print("\n Diameter of given Tree z ",diameter(root))
if findPairInBST(root,14):
    print("Pair Found.")
else:
    print("Pair not Found.")
labelOrderTraversal(root)  
'''
root = T(5)
root.l = T(3)
root.r = T(7)
root.l.l = T(2)
root.l.r = T(4)
#root.l.l.l = T(1)
root.r.l = T(6)
root.r.r = T(8)
print("Inorder Traversal\n")
inorder(root)
root1 = T(10)
root1.l = T(9)
root1.r = T(19)
print("Inorder Traversal\n")
inorder(root1)
print("********MergeTwoBST**********\n")
mergeTwoBST(root,root1)
print("Inorder Traversal")
inorder(root)
print("\nInorder Traversal with Stack")
inorderWithStack(root)
print("\nKth Smallest Node in BST z",KthSmallest(root,4))
#print("Label Order Traversal")
#label(root)
#print("Reverse Label Order Traversal")
#relabel(root)
#print("Height of given Tree is ")
#print(height(root))
''' 









