// Write a program to calculate the average of the numbers stored in a vector<double>.

#include <iostream>
#include <vector>

/**
 * @brief Computes the average of the vector num_list. 
 * 
 * @param num_list List of the students homework grades.
 * @return double Final grade percentage.
 */
double NumAvg(std::vector<double> num_list)
{

    double total = 0;

    for(double num : num_list)
    {
        total += num;
    }

    int size = num_list.size();

    double avg = total / size;

    return avg;

}

int main()
{

    std::vector<double> test = {1, 2, 3, 4, 5};
    double ans = NumAvg(test);

    std::cout<<"The average is: " << ans << std::endl;

}