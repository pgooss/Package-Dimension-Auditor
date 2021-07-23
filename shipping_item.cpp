#include "shipping_item.h"
#include <iostream>
#include <string>

using namespace std;

const double ShippingItem::kMaxWeight = 70.0;
const double ShippingItem::kMaxSize = 108.0;
const double ShippingItem::kMinSize = 0.007;

/**
 * brief - default constructor. It set's the default values for the constructor without user input.
 */
ShippingItem::ShippingItem() : shipping_weight_(2.0), shipping_length_(12.0), is_delivered_(false)
{
    Address obj1;
    obj1.name = "unknown";
    set_address(obj1);

}

/**
 * @brief non-default constructor - this constructor accepts an address weight and length when being set up.
 * @param address - a structure made of strings about the shippers address.
 * @param weight - a double value for the weight of the shipping item.
 * @param length - a double value for the length of the shipping item.
 */
ShippingItem::ShippingItem(Address address, double weight, double length)
{
    set_address(address);
    set_weight(weight);
    set_length(length);
}

/**
 * brief - this functions set's the address to the value sent in.
 *
 * @param address - string value sent by user.
 */
void ShippingItem::set_address(Address address)
{
    shippers_address_ = address;
}

/**
 * brief - this function checks if weight is less than zero
 *         if it is set value as 0 otherwise set as weight;
 * @param weight - a double sent by the user for the shipping item's weight.
 */
void ShippingItem::set_weight(double weight)
{
    shipping_weight_ = weight;

    if(weight < 0 || weight > kMaxWeight)
    {
        throw out_of_range("Unable to ship. This item does not meet the weight standards.");
    }

}

/**
 *  brief - this function makes sure the item is within the size limits.
 *          If it does not meet the size standards it will throw an exception.
 *          If it does meet standards, the value is set.
 * @param length - a double sent by user for the shipping item's length.
 */
void ShippingItem::set_length(double length)
{
    shipping_length_ = length;

    if(length < kMinSize || length > kMaxSize)
    {
        throw out_of_range("Unable to ship. This item does not meet the size limits.");
    }
}

/**
 *  brief - the function sets the value to true or false for if the item was delivered.
 *
 * @param delivered - a bool value sent by the user for if it was delivered.
 */
void ShippingItem::set_delivered(bool delivered)
{
    is_delivered_ = delivered;
}

/**
 * brief - this method sets delivered to true when called.
 */
void ShippingItem::MarkDelivered()
{
    is_delivered_ = true;
}



