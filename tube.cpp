#include "tube.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const double Tube::kPi = 3.14159;


/**
 * @brief non-default constructor - This is the constructor for non-default values passed to it. It tries
 *                                  all of the setters and catches an out of range exception if thrown.
 * @param address - a structure made of strings
 * @param weight - a double value for the weight
 * @param length - a double value for the length
 * @param circumference - a double value for circumference
 */
Tube::Tube(Address address, double weight, double length, double circumference)
{
    set_address(address);

    try
    {
        set_weight(weight);
        set_length(length);
        set_circumference(circumference);
    }
    catch (out_of_range e)
    {
        throw;
    }

}

/**
 * @brief - This is the setter for the circumference. It checks if it is less than kMin size or if it's
 *          circumference plus length would be greater than kMaxSize. If so it throws an out of range exception.
 * @param circumference
 */
void Tube::set_circumference(double circumference)
{
    circumference_ = circumference;

    if (circumference < kMinSize || circumference + shipping_length_ > kMaxSize) {
        throw out_of_range("The circumference of the item is too small or big for shipping");
    }
}

/**
 * @brief - This method calculates the volume of the tube shipping item.
 * @return it returns the calculate volume as a double.
 */
double Tube::Volume() const
{
   return kPi * (circumference_ / (2 * kPi) ) * (circumference_ / (2 * kPi) ) * shipping_length_;
}

/**
 * @brief - the method is for finding and returning the girth. (The girth is the same as the circumference).
 * @return - it returns the circumference as a double value.
 */
double Tube::Girth() const
{
    return circumference_;
}

/**
 * @brief - this method prints the information about the tube shipping item in an easy to read format.
 * @param out - the ostream object that determines how the print will be handled whether written to a console or a file.
 */
void Tube::Display(std::ostream &out) const
{
    out << setprecision(1) << fixed << "Tube: " << shipping_weight_ << " lbs. " << shipping_length_
        << " x " << circumference_ << endl;
}