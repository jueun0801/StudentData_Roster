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
	int days1 = stoi(student.substr(lhs, rhs - lhs)); 
	lhs = rhs + 1;
	rhs = student.find(",", lhs);
	int days2 = stoi(student.substr(lhs, rhs - lhs));
	lhs = rhs + 1; 
	rhs = student.find(",", lhs);
	int days3 = stoi(student.substr(lhs, rhs - lhs));

	/*lhs = rhs + 1;
	rhs = student.find(",", lhs);
	string strDegree = student.substr(lhs, rhs - lhs);

	DegreeProgram degreeProgram = SECURITY;
	if (strDegree == "SECURITY") {
		degreeProgram = SECURITY;
	}
	else if (strDegree == "NETWORK") {
		degreeProgram = NETWORK;
	}
	else if (strDegree == "SOFTWARE") {
		degreeProgram = SOFTWARE;
	}*/
	DegreeProgram degreeProgram = SECURITY;
	lhs = rhs + 1; 
	rhs = student.size()-1;
	string strDegree = student.substr(lhs, rhs - lhs);
	if (strDegree.at(strDegree.length()-1) == 'Y') {
		degreeProgram = SECURITY;
	}
	else if (strDegree.at(0) == 'N' ){
		degreeProgram = NETWORK;
	}
	else if (strDegree.at(1) == 'O') {
		degreeProgram = SOFTWARE;
	}
	
	add(studentId, fName, lName, email, age, days1, days2, days3, degreeProgram);
}
void Roster::add(string studentId, string fName, string lName, string email, int age, int days1, int days2, int days3, DegreeProgram degreeProgram)
{
	int daysArray[3] = {days1, days2, days3};
	classRosterArray[++lastIndex] = new Student(studentId, fName, lName, email, age, daysArray, degreeProgram);
}
void Roster::remove(string studentId) {
//	/*bool found = false;
//	int i;
//	for (i = 0, i <= Roster::lastIndex; ++i;) {
//		if (classRosterArray[i]->getStudentId() == studentId) {
//			found = true;
//			if (i < numStudents -1) {
//				Student* temp = classRosterArray[i];
//				classRosterArray[i] = classRosterArray[numStudents - 1];
//				classRosterArray[numStudents - 1] = temp;
//			}
//			Roster::lastIndex--;
//		}
//	}
//	if (found) {
//		cout << studentId << "removed." << endl;
//
//	}
//	else {
//		cout << "Error. " << studentId << " not found." << endl;
//	}*/
	cout << "Removing: " << studentId << endl;
	for (int i = 0; i < numStudents; ++i) {
		if (classRosterArray[i] == nullptr) {
			cout << "Record not found" << endl;
			break;
		}
		else if (studentId == classRosterArray[i]->getStudentId()) {
			classRosterArray[i] = nullptr;
			cout << "Student removed." << endl;
		}
	}
}
void Roster::printAll() {
	/*for (int i = 0; i <= Roster::lastIndex; ++i) {
		cout << classRosterArray[i]->getStudentId() << '\t';
		cout << classRosterArray[i]->getFirstName() << '\t';
		cout << classRosterArray[i]->getLastName() << '\t';
		cout << classRosterArray[i]->getEmail() << '\t';
		cout << classRosterArray[i]->getAge() << '\t';
		cout << classRosterArray[i]->getDays()[0] << '\t';
		cout << classRosterArray[i]->getDays()[1] << '\t';
		cout << classRosterArray[i]->getDays()[2] << '\t';
		cout << degreeProgramStr[classRosterArray[i]->getDegreeProgram()] << endl;
	}*/
	for (int i = 0; i <= Roster::lastIndex; ++i) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		}
	}
}
void Roster::printAverageDaysInCourse(string studentId) {
	for (int i = 0; i <= Roster::lastIndex;++i) {
		if (classRosterArray[i]->getStudentId() == studentId) {
			int average = (classRosterArray[i]->getDays()[0] + classRosterArray[i]->getDays()[1] + classRosterArray[i]->getDays()[2]) / 3;
			cout << studentId << " average days in course: " << average << endl;
		}
	}
}
void Roster::printInvalidEmails() {
	
	for (int i = 0; i <= Roster::lastIndex; ++i) {
		bool invalidAt = false;
		bool invalidPeriod = false;
		bool invalidSpace = false;
		string email = classRosterArray[i]->getEmail();
		for (char &charIndex : email) {
			if (charIndex == '@') {
				invalidAt = true;
			}
			if (charIndex == '.') {
				invalidPeriod = true;
			}
			if (charIndex == ' ') {
				invalidSpace = true;
			}
		}
		if (invalidAt == false || invalidPeriod == false || invalidSpace == true ) {
			cout << classRosterArray[i]->getEmail() << endl;
		}
	}
}
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	cout << "Showing students in degree program: " << endl;
	for (int i = 0; i <= Roster::lastIndex; ++i) {
		if (degreeProgram == classRosterArray[i]->getDegreeProgram()) {
			classRosterArray[i]->print(); 
			
		}
	}
}
Roster::~Roster() {}