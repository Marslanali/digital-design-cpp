//
// Created by arslan on 7/7/20.
//

#ifndef DIGITALDESIGN_CIRCUITS_H
#define DIGITALDESIGN_CIRCUITS_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <fstream>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>
#include <vector>

#define TOTAL_WIRES 504

enum GateType
{
    XOR = 0,
    AND = 0,
    INV = 0
};

class Circuits
{
  private:

    // file reading variables
    std::string file_path_;
    std::string delimeter_;

    // Circuits parameters
    unsigned int total_gates;
    unsigned int total_wires;

    unsigned int total_num_input;
    unsigned int inputs_bits;

    unsigned int total_num_outputs;
    unsigned int outputs_bits;

    // XOR, AND and INV count
    unsigned int xor_count, and_count, inv_count;

  public:

    // Total wires
    unsigned int wires[TOTAL_WIRES];

    // No argument contructor
    Circuits(){};

    // Two argument constructor
    Circuits(std::string file_path, std::string delimeter_ = " ") : file_path_(file_path), delimeter_(delimeter_)
    {

    }

    /*Function to fetch data from a text File*/
    std::vector<std::vector<std::string>> get_data();

    // print the all circuit data to the console
    void display_circuit(const std::vector<std::vector<std::string>>&  data_list);
    void copy_inputs(const std::vector<std::vector<std::string>>& data_list, char* char_array1, char* char_array2);
    void test_adder64(const std::vector<std::vector<std::string>>& data_list);
    void display_output();
    int total_num_wires();

};

#endif // DIGITALDESIGN_CIRCUITS_H
