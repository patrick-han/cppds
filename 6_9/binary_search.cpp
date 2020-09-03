#include <iostream>
#include <vector>


// Binary Search: Given an ordered list, search the list using a divide and conquer strategy.
// Determine the midpoint of the list and check if we've found the element. If not, depending
// on if the element is larger or smaller than the midpoint, search the upper or lower half respectively.
// Keep going until we find the element or the sublist becomes size 1


// This search can be implemented both iteratively and recursively as shown below in the 2 functions

bool binarySearch(std::vector<int> vector, int num)
{
    int first = 0;
    int last = vector.size() - 1;
    bool found = false;

    while (first <= last && !found)
    {
        int midpoint = (first + last)/2;
        if (vector[midpoint] == num)
        {
            found = true;
        }
        else
        {
            if (num < vector[midpoint])
            {
                last = midpoint - 1;
            }
            else 
            {
                first = midpoint + 1;
            }
        }
    }
    return(found);
}

bool binarySearchRecursive(std::vector<int> vector, int num)
{
    if (vector.size() == 0) // Base case: The list is empty
    {
        return(false);
    }
    else
    {
        int midpoint = vector.size() / 2;
        if (vector[midpoint] == num)
        {
            return(true);
        }
        else
        {
            if (num < vector[midpoint])
            {
                return(binarySearch(std::vector<int>(vector.begin(), vector.begin() + midpoint), num)); // Recursively search on the lower half
            }
            else
            {
                return(binarySearch(std::vector<int>(vector.begin() + midpoint + 1, vector.end()), num)); // Recursively search on the upper half
            }
        }
    }
}


int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13};
    std::vector<int> vec(std::begin(arr), std::end(arr));

    for (auto n : vec)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i <= 13; ++i)
    {
        std::cout << "Is " << i << " in the vector?: " << binarySearch(vec, i) << std::endl;
        std::cout << "Is " << i << " in the vector? (Recur): " << binarySearchRecursive(vec, i) << std::endl;
    }
    
    return(0);
}