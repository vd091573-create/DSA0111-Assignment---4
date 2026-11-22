#include <iostream>
using namespace std;

class Account {
public:
    virtual double rate() const {
        return 3.5;
    }

    virtual ~Account() {}
};

class SeniorAccount : public Account {
public:
    double rate() const override {
        return 4.0;
    }
};

int main() {
    Account* a = new Account();
    Account* s = new SeniorAccount();

    cout << a->rate() << endl;
    cout << s->rate() << endl;

    delete a;
    delete s;

    return 0;
}
