/*
Given a sorted array and a value x, the ceiling of x is the smallest element in an array greater than or equal to x,
and the floor is the greatest element smaller than or equal to x.
Assume that the array is sorted in non-decreasing order.
Write efficient functions to find the floor and ceiling of x.

For example, let the input array be {1, 2, 8, 10, 10, 12, 19}
For x = 0:    floor doesn't exist in array,  ceil  = 1
For x = 1:    floor  = 1,  ceil  = 1
For x = 5:    floor  = 2,  ceil  = 8
For x = 20:   floor  = 19,  ceil doesn't exist in array
*/

#include <iostream>

int main()
{
    //int arr[] = {1, 2, 8, 10, 10, 12, 19}, x = 5;
    int arr[] = {1, 2, 8, 10, 10, 12, 19}, x = 20;
    //int arr[] = {1, 2, 8, 10, 10, 12, 19}, x = -1 ;

    int size = sizeof(arr) / sizeof(int), flag = 0;

// Solution 1
// Time Complexity: O(n) , Space Complexity: O(1)

    if (arr[0] >= x)
        std ::cout << "Ceil Element is: " << arr[0];
    else if (arr[size - 1] < x)
        std ::cout << "Ceil Element is: " << -1;
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] > x)
            {
                std ::cout << "Ceil Element is: " << arr[i];
                break;
            }
        }
    }

    std ::cout << "\n";

// Solution 2
// Time Complexity: O(logn) , Space Complexity: O(1)

    int start = 0, end = size - 1, mid = start + ((end - start) / 2);
    int ans;

    while (start <= end)
    {
        if (arr[mid] == x)
            break;
        else if (arr[mid] > x)
        {
            ans = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
        mid = start + ((end - start) / 2);
    }
    std ::cout << "Ceil Element is: " << arr[mid];
}