// GordonEmpClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Jaylen Gordon
//Programming Assignment #13
//Program Name: GordonEmpClass
//Short Program Description: Employee class
//June 6th, 2020


#include <iostream>

using namespace std;
#include <iomanip>
#include <string>
using namespace std;
// Employee Class Declaration
class Employee
{
private:
	string name; // Employee's name
	int idNumber; // ID number
	string department; // Department name
	string position; // Employee's position
public:
	Employee(string x, int y, string a, string p);
	Employee();
	Employee(string x, int y);
	
	string getdepartment() {
		return department;
	}
	string getname() {
		return name;
	}

	int getidNumber() {
		return idNumber;
	}

	string getposition() {
		return position;
	}
	void setdepartment(string a) {
		department = a;
	}

	void setposition(string a) {
		position = a;
	}
	void setname(string a) {
		name = a;
	}
	void setidNumber(int a) {
		idNumber = a;
	}
};
// Constructor #1
Employee::Employee(string x, int y, string a, string b)
{
	name = x;
	idNumber = y;
	department = a;
	position = b;

	
}
// Constructor #2
Employee::Employee(string x, int y)
{
	
	name = x;
	idNumber = y;

}
// Constructor #3, default constructor
Employee::Employee()
{
	name = "";
	idNumber = 0;
	department = "";
	position = "";
	
}
// Function test
void displayEmployee(Employee);

int main()
{


	Employee e1("Susan Mayers", 47899, "Accounting", "Vice President");
	Employee e2("Mark Jones", 39119, "IT", "Programmer");
	Employee e3("Joy Rogers", 81774, "Manufacturing", "Engineer");

	// Displaying each employee's data.

	cout << setw(10) << "                Name           Id_Number          Department             Position" << endl;
	cout << endl;
	Employee employee[] = { e1, e2, e3 };
	displayEmployee(employee[0]);
	displayEmployee(employee[1]);
	displayEmployee(employee[2]);

	return 0;
}

void displayEmployee(Employee e)
{
	cout << setw(20) << e.getname() << setw(20) << e.getidNumber() << setw(20) << e.getdepartment() << " " << setw(20) << e.getposition() << endl;
	

}


