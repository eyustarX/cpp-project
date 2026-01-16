#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Course
{
    string code;
    string title;
    int creditHours;
    int year;
    int semester;
    string description;
    string instructor;
};

Course *findCourseByCode(Course *courses, int courseCount, string code)
{
    for (int i = 0; i < courseCount; i++)
    {
        if (courses[i].code == code)
        {
            return &courses[i];
        }
    }
    return nullptr;
}

void displayCourseDetails(Course *course)
{
    cout << "   COURSE DETAILS\n";

    cout << "Course Code:    " << course->code << "\n";
    cout << "Course Title:   " << course->title << "\n";
    cout << "Credit Hours:   " << course->creditHours << "\n";
    cout << "Year:           " << course->year << "\n";
    cout << "Semester:       " << course->semester << "\n";

    cout << "\nINSTRUCTOR:\n";
    if (course->instructor.empty())
    {
        cout << "No instructor assigned to this course yet.\n";
    }
    else
    {
        cout << "- " << course->instructor << "\n";
    }

    cout << "\nCOURSE DESCRIPTION:\n";
    cout << course->description << "\n\n";
}

int main()
{
    Course courses[50];
    int courseCount = 0;

    // Initialize courses
    courses[0].code = "SWEG2103";
    courses[0].title = "Fundamentals of Programming I";
    courses[0].creditHours = 3;
    courses[0].year = 2;
    courses[0].semester = 1;
    courses[0].description = "Fundamentals of Programming I establishes the foundation for software engineering using C++. It covers programming fundamentals including SDLC, algorithm design with flowcharts/pseudocode, and programming language paradigms. Students learn C++ syntax, variables, data types, operators, expressions, and input/output operations with debugging techniques. The course includes control structures (if, switch, loops) and data handling through arrays and string manipulation. Memory management concepts cover pointers, pointer arithmetic, and dynamic allocation.";
    courses[0].instructor = "Mrs. Eleni Teshome & Dr. John Doe";

    courses[1].code = "GLTr2011";
    courses[1].title = "Global Trend";
    courses[1].creditHours = 2;
    courses[1].year = 2;
    courses[1].semester = 1;
    courses[1].description = "Global Trend is designed to equip students with the basics of international relations so that they will be exposed to global challenges and perspectives. The course is very comprehensive, broad and multidisciplinary in its nature. Perhaps you may find it as an ice-breaking course since it touches up on wide range of issues, concepts, theories, approaches and debates that are helpful in understanding the contemporary international relations. Concepts, such as national interest, foreign policy, actors, globalization, balance of power, cold war, multi-polar systems, international law and other relevant concepts are being introduced. Different debates and approaches to the study of international relations including realism, liberalism are also given due emphasis.";
    courses[1].instructor = "Mrs. LULU";

    courses[2].code = "SWEG2101";
    courses[2].title = "Introduction to Software Engineering and Computing";
    courses[2].creditHours = 4;
    courses[2].year = 2;
    courses[2].semester = 1;
    courses[2].description = "This course provides a comprehensive introduction to the systematic application of engineering principles—design, development, testing, and maintenance—to the creation of reliable and efficient software systems. It serves as a bridge between foundational programming and professional project management, shifting the focus from 'just coding' to a holistic view of the Software Development Life Cycle (SDLC).";
    courses[2].instructor = "Mrs. LULU";

    courses[3].code = "SWEG2105";
    courses[3].title = "Discrete Mathematics for Software Engineering";
    courses[3].creditHours = 3;
    courses[3].year = 2;
    courses[3].semester = 1;
    courses[3].description = "This course serves as the mathematical bedrock for software engineering, shifting focus from continuous calculus to the study of discrete, isolated values. It integrates formal logic, set theory, graph theory, and combinatorics to provide the necessary framework for constructing efficient algorithms and complex data structures. Students move from abstract mathematical concepts to tangible software design, learning to apply propositional and predicate logic to program verification and code correctness. It covers the use of set theory and relations to model system behavior, while combinatorics and graph theory are utilized to optimize data flow and analyze network topologies. By the end of the course, students will be able to use these discrete structures to build robust, optimized software systems and perform rigorous analysis of computational problems.";
    courses[3].instructor = "Mrs. LULU";

    courses[4].code = "Hist2002";
    courses[4].title = "History of Ethiopia and the Horn";
    courses[4].creditHours = 3;
    courses[4].year = 2;
    courses[4].semester = 1;
    courses[4].description = "This course offers a comprehensive analytical journey through the historical evolution of Ethiopia and the Horn. Students begin by mastering the nature of historical inquiry and evaluating the diverse sources used to reconstruct the region's past. The curriculum traces the area's significance from the Neolithic Revolution and human evolution through the rise of early states and the influential role of the Queen of Sheba legend in shaping political legitimacy from the Solomonic restoration (1270) to the end of the imperial era (1974). The module examines the complex dynamics between the Christian Kingdom and Muslim Sultanates, alongside the transformative impact of population movements across the Eastern, Central, Southern, and Western regions. Students will analyze the cultural and political peaks of the Gondarine period and the subsequent fragmentation during the Zemene-Mesafint. Special focus is given to the 19th-century unification process that formed modern Ethiopia, highlighting the resistance against colonialism through major battles and patriotic struggles. The course concludes by evaluating the modern era, including the socio-political developments from 1941–1974, the reforms and oppositions of the Derg regime, and the pivotal political transitions occurring between 1991 and 1995.";
    courses[4].instructor = "Mrs. LULU";

    courses[5].code = "Stat2091";
    courses[5].title = "Probability and Statistics";
    courses[5].creditHours = 3;
    courses[5].year = 2;
    courses[5].semester = 1;
    courses[5].description = "This course provides a rigorous introduction to the mathematical theories used to quantify uncertainty and analyze data within the field of software engineering. It begins with descriptive statistics, teaching students how to organize and summarize data sets, before moving into the foundational laws of probability, including conditional probability and Bayes' Theorem. The course covers discrete and continuous probability distributions, such as Binomial, Poisson, and Normal distributions, which are essential for modeling system reliability and performance. Students will explore inferential statistics, focusing on point estimation, confidence intervals, and hypothesis testing to make data-driven decisions. Advanced topics include correlation and linear regression analysis, allowing students to model relationships between variables and predict software trends. Students will be equipped to apply statistical methods to experimental design, quality control, and the evaluation of complex computing systems.";
    courses[5].instructor = "Mrs. LULU";

    // Year 2, Semester 2 Courses
    courses[6].code = "Econ2009";
    courses[6].title = "Economics";
    courses[6].creditHours = 3;
    courses[6].year = 2;
    courses[6].semester = 2;
    courses[6].description = "Economics introduces the core principles used to manage limited resources in a world of unlimited wants. It covers the basic economic problem of scarcity, choice, and opportunity cost. The course is divided into Microeconomics, which focuses on individual market behavior like supply and demand, price elasticity, and production costs, and Macroeconomics, which looks at the national economy. Students learn about key national indicators including Gross Domestic Product (GDP), inflation, and unemployment. The course also explains how the government uses fiscal and monetary policies to influence economic growth and stability. Finally, it explores international trade and the specific economic challenges faced by developing countries like Ethiopia.";
    courses[6].instructor = "Mrs. LULU";

    courses[7].code = "SWEG2102";
    courses[7].title = "Fundamentals of Programming II";
    courses[7].creditHours = 3;
    courses[7].year = 2;
    courses[7].semester = 2;
    courses[7].description = "Fundamentals of Programming II focuses on solving complex problems by breaking large programs into smaller, manageable sub-modules using C++ functions. This modular approach makes it easier to reuse code, understand the program's logic, and handle debugging or maintenance. The course introduces advanced data structures, specifically pointers, to manage dynamic memory allocation and de-allocation. It also covers using structures to store and access records efficiently, along with File Operations for input and output.";
    courses[7].instructor = "Mrs. LULU";

    courses[8].code = "Eng2004";
    courses[8].title = "Digital Logic Design";
    courses[8].creditHours = 3;
    courses[8].year = 2;
    courses[8].semester = 2;
    courses[8].description = "Digital Logic Design introduces the fundamental building blocks of digital systems and computer hardware. It starts with number systems, Boolean algebra, and logic gates used to simplify digital circuits. The course covers combinational logic circuits like adders, decoders, and multiplexers, as well as sequential logic including flip-flops, counters, and registers. Students learn to design and analyze synchronous and asynchronous circuits while understanding how memory elements work. Practical lab sessions involve building and testing circuits to bridge the gap between theoretical logic and physical hardware implementation.";
    courses[8].instructor = "Mrs. LULU";

    courses[9].code = "SWEG2106";
    courses[9].title = "Data Communication and Computer Networks";
    courses[9].creditHours = 4;
    courses[9].year = 2;
    courses[9].semester = 2;
    courses[9].description = "This course explores the principles and protocols used in modern computer networking. It follows the OSI and TCP/IP layered models to explain how data travels from one device to another over various transmission media. Key topics include physical layer signaling, data link layer error detection, and MAC addressing. The course covers network layer routing, transport layer reliability (TCP/UDP), and common application layer protocols like HTTP and DNS. Students gain hands-on experience in the lab configuring IP addresses, understanding subnets, and simulating network topologies to solve connectivity issues.";
    courses[9].instructor = "Mrs. LULU";

    courses[10].code = "SWEG2108";
    courses[10].title = "Database Systems";
    courses[10].creditHours = 4;
    courses[10].year = 2;
    courses[10].semester = 2;
    courses[10].description = "Database Systems focuses on the design, implementation, and management of relational databases. It covers the Entity-Relationship (ER) modeling technique to map real-world data requirements into structured database schemas. Students learn the relational model, normalization to reduce data redundancy, and the use of Structured Query Language (SQL) for data definition and manipulation. The course also introduces database security, transaction management, and concurrency control to ensure data integrity. In the lab, students work with database management systems (DBMS) like MySQL or PostgreSQL to build and query functional databases for software applications.";
    courses[10].instructor = "Mrs. LULU";

    courseCount = 11;

    char runAgain = 'y';

    while (runAgain == 'y' || runAgain == 'Y')
    {
        cout << "    COURSE REVIEW SYSTEM - AASTU\n";

        cout << "1. View Course Overview\n";
        cout << "2. Exit\n\n";

        int mainChoice;
        cout << "Enter choice (1-2): ";
        cin >> mainChoice;

        // Keep asking until valid main menu choice
        while (mainChoice < 1 || mainChoice > 2)
        {
            cout << "Invalid choice! Please enter 1 or 2: ";
            cin >> mainChoice;
        }
        if (mainChoice == 1)
        {
            char viewMore = 'y';

            while (viewMore == 'y' || viewMore == 'Y')
            {
                cout << "        COURSE OVERVIEW\n";

                cout << "Select Academic Year:\n";
                cout << "1. Year 2\n";
                cout << "2. Year 3\n";
                cout << "3. Year 4\n";
                cout << "4. Year 5\n\n";

                int year;
                cout << "Enter choice (1-4): ";
                cin >> year;

                // Keep asking until valid year
                while (year < 1 || year > 4)
                {
                    cout << "Invalid year selection! Please enter a number between 1 and 4: ";
                    cin >> year;
                }

                year = year + 1; // Convert to actual year number

                cout << "\nSelect Semester:\n";
                cout << "1. Semester 1\n";
                cout << "2. Semester 2\n\n";
                int semester;
                cout << "Enter choice (1-2): ";
                cin >> semester;

                // Keep asking until valid semester
                while (semester != 1 && semester != 2)
                {
                    cout << "Invalid semester selection! Please enter 1 or 2: ";
                    cin >> semester;
                }

                Course *availableCourses[50];
                int availableCount = 0;

                // Filter courses by year and semester
                for (int i = 0; i < courseCount; i++)
                {
                    if (courses[i].year == year && courses[i].semester == semester)
                    {
                        availableCourses[availableCount] = &courses[i];
                        availableCount++;
                    }
                }

                if (availableCount == 0)
                {
                    cout << "\nNo courses found for Year " << year
                         << ", Semester " << semester << ".\n";
                    cout << "Do you want to try another selection? (y/n): ";
                    cin >> viewMore;
                    if (viewMore == 'n' || viewMore == 'N')
                    {
                        break;
                    }
                    continue;
                }

                cout << "Available Courses:\n";
                for (int i = 0; i < availableCount; i++)
                {
                    cout << i + 1 << ". " << availableCourses[i]->code << " - "
                         << availableCourses[i]->title << " ("
                         << availableCourses[i]->creditHours << " credits)\n";
                }

                cout << "\n0. Back to Main Menu\n\n";
                int courseChoice;
                cout << "Select a course (0-" << availableCount << "): ";
                cin >> courseChoice;

                // Keep asking until valid course choice
                while (courseChoice < 0 || courseChoice > availableCount)
                {
                    cout << "Invalid course selection! Please enter a number between 0 and "
                         << availableCount << ": ";
                    cin >> courseChoice;
                }

                if (courseChoice == 0)
                {
                    break;
                }

                Course *selectedCourse = availableCourses[courseChoice - 1];
                displayCourseDetails(selectedCourse);

                cout << "Do you want to view another course? (y/n): ";
                cin >> viewMore;
            }
        }
        else if (mainChoice == 2)
        {
            cout << "\nExiting system...\n";
            break;
        }

        cout << "\nDo you want to use the system again? (y/n): ";
        cin >> runAgain;
        cin.ignore();
    }

    cout << "\nThank you for using the AASTU Course Review System!\n";
    cout << "Goodbye!\n";

    return 0;
}