#define _CRT_SECURE_NO_WARNINGS //interpolycia
#include<stdio.h>
#include<math.h>

int interpolationSearch(int array[], int size, int n)
{
    int low = 0;
    int mid;
    int high = size - 1;
    while (1)
    {
        
        if (array[low] == n)
            return low;
        else if (array[high] == n)
            return high;

        if (array[low] == array[high])
            break;
        mid = low + (n - array[low]) * (high - low) / (array[high] - array[low]);
        
        if (n < array[mid])
            high = mid;
        
        else if (n > array[mid])
            low = mid + 1;
        else
            return mid;
        
        
    }
    return -1;
}
int main() {
    int x[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
    printf("%d", interpolationSearch(x, 15, 12));
}

