// ==============================================
// COURSE REVIEW SYSTEM - SINGLE MAIN FUNCTION
// Using Pointers to Access Structures
// ==============================================

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// ==================== STRUCTURES ====================
struct Teacher {
    string name;
    float rating;
    int ratingCount;
    string comments[20];
    int commentCount;
    string coursesTaught[10];
    int courseCount;
};

struct Course {
    string code;
    string name;
    int year;
    int semester;
    string description;
    float difficulty;
    string instructors[3];
    int instructorCount;
    string prerequisites[5];
    int prereqCount;
};

// ==================== FUNCTION TO CONVERT YEAR NUMBER TO STRING ====================
string getYearString(int year) {
    switch(year) {
        case 2: return "2nd Year";
        case 3: return "3rd Year";
        case 4: return "4th Year";
        case 5: return "5th Year";
        default: return to_string(year) + "th Year";
    }
}

// ==================== FUNCTION TO CONVERT SEMESTER NUMBER TO STRING ====================
string getSemesterString(int semester) {
    return (semester == 1) ? "1st Semester" : "2nd Semester";
}

// ==================== FUNCTION TO FIND TEACHER BY NAME ====================
Teacher* findTeacherByName(Teacher* teachers, int teacherCount, string name) {
    for(int i = 0; i < teacherCount; i++) {
        if((teachers + i)->name == name) {
            return teachers + i;
        }
    }
    return nullptr;
}

// ==================== FUNCTION TO FIND COURSE BY CODE ====================
Course* findCourseByCode(Course* courses, int courseCount, string code) {
    for(int i = 0; i < courseCount; i++) {
        if((courses + i)->code == code) {
            return courses + i;
        }
    }
    return nullptr;
}

// ==================== FUNCTION TO ADD TEACHER TO COURSE ====================
void addTeacherToCourse(Course* course, string teacherName) {
    if(course->instructorCount < 3) {
        course->instructors[course->instructorCount] = teacherName;
        course->instructorCount++;
    }
}

// ==================== MAIN FUNCTION ====================
int main() {
    // ==================== VARIABLE DECLARATIONS ====================
    Teacher teachers[50];
    Course courses[50];
    int teacherCount = 0;
    int courseCount = 0;

    // ==================== POINTER DECLARATIONS ====================
    Teacher* teacherPtr = teachers;
    Course* coursePtr = courses;

    // ==================== LOAD DATA ====================
    ifstream tFile("teachers.dat");
    if(tFile.is_open()) {
        tFile >> teacherCount;
        tFile.ignore();

        for(int i = 0; i < teacherCount; i++) {
            getline(tFile, (teacherPtr + i)->name);
            tFile >> (teacherPtr + i)->rating;
            tFile >> (teacherPtr + i)->ratingCount;
            tFile >> (teacherPtr + i)->commentCount;
            tFile >> (teacherPtr + i)->courseCount;
            tFile.ignore();

            for(int j = 0; j < (teacherPtr + i)->commentCount; j++) {
                getline(tFile, (teacherPtr + i)->comments[j]);
            }
            
            for(int j = 0; j < (teacherPtr + i)->courseCount; j++) {
                getline(tFile, (teacherPtr + i)->coursesTaught[j]);
            }

            string dummy;
            getline(tFile, dummy);
        }
        tFile.close();
    }

    ifstream cFile("courses.dat");
    if(cFile.is_open()) {
        cFile >> courseCount;
        cFile.ignore();

        for(int i = 0; i < courseCount; i++) {
            getline(cFile, (coursePtr + i)->code);
            getline(cFile, (coursePtr + i)->name);
            cFile >> (coursePtr + i)->year;
            cFile >> (coursePtr + i)->semester;
            cFile.ignore();
            getline(cFile, (coursePtr + i)->description);
            cFile >> (coursePtr + i)->difficulty;
            cFile >> (coursePtr + i)->instructorCount;
            cFile >> (coursePtr + i)->prereqCount;
            cFile.ignore();

            for(int j = 0; j < (coursePtr + i)->instructorCount; j++) {
                getline(cFile, (coursePtr + i)->instructors[j]);
            }
            
            for(int j = 0; j < (coursePtr + i)->prereqCount; j++) {
                getline(cFile, (coursePtr + i)->prerequisites[j]);
            }

            string dummy;
            getline(cFile, dummy);
        }
        cFile.close();
    }

    // ==================== ADD SAMPLE DATA IF EMPTY ====================
    if(teacherCount == 0) {
        teacherPtr->name = "Mrs. Eleni Teshome";
        teacherPtr->rating = 4.5;
        teacherPtr->ratingCount = 10;
        teacherPtr->commentCount = 3;
        teacherPtr->courseCount = 2;
        teacherPtr->comments[0] = "Great teacher";
        teacherPtr->comments[1] = "Very helpful";
        teacherPtr->comments[2] = "Explains well";
        teacherPtr->coursesTaught[0] = "SWEG2103";
        teacherPtr->coursesTaught[1] = "SWEG2105";

        (teacherPtr + 1)->name = "Dr. John Doe";
        (teacherPtr + 1)->rating = 4.2;
        (teacherPtr + 1)->ratingCount = 8;
        (teacherPtr + 1)->commentCount = 2;
        (teacherPtr + 1)->courseCount = 2;
        (teacherPtr + 1)->comments[0] = "Knowledgeable";
        (teacherPtr + 1)->comments[1] = "Fair grader";
        (teacherPtr + 1)->coursesTaught[0] = "SWEG2103";
        (teacherPtr + 1)->coursesTaught[1] = "SWEG2106";

        (teacherPtr + 2)->name = "Mr. Abraham";
        (teacherPtr + 2)->rating = 4.8;
        (teacherPtr + 2)->ratingCount = 12;
        (teacherPtr + 2)->commentCount = 2;
        (teacherPtr + 2)->courseCount = 1;
        (teacherPtr + 2)->comments[0] = "Best teacher ever";
        (teacherPtr + 2)->comments[1] = "Very practical";
        (teacherPtr + 2)->coursesTaught[0] = "SWEG2104";

        teacherCount = 3;
    }

    if(courseCount == 0) {
        coursePtr->code = "SWEG2103";
        coursePtr->name = "Fundamentals of Programming I";
        coursePtr->year = 2;
        coursePtr->semester = 1;
        coursePtr->description = "Fundamentals of Programming I establishes the foundation for software engineering using C++. It covers programming fundamentals including SDLC, algorithm design with flowcharts/pseudocode, and programming language paradigms. Students learn C++ syntax, variables, data types, operators, expressions, and input/output operations with debugging techniques. The course includes control structures (if, switch, loops) and data handling through arrays and string manipulation. Memory management concepts cover pointers, pointer arithmetic, and dynamic allocation.";
        coursePtr->difficulty = 4.2;
        coursePtr->instructorCount = 2;
        coursePtr->prereqCount = 0;
        coursePtr->instructors[0] = "Mrs. Eleni Teshome";
        coursePtr->instructors[1] = "Dr. John Doe";

        (coursePtr + 1)->code = "SWEG2104";
        (coursePtr + 1)->name = "Data Structures";
        (coursePtr + 1)->year = 2;
        (coursePtr + 1)->semester = 2;
        (coursePtr + 1)->description = "This course covers fundamental data structures including arrays, linked lists, stacks, queues, trees, and graphs. Students learn about time and space complexity analysis, recursion, and various algorithms for searching and sorting.";
        (coursePtr + 1)->difficulty = 4.5;
        (coursePtr + 1)->instructorCount = 1;
        (coursePtr + 1)->prereqCount = 1;
        (coursePtr + 1)->prerequisites[0] = "SWEG2103";
        (coursePtr + 1)->instructors[0] = "Mr. Abraham";

        (coursePtr + 2)->code = "SWEG2105";
        (coursePtr + 2)->name = "Database Systems";
        (coursePtr + 2)->year = 3;
        (coursePtr + 2)->semester = 1;
        (coursePtr + 2)->description = "Introduction to database systems, SQL, normalization techniques, and database design principles. Covers relational algebra, transactions, concurrency control, and NoSQL databases.";
        (coursePtr + 2)->difficulty = 4.0;
        (coursePtr + 2)->instructorCount = 1;
        (coursePtr + 2)->prereqCount = 1;
        (coursePtr + 2)->prerequisites[0] = "SWEG2103";
        (coursePtr + 2)->instructors[0] = "Mrs. Eleni Teshome";

        (coursePtr + 3)->code = "SWEG2106";
        (coursePtr + 3)->name = "OOP Programming";
        (coursePtr + 3)->year = 2;
        (coursePtr + 3)->semester = 2;
        (coursePtr + 3)->description = "Object-Oriented Programming concepts including classes, objects, inheritance, polymorphism, encapsulation, and abstraction. Design patterns and software engineering principles.";
        (coursePtr + 3)->difficulty = 3.8;
        (coursePtr + 3)->instructorCount = 1;
        (coursePtr + 3)->prereqCount = 1;
        (coursePtr + 3)->prerequisites[0] = "SWEG2103";
        (coursePtr + 3)->instructors[0] = "Dr. John Doe";

        courseCount = 4;
    }

    // ==================== MAIN PROGRAM LOOP ====================
    int mainChoice;

    do {
        system("cls");
        cout << "=========================================\n";
        cout << "    COURSE REVIEW SYSTEM - AASTU\n";
        cout << "=========================================\n\n";

        cout << "1. View Course Overview\n";
        cout << "2. Instructor Rating System\n";
        cout << "3. Exit\n\n";

        cout << "Enter choice (1-3): ";
        cin >> mainChoice;

        if(mainChoice == 1) {
            int year, semester, courseChoice;

            system("cls");
            cout << "=========================================\n";
            cout << "        COURSE OVERVIEW\n";
            cout << "=========================================\n\n";

            cout << "Select Academic Year:\n";
            cout << "1. 2nd Year\n";
            cout << "2. 3rd Year\n";
            cout << "3. 4th Year\n";
            cout << "4. 5th Year\n\n";
            cout << "Enter choice (1-4): ";
            cin >> year;

            if(year < 1 || year > 4) {
                cout << "Invalid year selection!\n";
                system("pause");
                continue;
            }
            
            year = year + 1;

            cout << "\nSelect Semester:\n";
            cout << "1. 1st Semester\n";
            cout << "2. 2nd Semester\n\n";
            cout << "Enter choice (1-2): ";
            cin >> semester;

            if(semester != 1 && semester != 2) {
                cout << "Invalid semester selection!\n";
                system("pause");
                continue;
            }

            Course* availableCourses[50];
            int availableCount = 0;
            
            for(int i = 0; i < courseCount; i++) {
                Course* currentCourse = coursePtr + i;
                if(currentCourse->year == year && currentCourse->semester == semester) {
                    availableCourses[availableCount] = currentCourse;
                    availableCount++;
                }
            }

            if(availableCount == 0) {
                cout << "\nNo courses found for " << getYearString(year) 
                     << ", " << getSemesterString(semester) << ".\n";
                system("pause");
                continue;
            }

            system("cls");
            cout << "=========================================\n";
            cout << "   " << getYearString(year) << " - " << getSemesterString(semester) << "\n";
            cout << "=========================================\n\n";
            
            cout << "Available Courses:\n";
            cout << "==================\n";
            for(int i = 0; i < availableCount; i++) {
                cout << i+1 << ". " << availableCourses[i]->code << " - " 
                     << availableCourses[i]->name << "\n";
            }
            
            cout << "\n0. Back to Main Menu\n\n";
            cout << "Select a course (1-" << availableCount << "): ";
            cin >> courseChoice;
            
            if(courseChoice == 0) {
                continue;
            }
            
            if(courseChoice < 1 || courseChoice > availableCount) {
                cout << "Invalid course selection!\n";
                system("pause");
                continue;
            }

            Course* selectedCourse = availableCourses[courseChoice - 1];
            
            system("cls");
            cout << "=========================================\n";
            cout << "   COURSE DETAILS\n";
            cout << "=========================================\n\n";
            
            cout << "Course Code: " << selectedCourse->code << "\n";
            cout << "Course Name: " << selectedCourse->name << "\n";
            cout << "Year:        " << getYearString(selectedCourse->year) << "\n";
            cout << "Semester:    " << getSemesterString(selectedCourse->semester) << "\n";
            cout << "Difficulty:  " << fixed << setprecision(1) << selectedCourse->difficulty << "/5.0\n\n";
            
            // Display prerequisites as simple list
            if(selectedCourse->prereqCount > 0) {
                cout << "PREREQUISITES:\n";
                cout << "==============\n";
                for(int i = 0; i < selectedCourse->prereqCount; i++) {
                    cout << selectedCourse->prerequisites[i];
                    if(i < selectedCourse->prereqCount - 1) {
                        cout << ", ";
                    }
                }
                cout << "\n\n";
            } else {
                cout << "PREREQUISITES: None\n\n";
            }
            
            cout << "COURSE DESCRIPTION:\n";
            cout << "===================\n";
            cout << selectedCourse->description << "\n\n";
            
            cout << "INSTRUCTORS:\n";
            cout << "============\n";
            if(selectedCourse->instructorCount == 0) {
                cout << "No instructors assigned to this course yet.\n";
            } else {
                for(int j = 0; j < selectedCourse->instructorCount; j++) {
                    Teacher* teacher = findTeacherByName(teacherPtr, teacherCount, selectedCourse->instructors[j]);
                    if(teacher != nullptr) {
                        cout << teacher->name << " (Rating: " << fixed << setprecision(1) << teacher->rating << "/5.0)\n";
                    } else {
                        cout << selectedCourse->instructors[j] << "\n";
                    }
                }
            }

            cout << "\n" << string(40, '=') << "\n\n";
            system("pause");

        } else if(mainChoice == 2) {
            int instructorChoice;

            do {
                system("cls");
                cout << "=========================================\n";
                cout << "      INSTRUCTOR RATING SYSTEM\n";
                cout << "=========================================\n\n";

                cout << "1. View a Teacher\n";
                cout << "2. Rate a Teacher\n";
                cout << "3. Add New Teacher\n";
                cout << "4. Back to Main Menu\n\n";

                cout << "Enter choice (1-4): ";
                cin >> instructorChoice;

                if(instructorChoice == 1) {
                    // VIEW A TEACHER (with comments)
                    system("cls");
                    cout << "=========================================\n";
                    cout << "       VIEW A TEACHER\n";
                    cout << "=========================================\n\n";
                    
                    if(courseCount == 0) {
                        cout << "No courses available.\n";
                        system("pause");
                        continue;
                    }
                    
                    // Display available courses
                    cout << "Select a course to view its teachers:\n";
                    cout << "======================================\n";
                    for(int i = 0; i < courseCount; i++) {
                        Course* currentCourse = coursePtr + i;
                        cout << i+1 << ". " << currentCourse->code << " - " 
                             << currentCourse->name << "\n";
                    }
                    
                    int courseChoice;
                    cout << "\nSelect a course (1-" << courseCount << "): ";
                    cin >> courseChoice;
                    
                    if(courseChoice < 1 || courseChoice > courseCount) {
                        cout << "Invalid selection!\n";
                        system("pause");
                        continue;
                    }
                    
                    Course* selectedCourse = coursePtr + (courseChoice - 1);
                    
                    system("cls");
                    cout << "=========================================\n";
                    cout << "   TEACHERS FOR " << selectedCourse->code << "\n";
                    cout << "=========================================\n\n";
                    
                    cout << "Course: " << selectedCourse->code << " - " 
                         << selectedCourse->name << "\n";
                    cout << "Year: " << getYearString(selectedCourse->year) << ", Semester: " 
                         << getSemesterString(selectedCourse->semester) << "\n\n";
                    
                    if(selectedCourse->instructorCount == 0) {
                        cout << "No teachers assigned to this course yet.\n";
                    } else {
                        for(int i = 0; i < selectedCourse->instructorCount; i++) {
                            Teacher* teacher = findTeacherByName(teacherPtr, teacherCount, selectedCourse->instructors[i]);
                            if(teacher != nullptr) {
                                cout << "TEACHER DETAILS:\n";
                                cout << "================\n";
                                cout << "Name: " << teacher->name << "\n";
                                cout << "Rating: " << fixed << setprecision(1) << teacher->rating << "/5.0\n";
                                cout << "Rating Count: " << teacher->ratingCount << "\n\n";
                                
                                cout << "Courses Taught:\n";
                                if(teacher->courseCount == 0) {
                                    cout << "No other courses\n";
                                } else {
                                    for(int j = 0; j < teacher->courseCount; j++) {
                                        Course* course = findCourseByCode(coursePtr, courseCount, teacher->coursesTaught[j]);
                                        if(course != nullptr) {
                                            cout << course->code << " - " << course->name << "\n";
                                        }
                                    }
                                }
                                cout << "\n";
                                
                                // Display comments for this teacher
                                cout << "STUDENT COMMENTS:\n";
                                cout << "=================\n";
                                if(teacher->commentCount == 0) {
                                    cout << "No comments yet for this teacher.\n";
                                } else {
                                    for(int j = 0; j < teacher->commentCount; j++) {
                                        cout << "\"" << teacher->comments[j] << "\"\n";
                                    }
                                }
                                
                                if(i < selectedCourse->instructorCount - 1) {
                                    cout << "\n" << string(40, '-') << "\n\n";
                                }
                            }
                        }
                    }
                    
                    cout << "\n";
                    system("pause");

                } else if(instructorChoice == 2) {
                    // RATE A TEACHER
                    if(teacherCount == 0) {
                        cout << "\nNo teachers available.\n";
                        system("pause");
                        continue;
                    }

                    system("cls");
                    cout << "=========================================\n";
                    cout << "         RATE A TEACHER\n";
                    cout << "=========================================\n\n";

                    Teacher* currentTeacher;
                    for(int i = 0; i < teacherCount; i++) {
                        currentTeacher = teacherPtr + i;
                        cout << i+1 << ". " << currentTeacher->name << "\n";
                    }

                    int choice;
                    cout << "\nSelect teacher (1-" << teacherCount << "): ";
                    cin >> choice;

                    if(choice < 1 || choice > teacherCount) {
                        cout << "Invalid selection!\n";
                        system("pause");
                        continue;
                    }

                    Teacher* selectedTeacher = teacherPtr + (choice - 1);

                    cout << "\nYou selected: " << selectedTeacher->name << "\n";
                    cout << "Current rating: " << fixed << setprecision(1) << selectedTeacher->rating << "/5.0\n";
                    cout << "Rating count: " << selectedTeacher->ratingCount << "\n\n";

                    int newRating;
                    cout << "Enter new rating (1-5): ";
                    cin >> newRating;

                    if(newRating < 1 || newRating > 5) {
                        cout << "Rating must be 1-5!\n";
                        system("pause");
                        continue;
                    }

                    string comment;
                    cout << "Enter your comment: ";
                    cin.ignore();
                    getline(cin, comment);

                    float total = selectedTeacher->rating * selectedTeacher->ratingCount;
                    total += newRating;
                    selectedTeacher->ratingCount++;
                    selectedTeacher->rating = total / selectedTeacher->ratingCount;

                    if(selectedTeacher->commentCount < 20) {
                        selectedTeacher->comments[selectedTeacher->commentCount] = comment;
                        selectedTeacher->commentCount++;
                    }

                    cout << "\nThank you! Rating saved.\n";
                    system("pause");

                } else if(instructorChoice == 3) {
                    // ADD NEW TEACHER
                    if(teacherCount >= 50) {
                        cout << "\nMaximum number of teachers reached!\n";
                        system("pause");
                        continue;
                    }

                    system("cls");
                    cout << "=========================================\n";
                    cout << "         ADD NEW TEACHER\n";
                    cout << "=========================================\n\n";

                    Teacher* newTeacher = teacherPtr + teacherCount;
                    
                    cout << "Enter teacher's name: ";
                    cin.ignore();
                    getline(cin, newTeacher->name);
                    
                    newTeacher->rating = 0.0;
                    newTeacher->ratingCount = 0;
                    newTeacher->commentCount = 0;
                    newTeacher->courseCount = 0;
                    
                    cout << "\nWhich courses does this teacher teach? (Enter course codes, type 'done' when finished)\n";
                    cout << "Available courses from Course Overview System:\n";
                    cout << "===============================================\n";
                    
                    // Show available courses from the system
                    for(int i = 0; i < courseCount; i++) {
                        Course* currentCourse = coursePtr + i;
                        cout << currentCourse->code << " - " << currentCourse->name 
                             << " (" << getYearString(currentCourse->year) << ", " 
                             << getSemesterString(currentCourse->semester) << ")\n";
                    }
                    cout << "\n";
                    
                    string courseCode;
                    int coursesAdded = 0;
                    
                    while(coursesAdded < 10) {
                        cout << "Course " << coursesAdded + 1 << " code (or 'done'): ";
                        getline(cin, courseCode);
                        
                        if(courseCode == "done" || courseCode == "DONE") {
                            break;
                        }
                        
                        // Check if course exists in the system
                        Course* course = findCourseByCode(coursePtr, courseCount, courseCode);
                        if(course != nullptr) {
                            // Add course to teacher
                            newTeacher->coursesTaught[coursesAdded] = courseCode;
                            coursesAdded++;
                            newTeacher->courseCount++;
                            
                            // Add teacher to course
                            addTeacherToCourse(course, newTeacher->name);
                            
                            cout << "Added " << course->name << " to teacher's courses.\n";
                        } else {
                            cout << "Course '" << courseCode << "' not found in the system.\n";
                            cout << "Would you like to add it anyway? (y/n): ";
                            char choice;
                            cin >> choice;
                            cin.ignore();
                            
                            if(choice == 'y' || choice == 'Y') {
                                newTeacher->coursesTaught[coursesAdded] = courseCode;
                                coursesAdded++;
                                newTeacher->courseCount++;
                                cout << "Course added to teacher's list.\n";
                            }
                        }
                    }
                    
                    teacherCount++;
                    cout << "\nTeacher added successfully!\n";
                    system("pause");

                } else if(instructorChoice == 4) {
                    // BACK TO MAIN MENU
                    break;
                } else {
                    cout << "Invalid choice!\n";
                    system("pause");
                }

            } while(instructorChoice != 4);

        } else if(mainChoice == 3) {
            // EXIT
            cout << "\nSaving data...\n";
        } else {
            cout << "Invalid choice!\n";
            system("pause");
        }

    } while(mainChoice != 3);

    // ==================== SAVE DATA ====================
    ofstream tFileOut("teachers.dat");
    if(tFileOut.is_open()) {
        tFileOut << teacherCount << endl;
        Teacher* currentTeacher;

        for(int i = 0; i < teacherCount; i++) {
            currentTeacher = teacherPtr + i;
            tFileOut << currentTeacher->name << endl;
            tFileOut << currentTeacher->rating << endl;
            tFileOut << currentTeacher->ratingCount << endl;
            tFileOut << currentTeacher->commentCount << endl;
            tFileOut << currentTeacher->courseCount << endl;

            for(int j = 0; j < currentTeacher->commentCount; j++) {
                tFileOut << currentTeacher->comments[j] << endl;
            }
            
            for(int j = 0; j < currentTeacher->courseCount; j++) {
                tFileOut << currentTeacher->coursesTaught[j] << endl;
            }
            
            tFileOut << "---" << endl;
        }
        tFileOut.close();
    }

    ofstream cFileOut("courses.dat");
    if(cFileOut.is_open()) {
        cFileOut << courseCount << endl;
        Course* currentCourse;

        for(int i = 0; i < courseCount; i++) {
            currentCourse = coursePtr + i;
            cFileOut << currentCourse->code << endl;
            cFileOut << currentCourse->name << endl;
            cFileOut << currentCourse->year << endl;
            cFileOut << currentCourse->semester << endl;
            cFileOut << currentCourse->description << endl;
            cFileOut << currentCourse->difficulty << endl;
            cFileOut << currentCourse->instructorCount << endl;
            cFileOut << currentCourse->prereqCount << endl;

            for(int j = 0; j < currentCourse->instructorCount; j++) {
                cFileOut << currentCourse->instructors[j] << endl;
            }
            
            for(int j = 0; j < currentCourse->prereqCount; j++) {
                cFileOut << currentCourse->prerequisites[j] << endl;
            }
            
            cFileOut << "---" << endl;
        }
        cFileOut.close();
    }

    cout << "\nThank you for using our system!\n";
    cout << "Goodbye!\n";

    return 0;
}