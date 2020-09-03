#include <iostream>
#include <vector>


// 2. Write a recursive function to reverse a list


std::vector<int> revIntList(std::vector<int> vec)
{
    // Base case: A single element list reversed is itself
    if (vec.size() == 1)
    {
        return(vec);
    }
    else
    {
        std::vector<int> output;
        output.push_back(vec[vec.size() - 1]); // Create a list of just the last element
        vec.pop_back();
        vec = revIntList(vec); // Recursive call on the remaining list members
        output.insert(output.end(), vec.begin(), vec.end()); // Append to the last element the result of the recursive call
        return(output);
    }

}


int main()
{
    int numarr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 23};
    std::vector<int> nums(std::begin(numarr), std::end(numarr));

    for (auto n:nums)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    std::vector<int> rev_nums = revIntList(nums);

    for (auto n:rev_nums)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return(0);
}