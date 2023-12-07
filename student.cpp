#include <iostream>
#include <string>
#include "student.h"
using namespace std;

Student::Student()	//default constructor
{
	studentId = "";
	firstname = "";
	lastname = "";
	email = "";
	age = 0;
	for (int i = 0; i < arraySize; ++i) {
		days[i] = 0;
	}
	degreeProgram = DegreeProgram::SECURITY;
}
Student::Student(string studentId, string firstname, string lastname, string email, int age, int days[], DegreeProgram degreeProgram)
{
	this->studentId = studentId;
	this->firstname = firstname;
	this->lastname = lastname;
	this->email = email;
	this->age = age;
	//FIXME: get days from days array using for loop
	/*this->days = days;*/
	setDays(days);
	this->degreeProgram = degreeProgram;
}
string Student::getStudentId()
{
	return studentId;
}
string Student::getFirstName()
{
	return firstname;
}
string Student::getLastName()
{
	return lastname;
}
string Student::getEmail()
{
	return email;
}
int Student::getAge()
{
	return age;
}
int* Student::getDays()
{
	return days;
}
DegreeProgram Student::getDegreeProgram() { return degreeProgram; }

void Student::setStudentId(string studentId) { this->studentId = studentId; }
void Student::setFirstName(string firstname) { this->firstname = firstname; }
void Student::setLastName(string lastname) { this->lastname = lastname; }
void Student::setEmail(string email) { this->email = email; }
void Student::setAge(int age) { this->age = age; }

//FIXME: Use for loop to set days individually
//void Student::setDays(int days[]) {this->days[] = days[]; }
void Student::setDays(int days[]) {
	this->days = new int[arraySize];
	for (int i = 0; i < arraySize; ++i) {
		this->days[i] = days[i];
	}
}

void Student::setDegreeProgram(DegreeProgram degreeProgam) { this->degreeProgram = degreeProgam; }

void Student::print()
{
	cout << getStudentId() << '\t';
	cout << getFirstName() << '\t';
	cout << getLastName() << '\t';
	cout << getEmail() << '\t';
	cout << getAge() << '\t';
	/*cout << getDays()[0] << '\t';
	cout << getDays()[1] << '\t';
	cout << getDays()[2] << '\t';*/
	int* days = getDays();
	for (int i = 0; i < arraySize; ++i) {
		cout << days[i] << " ";
	}
	string degreeString = "";
	switch (getDegreeProgram()) {
	case DegreeProgram::SECURITY:
		degreeString = "SECURITY";
		break;
	case DegreeProgram::NETWORK:
		degreeString = "NETWORK";
		break;
	case DegreeProgram::SOFTWARE:
		degreeString = "SOFTWARE";
		break;
	}
	cout << "\t" << degreeString << endl;
}
Student::~Student() {}
