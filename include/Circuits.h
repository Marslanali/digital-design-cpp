//
// Created by arslan on 7/7/20.
//

#ifndef DIGITALDESIGN_CIRCUITS_H
#define DIGITALDESIGN_CIRCUITS_H

#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <fstream>
#include <iostream>
#include <iterator>
#include <math.h>
#include <memory>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

#define INPUT_BITS 64

/*
enum GateType
{
    XOR,
    AND,
    INV
};

typedef struct
{
    std::string XOR, AND, INV;
} GateTypes;

 */

class Circuits
{
  private:
    // Circuits parameters
    unsigned int total_gates_;
    unsigned int total_wires_;

    unsigned int total_num_input_;
    unsigned int inputs_bits_;

    unsigned int total_num_outputs_;
    unsigned int outputs_bits_;

    // XOR, AND and INV count
    unsigned int xor_count_, and_count_, inv_count_;

    // Inputs
    std::string input_a_;
    std::string input_b_;

  public:

    // No argument constructor
    Circuits(){};

    // Read inputs
    char* read_inputs_A(std::string input_a);
    char* read_inputs_B(std::string input_b);

    // print the all circuit data to the console
    void display_circuit(const std::vector<std::vector<std::string>>& data_list);

    // 64-bit adder subtractor implementation
    void test_adder_sub64(const std::vector<std::vector<std::string>>& data_list, char* char_array1, char* char_array2);

    // display output
    void display_output();
};

#endif // DIGITALDESIGN_CIRCUITS_H
