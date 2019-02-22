/* Write a program that will calculate the avarage grade of a student and print the summary raport
 * 1.A student may sign up for any number of courses;
 * 2.During a course, the student may receive any number of grades;
 * 3.Grades are integer numbers in the range [1..5]
 * 4.The final grade for a course is the arithmetic mean of all grades received during the course;
 * 5.The overall final grade, is the arithmetic mean, of the final grades received from all 
 *the courses the student has taken;
 */

#include <iostream>
#include <iomanip>

int main(void)
{
	int **student_grades, courses, grades_no;
	float final_grade = 0;

	std::cout << "How many courses did the student take: ";
	std::cin >> courses;
	student_grades = new int*[courses];

	for(int i = 0; i < courses; i++)
	{
		std::cout << "Enter the number of grades for course nr." << i+1 << ": ";
		std::cin >> grades_no;
		student_grades[i] = new int[grades_no + 1];
		student_grades[i][0] = grades_no;
		for(int j = 1; j < grades_no + 1; j++)
		{
			std::cout << "a[" << i << "][" << j << "]= ";
			std::cin >> student_grades[i][j];
		}
	}

	for(int i = 0; i < courses; i++)
	{
		float avarage = 0;
		for(int j = 1; j < student_grades[i][0] + 1; j++)
		{
			avarage += student_grades[i][j];
		}
		avarage = (float)avarage / student_grades[i][0];
		final_grade += avarage;

		std::cout << std::fixed << std::setprecision(2) << "Course " << i+1 << ": final " << avarage << ", grades: "; 

		for(int j = 1; j < student_grades[i][0] + 1; j++)
		{
			std::cout << student_grades[i][j] << " ";
		}
		std::cout << std::endl;
		
	}
	
	std::cout << "Overall final " << (float)final_grade / courses << std::endl;

	return 0;
}