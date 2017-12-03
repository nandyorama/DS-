import sys
def matrixMul(arr,n):
    result = [[0 for x in range(n)]for x in range(n)]
    for i in range(n):
        result[i][i] = 0
    
    for l in range(2,n):
        for i in range(1,n-l+1):
            j = i+l-1
            result[i][j] = sys.maxsize
            for k in range(i,j):
                temp = result[i][k]+result[k+1][j]+arr[i-1]*arr[k]*arr[j]
                if temp<result[i][j] :
                    result[i][j] = temp
                
    return result[1][n-1]
    

a = [1,2,3,4]
n = len(a)
print(n)
print("Minimum of Matrix multiplication  z " + str(matrixMul(a,n)))
