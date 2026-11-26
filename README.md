<div align="center">

# Student Record Management System

**A menu-driven student record management system written in C**

![Language](https://img.shields.io/badge/Language-C-blue)
![Interface](https://img.shields.io/badge/Interface-Console-lightgrey)
![Data Structure](https://img.shields.io/badge/Data_Structure-Singly_Linked_List-informational)

</div>

---

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Student Information](#student-information)
- [Technical Details](#technical-details)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Data Storage](#data-storage)
- [Limitations](#limitations)
- [Future Improvements](#future-improvements)
- [Author](#author)

---

## Overview

Student Record Management System is a console-based application written in C. It allows users to add, view, search, update, and delete student records.

The program stores records in a singly linked list while it is running and uses file handling to load saved records from `students.txt` when it starts. Users can save the current records to that file through the program menu.

## Features

- Add a new student record
- View all student records
- Search for a student using the form number
- Update a student's details
- Delete a student record using the form number
- Load previously saved records when the program starts
- Save records to `students.txt`

## Student Information

Each student record contains:

| Field | Description |
|---|---|
| Form No. | Student's form number / record ID |
| Name | Student's name |
| Father's Name | Name of the student's father |
| Mother's Name | Name of the student's mother |
| DOB | Date of birth, entered as `DD-MM-YYYY` |
| Address | Student's residential address |
| Contact | Student's contact number |

## Technical Details

| Component | Implementation |
|---|---|
| Programming language | C |
| Data structure | Singly linked list |
| Record structure | `struct student` |
| In-memory list | `HEAD` and `TAIL` pointers |
| Dynamic memory | `malloc()` and `free()` |
| File handling | Standard C file functions |
| Data file | `students.txt` |
| Record separator | Pipe character (`|`) |
| Compiler | GCC (MinGW on Windows) |

## Getting Started

### Prerequisites

- GCC C compiler (MinGW-w64 can be used on Windows)
- A terminal or command prompt

### Compile

Keep `student_record.c` in your project folder, open a terminal in that folder, and run:

```bash
gcc student_record.c -o student_record
```

### Run

**Windows (Command Prompt / PowerShell):**

```powershell
.\student_record.exe
```

**Linux / macOS:**

```bash
./student_record
```

The program creates `students.txt` if it does not already exist, then attempts to load saved records from it.

## Usage

After starting the program, choose an operation from the menu:

```text
1. Add a New Student
2. View All Records
3. Delete Student
4. Search a Student
5. Update Student
6. Save Records to File
```

Enter the requested student details or form number when prompted.

**Important:** Choose option `6` to save changes to `students.txt`. The program does not currently provide a separate exit option; stop it from the terminal when you are finished, and save your records before stopping.

## Data Storage

Student records are stored in a local text file named `students.txt`.

- At startup, the program reads records from `students.txt`.
- When option `6` is selected, the program writes the current records to the file.
- Each saved record uses the pipe character (`|`) between fields.
- The file is created in the same directory from which the program is run.

Keep `students.txt` if you want to retain your saved records between runs.

## Limitations

- Records are saved only when the **Save Records to File** menu option is selected.
- There is no CSV export feature in the current program.
- The program does not currently include a dedicated exit menu option.
- Input validation and duplicate form-number handling when adding records can be improved.

## Future Improvements

- Add stronger validation for menu choices and student input
- Add a dedicated exit option
- Improve form-number generation and deletion handling
- Add an option to export records to CSV
- Improve file-reading error handling

---

## Author

**Reyaz Ali**

- GitHub: [@reyazali-dev](https://github.com/reyazali-dev)
- Email: [reyazali.dev@gmail.com](mailto:reyazali.dev@gmail.com)
