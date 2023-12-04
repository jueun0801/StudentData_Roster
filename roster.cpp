#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

//REFERENCE:
//"A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY"
//find(item, index) | substr(index, length)

//parse function definition
void Roster::parse(string student) {
	//size_t is the unsigned integer data type
	size_t rhs = student.find(","); //find the comma to set it as the value of right hand side for substr
	string studentId = student.substr(0, rhs);//get substr starting at index 0 to rhs value from above.

	size_t lhs = rhs + 1; //left hand side set to above rhs plus one index to move past previos comma
	rhs = student.find(",", lhs); //find comma starting at index lhs
	string fName = student.substr(lhs, rhs - lhs); //get substr fname at index lhs having rhs-lhs length chars
	
	lhs = rhs + 1;
	rhs = student.find(",", lhs);
	string lName = student.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = student.find(",", lhs);
	string email = student.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = student.find(",", lhs);
	int age = stoi(student.substr(lhs, rhs - lhs)); //string to integer

	lhs = rhs + 1;
	rhs = student.find(",", lhs);
	double days1 = stod(student.substr(lhs, rhs - lhs)); //string to double
	lhs = rhs + 1;
	rhs = student.find(",", lhs);
	double days2 = stod(student.substr(lhs, rhs - lhs));
	lhs = rhs + 1; 
	rhs = student.find(",", lhs);
	double days3 = stod(student.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = student.find(",", lhs);
	string strDegree = student.substr(lhs, rhs - lhs);

	DegreeProgram degreeProgram = DegreeProgram::SECURITY;
	if (strDegree == "SECURITY") {
		strDegree = DegreeProgram::SECURITY;
	}
	else if (strDegree == "NETWORK") {
		strDegree = DegreeProgram::NETWORK;
	}
	else if (strDegree == "SOFTWARE") {
		strDegree = DegreeProgram::SOFTWARE;
	}
	
}