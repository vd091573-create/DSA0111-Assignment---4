

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

const double RATE = 0.42;

class Staff {
protected:
    string name;
    int id;

public:
    Staff(string n, int i) : name(n), id(i) {}
    virtual double pay() = 0;
    virtual ~Staff() {}

    void display() {
        cout << name << " : Rs " << pay() << endl;
    }
};

class Professor : public Staff {
    double basic, research;

public:
    Professor(string n, int i, double b, double r)
        : Staff(n,i), basic(b), research(r) {}

    double pay() override {
        return basic + basic * RATE + research;
    }
};

class LabAssistant : public Staff {
    double basic;

public:
    LabAssistant(string n, int i, double b)
        : Staff(n,i), basic(b) {}

    double pay() override {
        return basic + basic * RATE;
    }
};

class GuestFaculty : public Staff {
    double hours, rate;

public:
    GuestFaculty(string n, int i, double h, double r)
        : Staff(n,i), hours(h), rate(r) {}

    double pay() override {
        return hours * rate;
    }
};

int main() {
    vector<Staff*> staff;

    staff.push_back(new Professor("John",101,50000,10000));
    staff.push_back(new LabAssistant("David",102,30000));
    staff.push_back(new GuestFaculty("Sam",103,20,1000));

    for(auto s : staff) {
        s->display();
        delete s;
    }

    return 0;
}
