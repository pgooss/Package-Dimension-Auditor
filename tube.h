#ifndef TUBE_H
#define TUBE_H

#include <iostream>
#include "shipping_item.h"

class Tube : public ShippingItem{
private:
    double circumference_;

public:
    //variable
    static const double kPi;

    //constructors
    Tube() : circumference_(12) {}
    Tube(Address address, double weight, double length, double circumference);
    ~Tube() {}

    //getter
    double get_circumference() const { return circumference_; }

    //setter
    void set_circumference(double circumference);

    //other methods
    double Volume() const;
    double Girth() const;
    void Display(std::ostream &out) const;
};

#endif