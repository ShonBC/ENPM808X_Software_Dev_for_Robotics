// Write  a  class  that  supports  course  grading;  
// it  contains  an  array  where each  student  is  
// identified  by  an  integer  and  has  a  course  grade.  
// There is also a method that can change the student grade 
// and a method that computes the grade point average for the class.

#include <iostream>
#include <array>

/**
 * @brief Class to track 10 students grades and their average GPA.
 * 
 */
class Course
{
    
public:

    std::array<int, 10> grades_ = {};
    std::array<int, 10> students_ = {};

public:
    
    /**
     * @brief Change the student's grade to a new grade.
     * 
     * @param student Integer value to indicate witch student's grade to change.
     * @param new_grade New grade value.
     */
    void ChangeGrade(int student, int new_grade)
    {

        grades_[student] = new_grade;

    }

    /**
     * @brief Compute the class average GPA.
     * 
     * @return double the average GPA
     */
    double ClassAvg()
    {

        double total = 0;

        for(double grade : grades_)
        {
            total += grade;
        }

        double avg = total / grades_.size();

        return avg;

    }

};

int main()
{

    Course test;
    test.ChangeGrade(0,100);
    test.ChangeGrade(9, 50);

    for(int grade : test.grades_)
    {
        std::cout<< grade << " " <<std::endl;
    }  
    
    std::cout<< "The Class Average is " << test.ClassAvg() << "%" <<std::endl;

}