#pragma once
#include "student.h"


class Roster {
private:
	//declare local variable for studentData
	const static int studentData = 5;
	//array of pointer
	Student* classRosterArray[studentData];
public:
	//parse method
	void parse(string student);

};

//FIXME: change to const static variable
//int Roster::studentData = 5;

//E2. Create a student object for each student in the data table and populate in the "studentData Table"
//a. parse each set of data identified in the studentData Table