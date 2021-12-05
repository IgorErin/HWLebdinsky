#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>
#include <time.h>

#define SIZE 500

void heapify(int arr[], int n, int i)
{
    int largest = i;
    
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        int c = arr[i];
        arr[i] = arr[largest];
        arr[largest] = c;

        heapify(arr, n, largest);
    }
}


void heapSort(int arr[], int n)
{
    
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

   
    for (int i = n - 1; i >= 0; i--)
    {
        
        int c = arr[0];
        arr[0] = arr[i];
        arr[i] = c;
        heapify(arr, i, 0);
    }
}


int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
