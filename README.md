# Student Record Management System in C++

## Description
This is a simple console-based **Student Record Management System** developed in **C++**. It allows users to manage student data including:

- Adding new student records
- Editing existing records
- Deleting records by ID
- Searching for a student by ID
- Displaying all student records
- Saving records to a file
- Loading records from a file

Each student record contains:
- Student ID
- First and last name
- Major (IT, IS, CS, or CYS)
- Academic level (1 to 4)
- Marks for 6 subjects
- Total marks and calculated grade

## Features
- CLI-based interface for easy interaction
- Automatically calculates total marks and average grade
- File I/O support for persistent data storage
- Input validation and structured code design

## Technologies Used
- C++ (Standard Library)
- File handling using fstream
- Basic object-oriented design with structs

## How to Run
1. Make sure you have a C++ compiler (like g++) installed.
2. Compile the program using:
   ```bash
   g++ -o student_manager "the fainal project.cpp"
