#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

int main() {
	int i;
	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Jueun,Yeon,jyeon@wgu.edu,26,5,30,50,SOFTWARE"
	};
	cout << "C867 - Scripting & Programming: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: " << endl;
	cout << "Name: Jueun Yeon" << endl;
	cout << endl;
	/*Roster student;
	const int students = 5;
	for (i = 0; i < students; ++i) {
		student.parse(studentData[i]);
	}
	student.printAll();*/

	Roster classRoster;

	const int students = 5;
	for (i = 0; i < students; ++i) {
		classRoster.parse(studentData[i]);
	}
	classRoster.printAll();
	cout << endl;

	cout << "Invalid email adddresses: " << endl;
	classRoster.printInvalidEmails();
	cout << endl;

	cout << "Average days in course by student: " << endl;
	for (i = 0; i < students; ++i) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentId());
	}
	
	cout << endl;
	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
	cout << endl;
	classRoster.remove("A3");
	cout << endl;
	classRoster.printAll();
	cout << endl;
	classRoster.remove("A3");

	classRoster.~Roster();
}