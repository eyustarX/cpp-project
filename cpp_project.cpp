#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct Teacher {
    string name;
    float rating;
    int ratingCount;
    string comments[1000];
    string coursesTaught[1000];
};

struct Course {
    string code;
    string title;
    int creditHours;
    int year;
    int semester;
    string description;
    string instructors[1000];
};

Teacher* findTeacherByName(Teacher* teachers, int teacherCount, string name) {
    for(int i = 0; i < teacherCount; i++) {
        if((teachers + i)->name == name) {
            return teachers + i;
        }
    }
    return nullptr;
}

Course* findCourseByCode(Course* courses, int courseCount, string code) {
    for(int i = 0; i < courseCount; i++) {
        if((courses + i)->code == code) {
            return courses + i;
        }
    }
    return nullptr;
}

void addTeacherToCourse(Course* course, string teacherName) {
    for(int i = 0; i < 1000; i++) {
        if(course->instructors[i].empty()) {
            course->instructors[i] = teacherName;
            break;
        }
    }
}

void saveTeacherToFile(Teacher* teacher) {
    ofstream file("teacher.txt", ios::app);
    if(file.is_open()) {
        file << "Name: " << teacher->name << endl;
        file << "Rating: " << fixed << setprecision(1) << teacher->rating << "/5.0" << endl;
        file << "Rating Count: " << teacher->ratingCount << endl;
        
        file << "Comments:" << endl;
        int commentCount = 0;
        for(int i = 0; i < 1000 && !teacher->comments[i].empty(); i++) {
            file << "  - " << teacher->comments[i] << endl;
            commentCount++;
        }
        file << "Total Comments: " << commentCount << endl;
        
        file << "Courses Taught:" << endl;
        int courseCount = 0;
        for(int i = 0; i < 1000 && !teacher->coursesTaught[i].empty(); i++) {
            file << "  - " << teacher->coursesTaught[i] << endl;
            courseCount++;
        }
        file << "Total Courses: " << courseCount << endl;
        
        file << "----------------------------------------" << endl;
        file.close();
        cout << "Teacher data saved to teacher.txt" << endl;
    } else {
        cout << "Error: Could not save teacher data to file." << endl;
    }
}

int countComments(Teacher* teacher) {
    int count = 0;
    for(int i = 0; i < 1000 && !teacher->comments[i].empty(); i++) {
        count++;
    }
    return count;
}

int countCoursesTaught(Teacher* teacher) {
    int count = 0;
    for(int i = 0; i < 1000 && !teacher->coursesTaught[i].empty(); i++) {
        count++;
    }
    return count;
}

int countInstructors(Course* course) {
    int count = 0;
    for(int i = 0; i < 1000 && !course->instructors[i].empty(); i++) {
        count++;
    }
    return count;
}

void displayCourseDetails(Course* course, Teacher* teachers, int teacherCount) {
    system("cls");
    cout << "=========================================\n";
    cout << "   COURSE DETAILS\n";
    cout << "=========================================\n\n";
    
    cout << "Course Code:    " << course->code << "\n";
    cout << "Course Title:   " << course->title << "\n";
    cout << "Credit Hours:   " << course->creditHours << "\n";
    cout << "Semester:       Year " << course->year << ", Semester " << course->semester << "\n";    
    cout << "\nINSTRUCTORS:\n";
    cout << "============\n";
    int instructorCount = countInstructors(course);
    if(instructorCount == 0) {
        cout << "No instructors assigned to this course yet.\n";
    } else {
        for(int j = 0; j < instructorCount; j++) {
            Teacher* teacher = findTeacherByName(teachers, teacherCount, course->instructors[j]);
            if(teacher != nullptr) {
                cout << "• " << teacher->name << " (Rating: " << fixed << setprecision(1) 
                     << teacher->rating << "/5.0)\n";
            } else {
                cout << "• " << course->instructors[j] << "\n";
            }
        }
    }
    
    cout << "\nCOURSE DESCRIPTION:\n";
    cout << "===================\n";
    cout << course->description << "\n\n";

    cout << "\n" << string(40, '=') << "\n\n";
    system("pause");
}

int main() {
    Teacher teachers[50];
    Course courses[50];
    int teacherCount = 0;
    int courseCount = 0;

    Teacher* teacherPtr = teachers;
    Course* coursePtr = courses;

    
    coursePtr->code = "SWEG2103";
    coursePtr->title = "Fundamentals of Programming I";
    coursePtr->creditHours = 3;
    coursePtr->year = 2;
    coursePtr->semester = 1;
    coursePtr->description = "Fundamentals of Programming I establishes the foundation for software engineering using C++. It covers programming fundamentals including SDLC, algorithm design with flowcharts/pseudocode, and programming language paradigms. Students learn C++ syntax, variables, data types, operators, expressions, and input/output operations with debugging techniques. The course includes control structures (if, switch, loops) and data handling through arrays and string manipulation. Memory management concepts cover pointers, pointer arithmetic, and dynamic allocation.";
    coursePtr->instructors[0] = "Mrs. Eleni Teshome";
    coursePtr->instructors[1] = "Dr. John Doe";

    (coursePtr + 1)->code = "GLTr2011";
    (coursePtr + 1)->title = "Global Trend";
    (coursePtr + 1)->creditHours = 2;
    (coursePtr + 1)->year = 2;
    (coursePtr + 1)->semester = 1;
    (coursePtr + 1)->description = "Global Trend is designed to equip students with the basics of international relations so that they will be exposed to global challenges and perspectives. The course is very comprehensive, broad and multidisciplinary in its nature. Perhaps you may find it as an ice-breaking course since it touches up on wide range of issues, concepts, theories, approaches and debates that are helpful in understanding the contemporary international relations. Concepts, such as national interest, foreign policy, actors, globalization, balance of power, cold war, multi-polar systems, international law and other relevant concepts are being introduced. Different debates and approaches to the study of international relations including realism, liberalism are also given due emphasis.";
    (coursePtr + 1)->instructors[0] = "Mrs. LULU";

    (coursePtr + 2)->code = "SWEG2101";
    (coursePtr + 2)->title = "Introduction to Software Engineering and Computing";
    (coursePtr + 2)->creditHours = 4;
    (coursePtr + 2)->year = 2;
    (coursePtr + 2)->semester = 1;
    (coursePtr + 2)->description = "This course provides a comprehensive introduction to the systematic application of engineering principles—design, development, testing, and maintenance—to the creation of reliable and efficient software systems. It serves as a bridge between foundational programming and professional project management, shifting the focus from 'just coding' to a holistic view of the Software Development Life Cycle (SDLC).";
    (coursePtr + 2)->instructors[0] = "Mrs. LULU";

    (coursePtr + 3)->code = "SWEG2105";
    (coursePtr + 3)->title = "Discrete Mathematics for Software Engineering";
    (coursePtr + 3)->creditHours = 3;
    (coursePtr + 3)->year = 2;
    (coursePtr + 3)->semester = 1;
    (coursePtr + 3)->description = "This course serves as the mathematical bedrock for software engineering, shifting focus from continuous calculus to the study of discrete, isolated values. It integrates formal logic, set theory, graph theory, and combinatorics to provide the necessary framework for constructing efficient algorithms and complex data structures. Students move from abstract mathematical concepts to tangible software design, learning to apply propositional and predicate logic to program verification and code correctness. It covers the use of set theory and relations to model system behavior, while combinatorics and graph theory are utilized to optimize data flow and analyze network topologies. By the end of the course, students will be able to use these discrete structures to build robust, optimized software systems and perform rigorous analysis of computational problems.";
    (coursePtr + 3)->instructors[0] = "Mrs. LULU";

    (coursePtr + 4)->code = "Hist2002";
    (coursePtr + 4)->title = "History of Ethiopia and the Horn";
    (coursePtr + 4)->creditHours = 3;
    (coursePtr + 4)->year = 2;
    (coursePtr + 4)->semester = 1;
    (coursePtr + 4)->description = "This course offers a comprehensive analytical journey through the historical evolution of Ethiopia and the Horn. Students begin by mastering the nature of historical inquiry and evaluating the diverse sources used to reconstruct the region's past. The curriculum traces the area's significance from the Neolithic Revolution and human evolution through the rise of early states and the influential role of the Queen of Sheba legend in shaping political legitimacy from the Solomonic restoration (1270) to the end of the imperial era (1974). The module examines the complex dynamics between the Christian Kingdom and Muslim Sultanates, alongside the transformative impact of population movements across the Eastern, Central, Southern, and Western regions. Students will analyze the cultural and political peaks of the Gondarine period and the subsequent fragmentation during the Zemene-Mesafint. Special focus is given to the 19th-century unification process that formed modern Ethiopia, highlighting the resistance against colonialism through major battles and patriotic struggles. The course concludes by evaluating the modern era, including the socio-political developments from 1941–1974, the reforms and oppositions of the Derg regime, and the pivotal political transitions occurring between 1991 and 1995.";
    (coursePtr + 4)->instructors[0] = "Mrs. LULU";

    (coursePtr + 5)->code = "Stat2091";
    (coursePtr + 5)->title = "Probability and Statistics";
    (coursePtr + 5)->creditHours = 3;
    (coursePtr + 5)->year = 2;
    (coursePtr + 5)->semester = 1;
    (coursePtr + 5)->description = "This course provides a rigorous introduction to the mathematical theories used to quantify uncertainty and analyze data within the field of software engineering. It begins with descriptive statistics, teaching students how to organize and summarize data sets, before moving into the foundational laws of probability, including conditional probability and Bayes' Theorem. The course covers discrete and continuous probability distributions, such as Binomial, Poisson, and Normal distributions, which are essential for modeling system reliability and performance. Students will explore inferential statistics, focusing on point estimation, confidence intervals, and hypothesis testing to make data-driven decisions. Advanced topics include correlation and linear regression analysis, allowing students to model relationships between variables and predict software trends. Students will be equipped to apply statistical methods to experimental design, quality control, and the evaluation of complex computing systems.";
    (coursePtr + 5)->instructors[0] = "Mrs. LULU";

    // Year 2, Semester 2 Courses
    (coursePtr + 6)->code = "Econ2009";
    (coursePtr + 6)->title = "Economics";
    (coursePtr + 6)->creditHours = 3;
    (coursePtr + 6)->year = 2;
    (coursePtr + 6)->semester = 2;
    (coursePtr + 6)->description = "Economics introduces the core principles used to manage limited resources in a world of unlimited wants. It covers the basic economic problem of scarcity, choice, and opportunity cost. The course is divided into Microeconomics, which focuses on individual market behavior like supply and demand, price elasticity, and production costs, and Macroeconomics, which looks at the national economy. Students learn about key national indicators including Gross Domestic Product (GDP), inflation, and unemployment. The course also explains how the government uses fiscal and monetary policies to influence economic growth and stability. Finally, it explores international trade and the specific economic challenges faced by developing countries like Ethiopia.";
    (coursePtr + 6)->instructors[0] = "Mrs. LULU";

    (coursePtr + 7)->code = "SWEG2102";
    (coursePtr + 7)->title = "Fundamentals of Programming II";
    (coursePtr + 7)->creditHours = 3;
    (coursePtr + 7)->year = 2;
    (coursePtr + 7)->semester = 2;
    (coursePtr + 7)->description = "Fundamentals of Programming II focuses on solving complex problems by breaking large programs into smaller, manageable sub-modules using C++ functions. This modular approach makes it easier to reuse code, understand the program's logic, and handle debugging or maintenance. The course introduces advanced data structures, specifically pointers, to manage dynamic memory allocation and de-allocation. It also covers using structures to store and access records efficiently, along with File Operations for input and output.";
    (coursePtr + 7)->instructors[0] = "Mrs. LULU";

    (coursePtr + 8)->code = "Eng2004";
    (coursePtr + 8)->title = "Digital Logic Design";
    (coursePtr + 8)->creditHours = 3;
    (coursePtr + 8)->year = 2;
    (coursePtr + 8)->semester = 2;
    (coursePtr + 8)->description = "Digital Logic Design introduces the fundamental building blocks of digital systems and computer hardware. It starts with number systems, Boolean algebra, and logic gates used to simplify digital circuits. The course covers combinational logic circuits like adders, decoders, and multiplexers, as well as sequential logic including flip-flops, counters, and registers. Students learn to design and analyze synchronous and asynchronous circuits while understanding how memory elements work. Practical lab sessions involve building and testing circuits to bridge the gap between theoretical logic and physical hardware implementation.";
    (coursePtr + 8)->instructors[0] = "Mrs. LULU";

    (coursePtr + 9)->code = "SWEG2106";
    (coursePtr + 9)->title = "Data Communication and Computer Networks";
    (coursePtr + 9)->creditHours = 4;
    (coursePtr + 9)->year = 2;
    (coursePtr + 9)->semester = 2;
    (coursePtr + 9)->description = "This course explores the principles and protocols used in modern computer networking. It follows the OSI and TCP/IP layered models to explain how data travels from one device to another over various transmission media. Key topics include physical layer signaling, data link layer error detection, and MAC addressing. The course covers network layer routing, transport layer reliability (TCP/UDP), and common application layer protocols like HTTP and DNS. Students gain hands-on experience in the lab configuring IP addresses, understanding subnets, and simulating network topologies to solve connectivity issues.";
    (coursePtr + 9)->instructors[0] = "Mrs. LULU";

    (coursePtr + 10)->code = "SWEG2108";
    (coursePtr + 10)->title = "Database Systems";
    (coursePtr + 10)->creditHours = 4;
    (coursePtr + 10)->year = 2;
    (coursePtr + 10)->semester = 2;
    (coursePtr + 10)->description = "Database Systems focuses on the design, implementation, and management of relational databases. It covers the Entity-Relationship (ER) modeling technique to map real-world data requirements into structured database schemas. Students learn the relational model, normalization to reduce data redundancy, and the use of Structured Query Language (SQL) for data definition and manipulation. The course also introduces database security, transaction management, and concurrency control to ensure data integrity. In the lab, students work with database management systems (DBMS) like MySQL or PostgreSQL to build and query functional databases for software applications.";
    (coursePtr + 10)->instructors[0] = "Mrs. LULU";

    courseCount = 11; // Total courses: 6 in Semester 1 + 5 in Semester 2

    // Initialize teachers
    teacherPtr->name = "Mrs. Eleni Teshome";
    teacherPtr->rating = 4.5;
    teacherPtr->ratingCount = 10;
    teacherPtr->comments[0] = "Great teacher";
    teacherPtr->comments[1] = "Very helpful";
    teacherPtr->comments[2] = "Explains well";
    teacherPtr->coursesTaught[0] = "SWEG2103";

    (teacherPtr + 1)->name = "Dr. John Doe";
    (teacherPtr + 1)->rating = 4.2;
    (teacherPtr + 1)->ratingCount = 8;
    (teacherPtr + 1)->comments[0] = "Knowledgeable";
    (teacherPtr + 1)->comments[1] = "Fair grader";
    (teacherPtr + 1)->coursesTaught[0] = "SWEG2103";

    (teacherPtr + 2)->name = "Mrs. LULU";
    (teacherPtr + 2)->rating = 4.7;
    (teacherPtr + 2)->ratingCount = 15;
    (teacherPtr + 2)->comments[0] = "Excellent lecturer";
    (teacherPtr + 2)->comments[1] = "Very organized";
    (teacherPtr + 2)->comments[2] = "Supportive and approachable";
    teacherPtr->coursesTaught[0] = "GLTr2011";
    teacherPtr->coursesTaught[1] = "SWEG2101";
    teacherPtr->coursesTaught[2] = "SWEG2105";
    teacherPtr->coursesTaught[3] = "Hist2002";
    teacherPtr->coursesTaught[4] = "Stat2091";
    teacherPtr->coursesTaught[5] = "Econ2009";
    teacherPtr->coursesTaught[6] = "SWEG2102";
    teacherPtr->coursesTaught[7] = "EEng2004";
    teacherPtr->coursesTaught[8] = "SWEG2106";
    teacherPtr->coursesTaught[9] = "SWEG2108";

    teacherCount = 3;

    char runAgain = 'y';
    
    while(runAgain == 'y' || runAgain == 'Y') {
        system("cls");
        cout << "    COURSE REVIEW SYSTEM - AASTU\n";
        cout << "1. View Course Overview\n";
        cout << "2. Instructor Rating System\n";
        cout << "3. Exit\n\n";

        int mainChoice;
        cout << "Enter choice (1-3): ";
        cin >> mainChoice;

        while(mainChoice < 1 || mainChoice > 3) {
            cout << "Invalid choice! Please enter 1, 2, or 3: ";
            cin >> mainChoice;
        }

        if(mainChoice == 1) {
            char viewMore = 'y';
            
            while(viewMore == 'y' || viewMore == 'Y') {
                system("cls");
                cout << "        COURSE OVERVIEW\n";
                cout << "Select Academic Year:\n";
                cout << "1. 2nd Year\n";
                cout << "2. 3rd Year\n";
                cout << "3. 4th Year\n";
                cout << "4. 5th Year\n\n";
                
                int year;
                cout << "Enter choice (1-4): ";
                cin >> year;

                while(year < 1 || year > 4) {
                    cout << "Invalid year selection! Please enter a number between 1 and 4: ";
                    cin >> year;
                }
                year = year + 1; // Convert to actual year number

                cout << "\nSelect Semester:\n";
                cout << "1. 1st Semester\n";
                cout << "2. 2nd Semester\n\n";
                int semester;
                cout << "Enter choice (1-2): ";
                cin >> semester;

                while(semester != 1 && semester != 2) {
                    cout << "Invalid semester selection! Please enter 1 or 2: ";
                    cin >> semester;
                }

                Course* availableCourses[50];
                int availableCount = 0;
                
                // Filter courses by year and semester
                for(int i = 0; i < courseCount; i++) {
                    Course currentCourse = courses[i];
                    if(currentCourse.year == year && currentCourse.semester == semester) {
                        availableCourses[availableCount] = &currentCourse;
                        availableCount++;
                    }
                }

                if(availableCount == 0) {
                    cout << "\nNo courses found for Year " << year << ", Semester " << semester << ".\n";
                    cout << "Do you want to try another selection? (y/n): ";
                    cin >> viewMore;
                    if(viewMore == 'n' || viewMore == 'N') {
                        break;
                    }
                    continue;
                }

                system("cls");
                cout << "   " << getYearString(year) << " - " << getSemesterString(semester) << "\n\n";
                
                cout << "Available Courses:\n";
                for(int i = 0; i < availableCount; i++) {
                    cout << i+1 << ". " << availableCourses[i]->code << " - " 
                         << availableCourses[i]->title << " (" 
                         << availableCourses[i]->creditHours << " credits)\n";
                }
                
                cout << "\n0. Back to Main Menu\n\n";
                int courseChoice;
                cout << "Select a course (0-" << availableCount << "): ";
                cin >> courseChoice;
                
                // Keep asking until valid course choice
                while(courseChoice < 0 || courseChoice > availableCount) {
                    cout << "Invalid course selection! Please enter a number between 0 and " 
                         << availableCount << ": ";
                    cin >> courseChoice;
                }
                
                if(courseChoice == 0) {
                    break;
                }

                Course* selectedCourse = availableCourses[courseChoice - 1];
                displayCourseDetails(selectedCourse, teacherPtr, teacherCount);
                
                cout << "Do you want to view another course? (y/n): ";
                cin >> viewMore;
            }

        } else if(mainChoice == 2) {
            char instructorMore = 'y';
            
            while(instructorMore == 'y' || instructorMore == 'Y') {
                system("cls");
                cout << "      INSTRUCTOR RATING SYSTEM\n";
                cout << "1. View a Teacher\n";
                cout << "2. Rate a Teacher\n";
                cout << "3. Add New Teacher\n";
                cout << "4. Back to Main Menu\n\n";

                int instructorChoice;
                cout << "Enter choice (1-4): ";
                cin >> instructorChoice;

                // Keep asking until valid instructor choice
                while(instructorChoice < 1 || instructorChoice > 4) {
                    cout << "Invalid choice! Please enter a number between 1 and 4: ";
                    cin >> instructorChoice;
                }

                if(instructorChoice == 1) {
                    if(courseCount == 0) {
                        cout << "\nNo courses available.\n";
                        cout << "Do you want to continue? (y/n): ";
                        char contChoice;
                        cin >> contChoice;
                        if(contChoice == 'n' || contChoice == 'N') {
                            break;
                        }
                        continue;
                    }
                    
                    system("cls");
                    cout << "       VIEW A TEACHER\n\n";
                    cout << "Select a course to view its teachers:\n";
                    
                    for(int i = 0; i < courseCount; i++) {
                        Course* currentCourse = coursePtr + i;
                        cout << i+1 << ". " << currentCourse->code << " - " 
                             << currentCourse->title << "\n";
                    }
                    
                    int courseChoice;
                    cout << "\nSelect a course (1-" << courseCount << "): ";
                    cin >> courseChoice;
                    
                    // Keep asking until valid course choice
                    while(courseChoice < 1 || courseChoice > courseCount) {
                        cout << "Invalid selection! Please enter a number between 1 and " 
                             << courseCount << ": ";
                        cin >> courseChoice;
                    }
                    
                    Course* selectedCourse = coursePtr + (courseChoice - 1);
                    
                    system("cls");
                    cout << "   TEACHERS FOR " << selectedCourse->code << "\n\n";
                    
                    cout << "Course: " << selectedCourse->code << " - " 
                         << selectedCourse->title << "\n";
                    cout << "Year: " << getYearString(selectedCourse->year) << ", Semester: " 
                         << getSemesterString(selectedCourse->semester) << "\n\n";
                    
                    int instructorCount = countInstructors(selectedCourse);
                    if(instructorCount == 0) {
                        cout << "No teachers assigned to this course yet.\n";
                    } else {
                        for(int i = 0; i < instructorCount; i++) {
                            Teacher* teacher = findTeacherByName(teacherPtr, teacherCount, selectedCourse->instructors[i]);
                            if(teacher != nullptr) {
                                cout << "TEACHER DETAILS:\n";
                                cout << "Name: " << teacher->name << "\n";
                                cout << "Rating: " << fixed << setprecision(1) << teacher->rating << "/5.0\n";
                                cout << "Rating Count: " << teacher->ratingCount << "\n\n";
                                
                                cout << "Courses Taught:\n";
                                int teacherCourseCount = countCoursesTaught(teacher);
                                if(teacherCourseCount == 0) {
                                    cout << "No other courses\n";
                                } else {
                                    for(int j = 0; j < teacherCourseCount; j++) {
                                        Course* course = findCourseByCode(coursePtr, courseCount, teacher->coursesTaught[j]);
                                        if(course != nullptr) {
                                            cout << course->code << " - " << course->title << "\n";
                                        }
                                    }
                                }
                                cout << "\n";
                                
                                cout << "STUDENT COMMENTS:\n";
                                int commentCount = countComments(teacher);
                                if(commentCount == 0) {
                                    cout << "No comments yet for this teacher.\n";
                                } else {
                                    for(int j = 0; j < commentCount; j++) {
                                        cout << "\"" << teacher->comments[j] << "\"\n";
                                    }
                                }
                                
                                if(i < instructorCount - 1) {
                                    cout << "\n" << string(40, '-') << "\n\n";
                                }
                            }
                        }
                    }
                    
                    cout << "\nDo you want to view another teacher? (y/n): ";
                    cin >> instructorMore;

                } else if(instructorChoice == 2) {
                    if(teacherCount == 0) {
                        cout << "\nNo teachers available.\n";
                        cout << "Do you want to continue? (y/n): ";
                        char contChoice;
                        cin >> contChoice;
                        if(contChoice == 'n' || contChoice == 'N') {
                            break;
                        }
                        continue;
                    }

                    system("cls");
                    cout << "         RATE A TEACHER\n\n";

                    Teacher* currentTeacher;
                    for(int i = 0; i < teacherCount; i++) {
                        currentTeacher = teacherPtr + i;
                        cout << i+1 << ". " << currentTeacher->name << "\n";
                    }

                    int choice;
                    cout << "\nSelect teacher (1-" << teacherCount << "): ";
                    cin >> choice;

                    // Keep asking until valid teacher choice
                    while(choice < 1 || choice > teacherCount) {
                        cout << "Invalid selection! Please enter a number between 1 and " 
                             << teacherCount << ": ";
                        cin >> choice;
                    }

                    Teacher* selectedTeacher = teacherPtr + (choice - 1);

                    cout << "\nYou selected: " << selectedTeacher->name << "\n";
                    cout << "Current rating: " << fixed << setprecision(1) << selectedTeacher->rating << "/5.0\n";
                    cout << "Rating count: " << selectedTeacher->ratingCount << "\n\n";

                    int newRating;
                    cout << "Enter new rating (1-5): ";
                    cin >> newRating;

                    // Keep asking until valid rating
                    while(newRating < 1 || newRating > 5) {
                        cout << "Rating must be 1-5! Please enter a valid rating: ";
                        cin >> newRating;
                    }

                    string comment;
                    cout << "Enter your comment: ";
                    cin.ignore();
                    getline(cin, comment);

                    float total = selectedTeacher->rating * selectedTeacher->ratingCount;
                    total += newRating;
                    selectedTeacher->ratingCount++;
                    selectedTeacher->rating = total / selectedTeacher->ratingCount;

                    // Add comment to first empty slot
                    for(int i = 0; i < 1000; i++) {
                        if(selectedTeacher->comments[i].empty()) {
                            selectedTeacher->comments[i] = comment;
                            break;
                        }
                    }

                    cout << "\nThank you! Rating saved (in memory only).\n";
                    cout << "New average rating: " << fixed << setprecision(1) << selectedTeacher->rating << "/5.0\n";
                    
                    cout << "\nDo you want to rate another teacher? (y/n): ";
                    cin >> instructorMore;
                    cin.ignore();

                } else if(instructorChoice == 3) {
                    if(teacherCount >= 50) {
                        cout << "\nMaximum number of teachers reached!\n";
                        cout << "Do you want to continue? (y/n): ";
                        char contChoice;
                        cin >> contChoice;
                        if(contChoice == 'n' || contChoice == 'N') {
                            break;
                        }
                        continue;
                    }

                    system("cls");
                    cout << "         ADD NEW TEACHER\n\n";

                    Teacher* newTeacher = teacherPtr + teacherCount;
                    
                    cout << "Enter teacher's name: ";
                    cin.ignore();
                    getline(cin, newTeacher->name);
                    
                    newTeacher->rating = 0.0;
                    newTeacher->ratingCount = 0;
                    
                    cout << "\nWhich courses does this teacher teach?\n";
                    cout << "Available courses:\n\n";
                    
                    // Show ALL courses for selection
                    for(int i = 0; i < courseCount; i++) {
                        Course* currentCourse = coursePtr + i;
                        cout << currentCourse->code << " - " << currentCourse->title 
                             << " (" << getYearString(currentCourse->year) << ", " 
                             << getSemesterString(currentCourse->semester) << ")\n";
                    }
                    cout << "\n";
                    
                    char addMoreCourses = 'y';
                    int courseIndex = 0;
                    
                    while((addMoreCourses == 'y' || addMoreCourses == 'Y') && courseIndex < 1000) {
                        cout << "Enter course " << courseIndex + 1 << " code: ";
                        string courseCode;
                        getline(cin, courseCode);
                        
                        Course* course = findCourseByCode(coursePtr, courseCount, courseCode);
                        if(course != nullptr) {
                            // Add to teacher's courses
                            newTeacher->coursesTaught[courseIndex] = courseCode;
                            
                            // Add teacher to course
                            addTeacherToCourse(course, newTeacher->name);
                            
                            cout << "Added " << course->title << " to teacher's courses.\n";
                            courseIndex++;
                        } else {
                            cout << "Course '" << courseCode << "' not found.\n";
                        }
                        
                        if(courseIndex < 1000) {
                            cout << "\nAdd another course? (y/n): ";
                            cin >> addMoreCourses;
                            cin.ignore();
                        } else {
                            cout << "Maximum courses reached for this teacher.\n";
                            break;
                        }
                    }
                    
                    teacherCount++;
                    
                    // Save the newly added teacher to file
                    cout << "\nSaving teacher data to file...\n";
                    saveTeacherToFile(newTeacher);
                    
                    cout << "Teacher added successfully!\n";
                    
                    cout << "\nDo you want to add another teacher? (y/n): ";
                    cin >> instructorMore;
                    cin.ignore();

                } else if(instructorChoice == 4) {
                    break;
                }
            }

        } else if(mainChoice == 3) {
            cout << "\nExiting system...\n";
            break;
        }
        
        cout << "\nDo you want to use the system again? (y/n): ";
        cin >> runAgain;
    }

    cout << "\nThank you for using the AASTU Course Review System!\n";
    cout << "Goodbye!\n";

    return 0;
}