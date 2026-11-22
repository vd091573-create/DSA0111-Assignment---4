
#include <iostream>
#include <vector>
using namespace std;

class Vehicle {
protected:
    string reg;
    double rate;
public:
    Vehicle(string r,double d):reg(r),rate(d){}
    virtual double charge(int days)=0;
    virtual void display()=0;
    virtual ~Vehicle(){}
};

class Bicycle: public Vehicle {
public:
    Bicycle(string r,double d):Vehicle(r,d){}
    double charge(int n) override { return rate*n; }
    void display() override {
        cout<<"Bicycle: "<<reg<<" Rs "<<charge(3)<<endl;
    }
};

class Car: public Vehicle {
public:
    Car(string r,double d):Vehicle(r,d){}
    double charge(int n) override { return rate*n; }
    void display() override {
        cout<<"Car: "<<reg<<" Rs "<<charge(3)<<endl;
    }
};

class ElectricCar: public Vehicle {
public:
    ElectricCar(string r,double d):Vehicle(r,d){}
    double charge(int n) override { return rate*n+100; }
    void display() override {
        cout<<"Electric Car: "<<reg<<" Rs "<<charge(3)<<endl;
    }
};

class ElectricBus: public Vehicle {
public:
    ElectricBus(string r,double d):Vehicle(r,d){}
    double charge(int n) override { return rate*n+200; }
    void display() override {
        cout<<"Electric Bus: "<<reg<<" Rs "<<charge(3)<<endl;
    }
};

int main() {
    vector<Vehicle*> v;
    v.push_back(new Bicycle("B101",100));
    v.push_back(new Car("C102",500));
    v.push_back(new ElectricCar("E103",400));
    v.push_back(new ElectricBus("EB104",1000));

    for(auto x:v) {
        x->display();
        delete x;
    }
    return 0;
}
