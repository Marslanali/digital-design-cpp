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

    // Inputs
    std::string input_a_;
    std::string input_b_;

    std::vector<unsigned int> wires_vec_;

  public:
    // No argument constructor
    Circuits(){};

    // Read inputs
    char* read_inputs_A(std::string input_a);
    char* read_inputs_B(std::string input_b);

    // print the all circuit data to the console
    void display_circuit(const std::vector<std::vector<std::string>>& data_list);

    // arithmetic_functions implementation
    std::vector<unsigned int> arithmetic_functions(const std::vector<std::vector<std::string>>& data_list, char* char_array1, char* char_array2);

    // display output
    void display_output(std::vector<unsigned int> wires_temp, int output_bit_size);
    void display_output_mul64(std::vector<unsigned int> wires_temp, int output_bit_size);
    void display_output_div64(std::vector<unsigned int> wires_temp, int output_bit_size);

};

#endif // DIGITALDESIGN_CIRCUITS_H
