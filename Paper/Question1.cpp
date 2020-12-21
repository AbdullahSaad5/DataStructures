#include <iostream>
#include <string>
using namespace std;

class student
{
public:
    int rollNo;
    string name;

    void input()
    {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        getline(cin, name);
        getline(cin, name);
    }

    void output()
    {
        cout << "Roll Number: " << rollNo << endl;
        cout << "Name: " << name << endl;
    }
};

class result
{
public:
    int marks1;
    int marks2;
    int marks3;

    void input()
    {
        cout << "Enter Marks 1: ";
        cin >> marks1;
        cout << "Enter Marks 2: ";
        cin >> marks2;
        cout << "Enter Marks 3: ";
        cin >> marks3;
    }

    void output()
    {
        cout << "Marks1: " << marks1 << endl;
        cout << "Marks2: " << marks2 << endl;
        cout << "Marks3: " << marks3 << endl;
        totalMarks();
        averageMarks();
    }

    void totalMarks()
    {
        cout << "Total: " << marks1 + marks2 + marks3 << endl;
    }

    void averageMarks()
    {
        double average = (marks1 + marks2 + marks3) / 3.0;
        cout << "Average: " << average << endl;
    }
};

class Info
{
public:
    student s;
    result r;
    void input()
    {
        s.input();
        r.input();
    }
    void personalInfo()
    {
        cout << "Personal Information" << endl;
        s.output();
        cout << "Result Card" << endl;
        r.output();
    }
};

int main()
{
    Info i;
    i.input();
    i.personalInfo();
}