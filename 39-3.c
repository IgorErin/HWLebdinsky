define _CRT_SECURE_NO_WARNINGS //interpolycia

#include<stdio.h>
#include<math.h>


int interpolationSearch(int array[], int size, int n)
{
    int low = 0;
    int mid;
    int high = size - 1;

    while (n > array[low] && n < array[high])
    {
        if (array[low] == array[high])
            break;

        mid = low + (n - array[low]) * (high - low) / (array[low] - array[high]);// границы проверка
        if (n < array[mid])
            high = mid - 1;
        else if (n > array[mid])// не работает.
            low = mid + 1;
        else
            return mid;

        if (array[low] == n)
            return low;
        else if (array[high] == n)
            return high;
    }
    return -1;
}




int main() {
    int x[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
    
}

