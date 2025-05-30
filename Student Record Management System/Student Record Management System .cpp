

// the fainal project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include<string>
#include<cctype>
#include "the fainal project.h"

using namespace std;
//strucct to represent studen recrd

struct student
{
	int id;
	string first_name;
	string last_name;
	string major;
	int level;
	int marks[6];
	const int size = 6;
	int total_marks;
	float gtrade;

};
//function to caitalize hte first later of a string
void capitalize(string& str)
{
	str[0] = toupper(str[0]);
}
//function  to add new student record
void addStudent(student students[], int& count)
{
	cout << "Enter student id:";
	cin >> students[count].id;

	cout << "Enter student first name:";
	cin >> students[count].first_name;
	capitalize(students[count].first_name);

	cout << "Enter student last name :";
	cin >> students[count].last_name;
	capitalize(students[count].last_name);


	cout << "Enter student major (IT,IS,CS,CYS:";
	cin >> students[count].major;
	capitalize(students[count].major);


	cout << "Enter student level (1_4):";
	cin >> students[count].level;

	cout << "Enter student marks for each subject(6subjects):" << endl;
	students[count].total_marks = 0;
	for (int i = 0; i < students[count].size; i++)
	{
		cout << "subject" << i + 1 << "";
		cin >> students[count].marks[i];
		students[count].total_marks += students[count].marks[i];

	}
	students[count].gtrade = static_cast<float>(students[count].total_marks) / students[count].size;

	count++;

}

//function to edit an existimf student recird
void editStudent(student students[], int count)
{
	int id;
	cout << "Enter the ID of student to edit : ";
	cin >> id;

	int index = -1;
	for (int i = 0; i < count; i++)
	{
		if (students[i].id == id) {
			index = i;
			break;
		}
	
	}
	if (index == -1) 
	{
		cout << "student not found." << endl;
		return;
	}
	cout << "Enter new student first name :";
	cin >> students[index].first_name;
	capitalize(students[index].first_name);

	cout << "Enter new student last name :";
	cin >> students[index].last_name ;
	capitalize(students[index].last_name);

	cout << "Enter new student major (IT,IS,CS,CYS) :";
	cin >> students[index].major;
	capitalize(students[index].major);

	cout << "Enter neew student level(1_4): ";
	cin >> students[index].level;

	cout << "Enter new student marks for each subects(6subjects) :" << endl;
	cin >> students[index].total_marks=0;
	
	for (int i = 0; i < students[index].size; i++)
	{
		cout << "subject" << i + 1 << "";
;
	}
	cin >> students[index].marks[i];
	students[index].total_marks += students[index].marks[i];

	students[index].gtrade = static_cast<float>(students[index].total_marks) / students[index].size;

	cout << "student record update successfully ." << endl;


}

//function to delete an existing student record
void deleteStudent(student students[], int& count)
{
	int id;
	cout << "Enter the ID of student to delete : ";
	cin >> id;
	int index = -1;
	for (int i = 0; i < count; i++)
	{
		if (students[i].id == id) {
			index = i;
			break;
		}

	}
	if (index == -1)
	{
		cout << "student not found." << endl;
		return;
	}
	//shift elements to the left to overwrite the deleted record
	for (int i = index; i < count - 1; i++)
	{
		students[i] = students[i + 1];
	}
	count--;
}
//function to search for student record by ID 
void searchByID(const student students, int count)
{
	int id;
	cout << "Enter the ID of student to search for  : ";
	cin >> id;
	int index = -1;
	for (int i = 0; i < count; i++)
	{
		if (students[i].id == id) {
			index = i;
			break;
		}

	}
	if (index == -1)
	{
		cout << "student not found." << endl;
		return;
	}
	const student& student = students[index];
	cout << "student ID :" << student.id << endl;
	cout << "student name  :" << student.first_name << "" << student.last_name << endl;
	cout << "student major :" << student.major << endl;
	cout << "student level  :" << student.level << endl;
	cout << "student marks :" << endl;
	for (int i = 0; i < student.size; i++)
	{
		cout << "subject" << i + 1 << "" << student.marks[i] << endl;
	}
	cout << "total of marks :" << student.total_marks << endl;
	cout << "grade :" << student.gtrade << endl;
}
//functaion to display all student records
void displayRecords(const student students[], int count)
{
	if (count == 0)
	{
		cout << "no student records found ." << endl;
		return;
	}
	cout << "student records :" << endl;
	for (int i = 0; i < count; i++)
	{
		const student& student = students[i];
		cout << "student ID :" << student.id << endl;
		cout << "student name" << student.first_name << "" << student.last_name << endl;
		cout << "student major :" << student.major << endl;
		cout << "student level: " << student.level << endl;
		cout << "tsudent marks: " << endl;
		for (int j = 0; j < student.size; j++)
		{
			cout << "subject" << j + 1 << ": " << student.marks[j] << endl;
		}
		cout << "total marks :" << student.total_marks << endl;
		cout << "grade :" << student.gtrade << endl;
		cout << endl;

	}
}
//function to save student recordsmtoma file
void saveTofile(const student students[], int count)
{
	string filename;
	cout << "Enter the file name ti save the records to : ";
	cin >> filename;

	ofstream file(filename);

	if (!file)
	{
		cout << "Error opening file." << endl;
		return;
	}
	for (int i = 0; i < count; i++)
	{
		const student& student = students[i];
		file << "student ID:" << student.id << endl;
		file<< " student name:" << student.first_name << "" << student.last_name << endl;
		file << "tsudent major:" << student.major << endl;
		file << "student level:" << student.level << endl;
		file << "student marks :" << endl;
		for (int j = 0; j < student.size; j++)
		{
			file << "subject :" << j + 1 << ":" << student.marks[j] << endl;

		}
		file << "total marks:" << student.total_marks << endl;
		file << "grade: " << student.gtrade << endl;
		file << endl;
	
	}

	file.close();
	cout << " student records saved to file successfully :" << endl;
}
//function to load student records from a file
void loadFromfile(student students[], int& count)
{
	string filename;
	cout << "Enter the file name to lod the records from : ";
	cin >> filename;

	ifstream file(filename);

	if (!file)
	{
		cout << "Error opening file." << endl;
		return;
	}
	count = 0;
	string line;
	while (getline(file, line)) 
	{
		if (line.find("student ID:") != string::npos)
		{
			student& student = students[count];
			file >> student.id;
			file.ignore();
			getline(file, line);
			student.first_name = line.substr(line.find(":") + 2);
			getline(file, line);
			student.last_name = line.substr(line.find(":") + 2);
			getline(file, line);
			student.major = line.substr(line.find(":") + 2);
			getline(file, line);
			student.level = stoi(line.substr(line.find(":") + 2));
			for (int i = 0; i < student.size; i++)
			{
				getline(file.line);
				student.marks[i] = stoi(line.substr(line.find(": ") + 2));
				student.total_marks += student.marks[i];

				student.gtrade = static_cast<float>(student.total_marks) / student.size;

				count++;
			}

		}
		file.close();

		cout << "student records loaded from file successflly ." << endl;
	}
	
}
int main()
{
	const int MAX_STUDENTS = 100;
	student students[MAX_STUDENTS];
	int count = 0;
	int choice; 
	while (true)
	{
		cout << "student record mangmant system:" << endl;

		cout << "1. Add student" << endl;
		cout << "2. Eddit student" << endl;
		cout << "3. Delete student " << endl;
		cout << "4. search by ID" << endl;
		cout << "5. Display all records" << endl;
		cout << "6. save to file" << endl;
		cout << "7. load from file" << endl;
		cout << "8. Exit" << endl;
		cout << "Enter your choice (1-8)";
		cin >> choice;

		switch (choice)
		{
		case 1:
			addStudent(students, count);
			break; 
		case 2:
			editStudent(students, count);
			break;
		case 3:
			deleteStudent(students, count);
			break;
		case 4:
			searchByID(students, count);
			break;
		case 5:
			displayRecords(students, count);
			break;
		case 6:
			saveTofile(students, count);
			break;
		case 7:
			loadFromfile(students, count);
			break;
		case 8:
			cout << "Exit program Goodbye!" << endl;
			return 0;
		default:
			cout << "invalid choice pleas try again:" << endl;
			break;
		}
		cout << endl;
	}
	return 0;
}


 