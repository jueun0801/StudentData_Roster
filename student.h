#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using namespace std;

class Student {
public:
	const static int arraySize = 3;
	Student(); //default constructor;
	Student(string studentId, string firstname, string lastname, string email, int age, int days[], DegreeProgram degreeProgram);
	~Student(); //Destructor

	string getStudentId();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDays();
	DegreeProgram getDegreeProgram();

	void setStudentId(string studentId);
	void setFirstName(string firstname);
	void setLastName(string lastname);
	void setEmail(string email);
	void setAge(int age);
	void setDays(int days[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	void print();

private: 
	string studentId;
	string firstname;
	string lastname;
	string email;
	int age;

	//const static int arraySize = 3;
	/*int days[arraySize];*/ //array of number of days to complete each course
	int* days;
	DegreeProgram degreeProgram;
};