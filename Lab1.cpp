//////////////////////////////////////////////////////////
//Max Horie (A01010912)
//ELEX 4618 Lab 1: Simple grading program with user input
//created: 12/30/18
//////////////////////////////////////////////////////////

#include "pch.h"
#include "gradingsystem.h"
#include <iostream>
#include <iomanip> 

using namespace std;

int main() {

	char command; //for add/edit/print/quit menu commands
	int num;//to choose which student to edit

	while (1) {

		print_menu();
		cin >> command;
		cout << endl;

		switch (command) {

			case 'A':
			case 'a': add_student();
			break;

			case 'E':
			case 'e':
				cout << "Student to edit: ";
				cin >> num;
				edit_student(num);
			break;

			case 'P':
			case 'p': print_grades();
			break;

			case 'Q':
			case 'q': return 0;
			break;

			default: cout << "Command unknown\n";
		}
		cout << endl;
	}
	return 0;
}


