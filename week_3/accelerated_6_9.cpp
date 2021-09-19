// Use a library algorithm to concatenate all the elements of a vector<string>.

#include <iostream>
#include <numeric>
#include <string>
#include <vector>

std::string Concatenate(std::vector<std::string> vec)
{

    std::string new_str = std::accumulate(vec.begin(), vec.end(), std::string(""));

    return new_str;

}

int main()
{

    std::vector<std::string> test = 
    Concatenate(test)

}