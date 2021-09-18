// Write a program that will keep track of grades for several students at once. 
// The program could keep two vectors in sync: 
//     The first should hold the student's names,
//     and the second the final grades that can be computed as input is read. 
// For now, you should assume a fixed number of homework grades. 
// We'll see in §4.1.3/56 how to handle a variable number of grades intermixed with student names.

#include <iostream>
#include <vector>
#include <string>

//Enter name
//Store name in first vector
//Enter X homework grades for each student 
//Store grade in second vector
//Compute Final grade

std::string GetName()
{

    std::cout<<"Please enter Students name: " << std::endl;

    std::string students;
    std::cin >> students;

    return students;

}

std::vector<double> GetGrades()
{
    
    std::cout<<"Please enter 5 homework grades. Enter ';' when finished: " << std::endl;

    std::vector<double> grades;

    double x;

    while (std::cin >> x)
        {
            grades.push_back(x);
        }

    return grades;

}

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

bool MoreStudents()
{
    
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

int main()
{

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
        std::cout<<final_grade<<std::endl;
        grade_list.push_back(final_grade);        

        more_students = MoreStudents();
        
    }

    for(std::string name : students_list)
    {

        std::cout<<name;

    }

    std::cout<<std::endl;

    for(double grade : grade_list)
    {

        std::cout<<grade;

    }
    std::cout<<std::endl;
    

}