#include <iostream>
#include <vector>
using namespace std;

class Subject {
public:
    string subjectname;
    int credit;
    float grade;

    Subject(string name, int cr, float gr) {
        subjectname = name;
        credit = cr;
        grade = gr;
    }
};

class Student {
public:
    string name;
    vector<Subject> subjects;

    Student(string studentname) {
        name = studentname;
    }

    void addSubject(string subjectname, int credit, float grade) {
        Subject newsubject(subjectname, credit, grade);
        subjects.push_back(newsubject);
    }

    float calculateCgpa() {
        int totalcredit = 0;
        float weightgrade = 0;

        for (const Subject &subject:subjects) {
            totalcredit += subject.credit;
            weightgrade += subject.credit * subject.grade;
        }

        return (totalcredit>0)?(weightgrade/totalcredit):0;
    }

    void displayCgpa() {
        cout << "Student name : " << name;
        float Cgpa = calculateCgpa();
        cout << "CGPA : " << Cgpa;
    }
    void addsubject(string subjectname,int credit,float grade);
};

int main() {
    string studentname;
    int numsub;

    cout << "Enter student's name: ";
    getline(cin, studentname);

    cout << "Enter number of subjects: ";
    cin >> numsub;
    cin.ignore();

    Student student(studentname);

    for(int i = 0; i < numsub; i++) {
        string subjectname;
        int credit;
        float grade;

        cout << "Enter subject name: ";
        getline(cin, subjectname);

        cout << "Enter the credit: ";
        cin >> credit;

        cout << "Enter the grade: ";
        cin >> grade;
        cin.ignore();

        student.addSubject(subjectname, credit, grade);
    }

    student.displayCgpa();
    return 0;
}
