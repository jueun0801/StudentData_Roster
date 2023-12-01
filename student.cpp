#include <iostream>
#include <string>
#include "student.h"
using namespace std;

Student::Student()	//default constructor
{

}
Student::Student(int studentId, string firstname, string lastname, string email, int age, int days[], DegreeProgram degreeProgram)
{
	this->studentId = studentId;
	this->firstname = firstname;
	this->lastname = lastname;
	this->email = email;
	this->age = age;
	//FIXME: get days from days array using for loop
	/*this->days = days;*/
	this->degreeProgram = degreeProgram;
}
int Student::getStudentId()
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

void Student::setStudentId(int studentId) { this->studentId = studentId; }
void Student::setFirstName(string firstname) { this->firstname = firstname; }
void Student::setLastName(string lastname) { this->lastname = lastname; }
void Student::setEmail(string email) { this->email = email; }
void Student::setAge(int age) { this->age = age; }

//FIXME: Use for loop to set days individually
//void Student::setDays(int days[]) {this->days[] = days[]; }

void Student::setDegreeProgram(DegreeProgram degreeProgam) { this->degreeProgram = degreeProgam; }

void Student::print()
{
	cout << getStudentId() << '\t';
	cout << getFirstName() << '\t';
	cout << getLastName() << '\t';
	cout << getEmail() << '\t';
	cout << getAge() << '\t';
	cout << getDays() << '\t';
	cout << getDegreeProgram() << endl;
}
