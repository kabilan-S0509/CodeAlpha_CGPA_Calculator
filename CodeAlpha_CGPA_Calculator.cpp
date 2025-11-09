#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

struct Course {
    double grade;   // numeric (e.g., 9.0 or 8.5 or on 4.0 scale)
    double credit;  // credit hours
};

int main() {
    cout << "==============================" << endl;
    cout << "       CGPA CALCULATOR        " << endl;
    cout << "==============================" << endl;

    int numSemesters = 1;
    cout << "Enter number of semesters to include (e.g., 1 for this term only): ";
    cin >> numSemesters;

    if (numSemesters <= 0) {
        cout << "Error: Number of semesters must be >= 1." << endl;
        return 0;
    }

    double overallTotalCredits = 0.0;
    double overallTotalGradePoints = 0.0;

    for (int s = 1; s <= numSemesters; ++s) {
        cout << "\n----- SEMESTER " << s << " -----" << endl;

        int numCourses;
        cout << "Enter the number of courses: ";
        cin >> numCourses;

        if (numCourses <= 0) {
            cout << "Error: Number of courses must be >= 1." << endl;
            return 0;
        }

        vector<Course> courses(numCourses);
        double semTotalCredits = 0.0;
        double semTotalGradePoints = 0.0;

        for (int i = 0; i < numCourses; ++i) {
            cout << "\nCourse " << (i + 1) << ":" << endl;
            cout << "Enter grade (numeric, e.g., 9.0 or 3.7): ";
            cin >> courses[i].grade;
            cout << "Enter credit hours: ";
            cin >> courses[i].credit;

            semTotalCredits += courses[i].credit;
            semTotalGradePoints += courses[i].grade * courses[i].credit;
        }

        if (semTotalCredits == 0) {
            cout << "\nError: Total credits for the semester cannot be zero!" << endl;
            return 0;
        }

        double semGPA = semTotalGradePoints / semTotalCredits;

        // Display per-course table
        cout << fixed << setprecision(2);
        cout << "\nCourses Summary (Semester " << s << ")\n";
        cout << left << setw(10) << "Course" 
             << setw(12) << "Grade" 
             << setw(14) << "Credits" 
             << setw(16) << "Grade Points" << endl;
        cout << string(52, '-') << endl;

        for (int i = 0; i < numCourses; ++i) {
            double gp = courses[i].grade * courses[i].credit;
            cout << left << setw(10) << (to_string(i + 1))
                 << setw(12) << courses[i].grade
                 << setw(14) << courses[i].credit
                 << setw(16) << gp << endl;
        }

        cout << string(52, '-') << endl;
        cout << left << setw(22) << "Semester Totals:"
             << setw(14) << semTotalCredits
             << setw(16) << semTotalGradePoints << endl;

        cout << "Semester GPA: " << semGPA << "\n";

        // Accumulate for overall CGPA
        overallTotalCredits += semTotalCredits;
        overallTotalGradePoints += semTotalGradePoints;
    }

    // Overall CGPA across all semesters
    double cgpa = overallTotalGradePoints / overallTotalCredits;

    cout << "\n========== OVERALL RESULT ==========" << endl;
    cout << fixed << setprecision(2);
    cout << "Overall Credits Earned : " << overallTotalCredits << endl;
    cout << "Overall Grade Points   : " << overallTotalGradePoints << endl;
    cout << "Overall CGPA           : " << cgpa << endl;
    cout << "===================================" << endl;

    // Friendly remark
    if (cgpa >= 9.0)
        cout << "Excellent Performance! 🎓" << endl;
    else if (cgpa >= 8.0)
        cout << "Very Good! Keep it up!" << endl;
    else if (cgpa >= 7.0)
        cout << "Good job! You can aim higher!" << endl;
    else if (cgpa >= 6.0)
        cout << "Average performance. Keep working!" << endl;
    else
        cout << "Needs improvement. Don't give up!" << endl;

    return 0;
}
