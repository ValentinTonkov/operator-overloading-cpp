#include <iostream>
using namespace std;

class Fuel {
private:
    string name;
    double quantity;
    string unit;

public:

    Fuel(const string &name, double quantity, const string &unit) {
        this->quantity = quantity;
        this->name = name;
        this->unit = unit;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Fuel::name = name;
    }

    double getQuantity() const {
        return quantity;
    }

    void setQuantity(double quantity) {
        Fuel::quantity = quantity;
    }

    const string &getUnit() const {
        return unit;
    }

    void setUnit(const string &unit) {
        Fuel::unit = unit;
    }


    void printInfo() {
        cout<<name<<" "<<quantity<<" "<<unit<<endl;
    }

    /*
     * Overloading operator +
     * now fuel object could be added like this
     * fuel3 = fuel1 + fuel2;
     * where fuel1 is the current object, fuel2 is fuelToAdd param
     * and fuel3 is the newFuel that is returned
     *
     * other operators could also be overloaded
     * */
    Fuel operator+(const Fuel & fuelToAdd){
        double q = quantity + fuelToAdd.getQuantity();
        Fuel newFuel (name, q, unit);
        return newFuel;
    }
};




/**
 * Adding two fuels with a function
 * it will be used like this:
 * Fuel f3 = addFuels(fuel1, fuel2);
 * using const reference to to the object
 * in order to avoid copying and modifying
 * */

Fuel addFuels(const Fuel & f1, const Fuel & f2){
    const string& name = f1.getName();
    const string& unit = f1.getUnit();

    double quantity = f1.getQuantity() + f2.getQuantity();
    Fuel newFuel (name, quantity, unit);

    return newFuel;
}

int main() {
    Fuel fuel1("Gasoline", 5.5, "liters");
    Fuel fuel2("Gasoline", 10, "liters");
    Fuel f3 = addFuels(fuel1, fuel2);
    Fuel f4 = f3 + fuel1;

    fuel1.printInfo();
    fuel2.printInfo();
    f3.printInfo();
    f4.printInfo();
    return 0;
}
