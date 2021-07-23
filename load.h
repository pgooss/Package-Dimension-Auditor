#ifndef LOAD_H
#define LOAD_H

#include <vector>
#include <string>
#include <fstream>
#include "shipping_item.h"

class Load {
private:
    int curr_index_ = 0;
    int count_ = 0;
    double total_weight_ = 0;
    double total_volume_ = 0;

public:
    //constructors
    Load() : curr_index_(0), count_(0), total_weight_(0), total_volume_(0) {}
    ~Load();

    //getters
    int get_count() const { return  count_; }
    double get_total_volume() const { return total_volume_; }
    double get_total_weight() const { return  total_weight_; }

    //other methods
    void FillLoad(std::string filename);
    void DisplayNextDelivery(std::ofstream &out) const;
    void ItemDelivered();
    void NotDeliverable();
    int HowManyDelivered() const;
    int HowManyNotDelivered() const;
};
#endif