#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>


void number1(int num_elements) 
{
    // 1. Verify that the vector index operator is O(1)
    std::vector<int> vec;
    for (int i = 0; i < num_elements; ++i)
        vec.push_back(i);
    
    clock_t begin_t1 = clock();
    std::cout << vec[500] << std::endl;
    clock_t end_t1 = clock();
    double elapsed_secs = double(end_t1 - begin_t1) / CLOCKS_PER_SEC;
    std::cout << "Index took: " << elapsed_secs << " seconds." << std::endl;
}

void number2(int num_elements) 
{
    // 2. Verify that find and insert are O(1) for hash tables

    // Populate the hash table
    std::unordered_map<int, int> map;
    for (int j = 0; j < num_elements; j++) 
    {
        map[j] = 30;
    }

    // Find
    // clock_t begin_t1 = clock();
    // map.find(500);
    // clock_t end_t1 = clock();
    // double elapsed_secs = double(end_t1 - begin_t1) / CLOCKS_PER_SEC;
    // std::cout << "find() took: " << elapsed_secs << " seconds." << std::endl;

    // Insert
    clock_t begin_t1 = clock();
    map.insert(std::make_pair<int, int> (40000, 2));
    clock_t end_t1 = clock();
    double elapsed_secs = double(end_t1 - begin_t1) / CLOCKS_PER_SEC;
    std::cout << "insert() took: " << elapsed_secs << " seconds." << std::endl;
}


void print_vec(std::vector<int> v) 
{
    std::cout << "The vector: ";
    for (auto e : v) 
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;

}


int main() 
{

    // Exercise 1.
    // for (int n = 1000; n <= 10000; n = n + 1000)
    //     number1(n);
    
    // Exercise 2.
    // for (int n = 1000; n <= 30000; n = n + 1000)
    //     number2(n);

    // Exercise 3.1
    // std::vector<int> vec;
    // int length = 10;
    // int k = 9;
    // for (int i = 1; i <= 10; ++i)
    //     vec.push_back((rand() % 10));
    // print_vec(vec);
    // std::sort(vec.begin(), vec.end()); // Sort takes n*log(n)
    // print_vec(vec);
    // std::cout << "kth(" << k << ") smallest element is: " << vec[k-1] << std::endl;

    // Exercise 3.2
    std::vector<int> vec;
    int length = 10;
    int k = 9;
    for (int i = 1; i <= 10; ++i)
        vec.push_back((rand() % 10));
    print_vec(vec);

    

    return(0);
}