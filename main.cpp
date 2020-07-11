//
// Created by arslan on 7/7/20.
//

#include "../digitaldesign/include/Circuits.h"
#include "../digitaldesign/include/ReadData.h"
#include <iostream>
#include <memory>
#include <string>
#include <vector>

// 64 bits inputs
std::string input_a = "0010101101100010101010101000101010101001010110110011011110001010";
std::string input_b = "0000010101101100010101010101000101010101001010110110011011110000";

int main(int argc, char** argv)
{
    // Create and instance of ReadData class and called constructor
    ReadData text_file_read(argv[1]);

    // Get the data from text File
    std::vector<std::vector<std::string>> data_list = text_file_read.get_data();

    // Create an instance of Circuit class
    Circuits* circuit_obj = new Circuits;

    // circuit_obj calling to its member function i.e display_circuit
    circuit_obj->display_circuit(data_list);

    ////////////////////////////////////// Inputs A & B  ///////////////////////////////////////////////////
    // Input A and B 64-bits
    char* char_array1 = circuit_obj->read_inputs_A(input_a);
    char* char_array2 = circuit_obj->read_inputs_B(input_b);

    ////////////////////////////////////// Call 64-but adder/subtractor ////////////////////////////////////
    circuit_obj->test_adder_sub64(data_list, char_array1, char_array2);

    delete circuit_obj;

    return 0;
}
