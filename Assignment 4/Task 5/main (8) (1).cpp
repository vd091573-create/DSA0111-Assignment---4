#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Cart {
    string items[10];
    double prices[10];
    int n = 0;
    double discount = 0;

public:
    Cart& add(string item, double price) {
        items[n] = item;
        prices[n] = price;
        n++;
        return *this;
    }

    Cart& setDiscount(double discount) {
        this->discount = discount;
        return *this;
    }

    double total() const {
        double t = 0;
        for (int i = 0; i < n; i++)
            t += prices[i];

        return t * (100 - discount) / 100;
    }
};

int main() {
    Cart c;

    // Direct access
    c.add("Rice", 60).add("Dal", 120).setDiscount(10);

    // Pointer access
    Cart* p = &c;
    p->add("Oil", 180);

    // Reference access
    Cart& r = c;
    r.total();

    // Dynamic pointer
    Cart* q = new Cart;
    q->add("Milk", 50);
    delete q;

    cout << fixed << setprecision(2) << p->total();

    return 0;
}

