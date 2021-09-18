// Write a program that will keep track of grades for several students at once. 
// The program could keep two vectors in sync: 
//     The first should hold the student's names,
//     and the second the final grades that can be computed as input is read. 
// For now, you should assume a fixed number of homework grades. 
// We'll see in §4.1.3/56 how to handle a variable number of grades intermixed with student names.

#include <iostream>
#include <vector>
#include <string>
#include <limits>

/**
 * @brief Get the Name object. Asks user for name of student.
 * 
 * @return std::string Returns the student name.
 */
std::string GetName()
{

    std::cout<<"Please enter Students name: " << std::endl;

    std::string students;
    std::cin >> students;

    return students;

}

/**
 * @brief Get the Grades object. Asks user for homework grades. 
 * 
 * @return std::vector<double> Returns a vector containing all the input grades.
 */
std::vector<double> GetGrades()
{
    
    std::cout<<"Please enter 5 homework grades. Enter 'f' when finished: " << std::endl;

    std::vector<double> grades;

    double x;

    while (true)
        {
            std::cin >> x;
            if (!x)
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.clear(); 
                break;
            }
            else
            {
                grades.push_back(x);
            }
            
        }

    return grades;

}

/**
 * @brief Computes the average of the vector g_list. 
 * 
 * @param g_list List of the students homework grades.
 * @return double Final grade percentage.
 */
double FinalGrade(std::vector<double> g_list)
{

    double total = 0;

    for(double grade : g_list)
    {
        total += grade;
    }

    int size = g_list.size();

    double final_grade = total / size;

    return final_grade;

}

/**
 * @brief Asks user if there are more students to enter.
 * 
 * @return true If there are more students to enter.
 * @return false If the user is done entering students information.
 */
bool MoreStudents()
{

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear(); 
    std::cout<<"Would you like to enter another students grades? (Y or N)"<<std::endl;
    std::string decision = "";
    
    std::cin>> decision;

    if (decision == "Y")
    {

        return true;   

    }
    else
    {

        return false;
        
    }

}

/**
 * @brief Prints the items stored in the vector passed regardless of the datatype stored.
 * 
 * @tparam T 
 * @param vec 
 */
template<typename T>
void PrintVec(std::vector<T> vec)
{

    for(T item : vec)
    {

        std::cout<<item<< " ";

    }

    std::cout<<std::endl;

} 

int main()
{

    //Initialize student and grade vectors
    std::vector<std::string> students_list;
    std::vector<double> grade_list;
    
    bool more_students = true;

    while(more_students)
    {

        //Store Students Name in vector.  
        std::string name = "";
        name = GetName();
        students_list.push_back(name);

        //Store homework grades in a vector.
        std::vector<double> homework_grades;
        homework_grades = GetGrades();

        //Compute final grade and store it in the grade list.
        double final_grade = FinalGrade(homework_grades);
        grade_list.push_back(final_grade);       

        more_students = MoreStudents();
        
    }

    PrintVec(students_list);
    PrintVec(grade_list);
    
}