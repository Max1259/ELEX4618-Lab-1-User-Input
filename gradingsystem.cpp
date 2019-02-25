#include "pch.h"
#include "gradingsystem.h"
#include <iostream>
#include <iomanip>

using namespace std;

int number_of_students = 0; //variable to keep track of how many students have been added

struct grade { //struct to hold student number and grades for each student 

	char student_number[9];
	float lab_grade, quiz_grade, midterm_grade, final_exam_grade;

} student_index[100]; //array to hold all students

////////////////////////////////////////////////////////////////////
//final grade calc
//arguments: int n for the student whose grades are being calculated
//return: float final grade
////////////////////////////////////////////////////////////////////
float final_grade(int n) {

	return ((student_index[n].lab_grade * 0.4) + (student_index[n].quiz_grade * 0.1)
		+ (student_index[n].midterm_grade * 0.2) + (student_index[n].final_exam_grade * 0.3));
}

////////////////////////////////////////////////////////
//print menu function
//no arguments or return types
///////////////////////////////////////////////////////
void print_menu() {

	cout<< "************************************" << endl
		<< "ELEX 4618 Grade System, by Max Horie" << endl
		<< "************************************" << endl
		<< "(A)dd student\n(E)dit student\n(P)rint grades\n(Q)uit\n\n";
}

//////////////////////////////////////////////////////
//add student function
//no arguments or return types
//////////////////////////////////////////////////////
void add_student() {

	++number_of_students;
	edit_student(number_of_students);
}

/////////////////////////////////////////////////////
//edit student funtion
//no arguments or return types
/////////////////////////////////////////////////////
void edit_student(int student_edit) {

	if (number_of_students == 0) {

		cout << "No students to edit\n" << endl;
	}

	cout << "Student Number: ";
	cin >> student_index[student_edit - 1].student_number;
	cout << "Lab Grade: ";
	cin >> student_index[student_edit - 1].lab_grade;
	cout << "Quiz Grade: ";
	cin >> student_index[student_edit - 1].quiz_grade;
	cout << "Midterm Grade: ";
	cin >> student_index[student_edit - 1].midterm_grade;
	cout << "Final Exam Grade: ";
	cin >> student_index[student_edit - 1].final_exam_grade;
	cout << endl;

}

//////////////////////////////////////////////////
//print grades function
//no arguments or return types
/////////////////////////////////////////////////
void print_grades() {

	cout<< setw(3) << left << "#" << setw(12) << left << "Student"
		<< setw(8) << left << "Lab" << setw(10) << left << "Quiz"
		<< setw(10) << left << "Midterm" << setw(15) << left << "Final Exam"
		<< setw(10) << left << "Final Grade" << endl;

	for (int i = 0; i < number_of_students; i++) {

		cout<< setw(3) << left << i + 1 << setw(12) << left << student_index[i].student_number;

		cout.precision(2);

		cout<< fixed << setw(8) << left << student_index[i].lab_grade
			<< setw(10) << left << student_index[i].quiz_grade
			<< setw(10) << left << student_index[i].midterm_grade
			<< setw(15) << left << student_index[i].final_exam_grade
			<< setw(10) << left << final_grade(i) << endl;
	}

	cout << endl;
}