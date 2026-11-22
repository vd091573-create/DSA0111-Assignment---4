#include <iostream>
using namespace std;

class Person {
public:
    string name;
    int id;
    string phone;

    Person() {
        cout << "Person ";
    }
};

class Student : virtual public Person {
public:
    string programme;
    float cgpa;

    Student() {
        cout << "Student ";
    }
};

class Staff : virtual public Person {
public:
    string department;
    double salary;

    Staff() {
        cout << "Staff ";
    }
};

class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant() {
        cout << "TA ";
    }
};

class ResearchScholar : public Student {
public:
    double fellowship;
};

int main() {
    TeachingAssistant ta;
    cout << endl;

    return 0;
}