# Closest Pair of Points Problem 
***
## Name: Reema Khandelwal
## Roll no: 16
## Design  and analysis of algorithm assignment
***
## Question:
Implement a solution to find a minimum distance between two points. Input array: each element defined as [a, b] for example [2, 3]. Use distance formula.
***
## Approach:
1. For a given array of points in the 2D plane with x and y co-ordinates, we have to find closest pair of points.
2. Sort the given array according to x co-ordinates and find the middle point from it. We can take P[n/2] as middle point. 
3. Divide the array into two halves. The first subarray constain points from P[0] to p[n/2], whereas other constain points from P[n/2+1] to P[n-1].
4. Recursively find the smallest distances from both the sub arrays. Let dl and dr be minimum distance from left and right sub array. Find the minimum distance between dl and dr. Let d be the minimum distance.
5. From the above steps we get the upper bound of minimum distance. Now we need to consider the pairs where one point is from left part and other from right part.
6. Consider a middle line passing through P[n/2] and create a strip[] of all points whose x co-ordinate is closer than d to the middle vertical line.
7. Sort the strip[] according to y co-ordinate. Though sorting takes O(nLogn) but it can be optimised in O(n) by recursively sorting and merging.
8. Find the smallest distance from strip[]. Though it might seem to be an O(n^2) step, but it is actually O(n) (It can be proved geometrically that at most only 7 comparisons are needed to check the minimum distance).
9. The strip is traversed from bottom to top and minimum distance is obtained. Finally, we return the minimum between d and minimum distance obtained from strip[].
##
***
## Complexity:
Let T(n) be the time complexity of the above algorithm. Let us assume that the sorting algorithm uses O(nLogn) time complexity. The algorithm recursively divides the array in two halves. After dividing, the strip[] is build in O(n) time complexity. Also, it takes O(n) time to sort strip[] according to y co-ordinate and find smallest distance.  
Thus, the T(n) can be expressed as  
T(n) = 2T(n/2) + O(n) + O(n) + O(n)  
T(n) = 2T(n/2) + O(n)  
T(n) = T(nLogn)   
The time complexity of the algorithm is **O(nLogn)**.
##
***
## Implementation:
The above discussed algorithm is implemented in **C** programming language using 2D array.
##
***
## Test Cases:

Test case 1: (2, 3), (12, 30), (40, 50), (5, 1), (12, 10), (2, 1)  
The minimum distance is 2 between points (2, 3) and (2, 1).  
![t1](https://user-images.githubusercontent.com/94159340/191347324-c55cd7e5-83a7-4756-9581-c139f9c5e3d0.png)


Test case 2: (2, 6), (30, 30), (40, 50), (5, 12), (17, 10), (2, 1), (6, 9), (12, 5)  
The minimum distance is 3.162278 between points (2, 6) and (6, 9).  
![t2](https://user-images.githubusercontent.com/94159340/191347716-9b06976e-be6f-49eb-9c81-c93d37ff3340.png)


Test case 3: (2, -3), (-30, 30), (-17, 10), (2, -1), (6, 9), (-12, 5)  
The minimum distance is 2 between points (2, -3) and (2, -1).  
![t3](https://user-images.githubusercontent.com/94159340/191347761-15188d0c-b9e1-481f-80f5-0ac7fde68ce3.png)
