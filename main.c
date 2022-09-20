#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

// Start of merge sort 
void merge(int arr[][2], int l, int m, int r, int co)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2], t1[n1], t2[n2];
 
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i][co];
        t1[i] = arr[l + i][!co];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j][co];
        t2[j] = arr[m + 1 + j][!co];
    }
    
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k][co] = L[i];
            arr[k][!co] = t1[i];
            i++;
        }
        else {
            arr[k][co] = R[j];
            arr[k][!co] = t2[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k][co] = L[i];
        arr[k][!co] = t1[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k][co] = R[j];
        arr[k][!co] = t2[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[][2], int l, int r, int co)
{
    if (l < r) {
        int m = l + (r - l) / 2;
 
        mergeSort(arr, l, m, co);
        mergeSort(arr, m + 1, r, co);
 
        merge(arr, l, m, r, co);
    }
}

void printArray(int arr[][2], int row, int col)
{
    for(int i=0; i<row; ++i)
    {
        for(int j=0; j<col; ++j)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    printf("\n");
}
// End of merge sort 

// Start of closest pair of points
float dist(int p1[2], int p2[2])    // This is used to calculate distance between two co-ordinates
{
	return sqrt( (p1[0] - p2[0])*(p1[0] - p2[0]) +
				(p1[1] - p2[1])*(p1[1] - p2[1])
			);
}

// This function is used to find minimum distance from the strip[] of size n
float bruteForce(int arr[][2], int n)
{
	float min = FLT_MAX;
	for (int i = 0; i < n; ++i)
		for (int j = i+1; j < n; ++j)
			if (dist(arr[i], arr[j]) < min)
				min = dist(arr[i], arr[j]);
	return min;
}

// This function is used to find minimum distance between two provided distances
float min(float x, float y)
{
	return (x < y)? x : y;
}

// This function is used to find distance between points from strip created
float stripClosest(int strip[][2], int size, float d)
{
	float min = d;
    int y=1;
	mergeSort(strip, 0, size-1, y);

	for (int i = 0; i < size; ++i)
		for (int j = i+1; j < size && (strip[j][y] - strip[i][y]) < min; ++j)
			if (dist(strip[i],strip[j]) < min)
				min = dist(strip[i], strip[j]);

	return min;
}

float closestPoint(int arr[][2], int n) // This is a recursive function used to find smallest distance on either side of mid point 
{
    // If there are 2 or 3 points, then use brute force method
	if (n <= 3)
		return bruteForce(arr, n);

	int mid = n/2;
	// Storing x and y co-ordinates of mid value
	int midPointX= arr[mid][0];
	int midPointY= arr[mid][1];

	float dl = closestPoint(arr, mid);
	float dr = closestPoint(arr + mid, n-mid);
	
	float d = min(dl, dr);  // Finding smallest distance between left and right side

	int strip[n][2];    // Creating an array of points which close (closer than d) to mid line
	int j = 0;
	for (int i = 0; i < n; i++)
		if (abs(arr[i][0] - midPointX) < d)
		{
			strip[j][0] = arr[i][0];
			strip[j][1] = arr[i][1];
			j++;
		}
		
	return min(d, stripClosest(strip, j, d));
}

float closest(int arr[][2], int n)  // This function is used to find smallest distance using closePoint()
{
	int y=0;
	mergeSort(arr, 0, n-1, y);
	return closestPoint(arr, n);
}
// End of closest pair of points

int main()  // Driver function to test above program
{
    int arr[][2] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {2, 1}};
    int row=6, col=2;
    
    // Variable data set
    // int arr[][2] = {{2, 6}, {30, 30}, {40, 50}, {5, 12}, {17, 10}, {2, 1}, {6, 9}, {12, 5}};
    // int row=8, col=2;
    
 	printf("The smallest distance is %f ", closest(arr, row));
    
    return 0;
}