#include "load.h"
#include <iostream>
#include <fstream>
#include <string>

#include "shipping_item.h"
#include "flat.h"
#include "carton.h"
#include "tube.h"

using namespace std;

//variable
std::vector<ShippingItem*> shippingitem_array;

/**
 * destructor - which dynamically deletes memory from a vector of Shipping Item pointers.
 */
Load::~Load()
{
    for(ShippingItem* &one_ptr: shippingitem_array)
    {
        delete one_ptr;
        one_ptr = NULL;
    }
}

/**
 * @brief - this accepts a file name and reads the information in as a specific type of shipping item
 *          such as tube, flat and carton. It accepts information about the address and other parameters.
 *          It also determines the total weight, total volume and how many items there are total.
 * @param filename
 */
void Load::FillLoad(std::string filename)
{
    ifstream in(filename);
    std::string shipping_type;

    while(in >> shipping_type)
    {
        Address address;
        double side1;
        double side2;
        double side3;
        double weight;
        double length;
        double height;
        double thickness;
        double volume;
        double circumference;

        in.ignore();
        getline(in, address.name);
        getline(in,address.street_address);
        getline(in,address.city);
        getline(in,address.state);
        getline(in,address.zip);



        if(shipping_type == "F")
        {
            in >> weight;
            in >> length;
            in >> height;
            in >> thickness;
            in.ignore();

            shippingitem_array.push_back(new Flat(address, weight, length, height, thickness));
        }

        if(shipping_type == "C")
        {
            in >> weight;
            in >> side1;
            in >> side2;
            in >> side3;
            in.ignore();

            shippingitem_array.push_back(new Carton(address, weight, side1, side2, side3));
        }

        if(shipping_type == "T")
        {
            in >> weight;
            in >> length;
            in >> circumference;
            in.ignore();

            shippingitem_array.push_back(new Tube(address, weight, length, circumference));
        }

        total_weight_ += weight;
        total_volume_ += shippingitem_array[count_]->Volume();
        count_++;

    }

}

void Load::DisplayNextDelivery(std::ofstream &out) const
{
    out << shippingitem_array[curr_index_]->get_address().name << endl
        << shippingitem_array[curr_index_]->get_address().street_address << endl
        << shippingitem_array[curr_index_]->get_address().city << ", " << shippingitem_array[curr_index_]->get_address().state
        << " " << shippingitem_array[curr_index_]->get_address().zip << endl;
    shippingitem_array[curr_index_]->Display(out);
}

/**
 * @brief - it changes the current shipping item looked at to delivered and moves on to the next shipping item
 *          in the list.
 */
void Load::ItemDelivered()
{
    shippingitem_array[curr_index_]->set_delivered(true);
    curr_index_++;

}

/**
 * @brief - it changes the current shipping item looked at to notdelivered and moves on to the next shipping item
 *          in the list.
 */
void Load::NotDeliverable()
{
    shippingitem_array[curr_index_]->set_delivered(false);
    curr_index_++;
}

/**
 * @brief - a method to determine how many packages were delivered.
 * @return - a int total is returned of the total packages delivered.
 */
int Load::HowManyDelivered() const
{
    int total_ = 0;
    for(int i = 0; i < shippingitem_array.size(); ++i)
    {
        if(shippingitem_array[i]->get_delivered() == true)
        {
            total_++;
        }

    }
    return total_;
}

/**
 * @brief - a method to determine how many packages were not delivered.
 * @return - a int total is returned of the total packages not delivered.
 */
int Load::HowManyNotDelivered() const
{
    int total_ = 0;
    for(int i = 0; i < shippingitem_array.size(); ++i)
    {
        if(shippingitem_array[i]->get_delivered() == false)
        {
            total_++;
        }

    }
    return total_;
}

