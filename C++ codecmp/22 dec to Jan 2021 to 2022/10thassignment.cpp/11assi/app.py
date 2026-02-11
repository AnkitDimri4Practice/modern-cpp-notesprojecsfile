arr1=int(input("Number of elements in the array:-"))
n=list(map(int, input("elements of array:-").strip().split()))
print(n)
import numpy as np
 
arr1 = np.array([3, 2, 1])
arr2 = np.array([1, 2, 3])
   
print ("1st array : ", arr1)  
print ("2nd array : ", arr2)  
   
out_arr = np.add(arr1, arr2)  
print ("added array : ", out_arr)  