#pragma once
#include "student.h"


class Roster {
private:
	//declare local variable for studentData
	int lastIndex = -1;
	
public:
	const static int numStudents = 5;
	//array of pointer
	Student* classRosterArray[numStudents];
	//parse method
	void parse(string student);
	//add function
	void add(string studentId, string fName, string lName, string email, int age,
			int days1, int days2, int days3, DegreeProgram degreeProgram);
	void remove(string studentId);
	void printAll();
	void printAverageDaysInCourse(string studentId);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);

	~Roster();
};

//FIXME: change to const static variable
//int Roster::studentData = 5;

//E2. Create a student object for each student in the data table and populate in the "studentData Table"
//a. parse each set of data identified in the studentData Table