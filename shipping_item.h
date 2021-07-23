#ifndef SHIPPING_ITEM_H
#define SHIPPING_ITEM_H
#include <string>

struct Address{
    std::string name;
    std::string street_address;
    std::string city;
    std::string state;
    std:: string zip;
};

class ShippingItem{
protected:
    Address shippers_address_;
    double shipping_weight_;
    double shipping_length_;
    bool is_delivered_;

public:
    static const double kMaxWeight;
    static const double kMaxSize;
    static const double kMinSize;

    //constructors
    ShippingItem();
    ShippingItem(Address address, double weight, double length);
    ~ShippingItem() {}

    //getters
    Address get_address() const { return shippers_address_; }
    double get_weight() const { return shipping_weight_; }
    double get_length() const { return shipping_length_; }
    bool get_delivered() const { return is_delivered_; }

    //setters
    void set_address(Address address);
    void set_weight(double weight);
    virtual void set_length(double length);
    void set_delivered(bool delivered);

    //other methods
    void MarkDelivered();
    virtual double Volume() const = 0;
    virtual void Display(std::ostream &out) const = 0;
};

#endif