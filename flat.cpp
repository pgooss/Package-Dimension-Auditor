#include "flat.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/**
 * @brief non-default constructor - this constructor accepts an address weight,length, height, and thickness when being set up.
 *                                  It also try's the to set each value and catches any out_of_range exceptions thrown.
 * @param address - a structure made of strings about the shippers address.
 * @param weight - a double value for the weight of the shipping item.
 * @param length - a double value for the length of the shipping item.
 * @param height - a double value for the height of the shipping item.
 * @param thickness - a double value for the thickness of the shipping item.
 */
Flat::Flat(Address address, double weight, double length, double height, double thickness)
{
    try
    {
        set_address(address);
        set_weight(weight);
        set_length(length);
        set_height(height);
        set_thickness(thickness);
    }
    catch (out_of_range e)
    {
        throw;
    }
}

/**
 * @brief setter- this method attempts to set the length of flat item and throws an exception if it is smaller than
 *                than kMinSize or larger than 15.
 * @param length - a double value for the length of the shipping item.
 */
void Flat::set_length(double length)
{
    if(length < kMinSize || length > 15)
    {
        throw std::out_of_range("The length of this item does not meet size standards.");
    }

    shipping_length_ = length;
}

/**
 * @brief setter- this method attempts to set the height of flat item and throws an exception if it is smaller than
 *                than kMinSize or larger than 12.
 * @param height - a double value for the height of the shipping item.
 */
void Flat::set_height(double height)
{
    if(height < kMinSize || height > 12)
    {
        throw std::out_of_range("The height of this item does not meet size standards.");
    }

    height_ = height;
}

/**
 * @brief setter- this method attempts to set the length of flat item and throws an exception if it is smaller than
 *                than kMinSize or larger than 0.75.
 * @param thickness - a double value for the thickness of the shipping item.
 */
void Flat::set_thickness(double thickness)
{
    thickness_ = thickness;

    if(thickness_ < kMinSize)
    {
        throw std::out_of_range("The thickness of this item does not meet size standards.");
    }
    if(thickness_ > 0.75)
    {
        throw std::out_of_range("The thickness of this item does not meet size standards.");
    }


}

/**
 *  @brief - This method calculates volume by using length, height and thickness and then returns the value as a double.
 * @return - returns a double for the volume found.
 */
double Flat::Volume() const
{
    return shipping_length_ * height_ * thickness_;
}

/**
 * @brief - this method prints the information about the flat shipping item in an easy to read format.
 * @param out - the ostream object that determines how the print will be handled whether written to a console or a file.
 */
void Flat::Display(std::ostream &out) const
{
    out << std::setprecision(1) << std::fixed << "Flat: " << shipping_weight_ << " lbs. " << shipping_length_
        << " x " << height_ << " x " << thickness_ << endl;
}

