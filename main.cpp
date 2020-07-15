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

    ////////////////////////////////////// ADDER / SUB  ///////////////////////////////////////////////////

    // Create and instance of ReadData class and called constructor
    ReadData text_file_read1("/home/arslan/CLionProjects/digitaldesign/data/arithmetic-functions/adder64.txt");

    // Get the data from text File
    std::vector<std::vector<std::string>> data_list1 = text_file_read1.get_data();

    // Create an instance of Circuit class
    Circuits* circuit_obj1 = new Circuits;

    // circuit_obj calling to its member function i.e display_circuit
    circuit_obj1->display_circuit(data_list1);

    // Input A and B 64-bits
    char* char_array1 = circuit_obj1->read_inputs_A(input_a);
    char* char_array2 = circuit_obj1->read_inputs_B(input_b);

    std::vector<unsigned int> return_wires = circuit_obj1->test_adder_sub64(data_list1, char_array1, char_array2);
    circuit_obj1->display_output(return_wires);
    delete circuit_obj1;

    //////////////////////////////////////  MULTIPLIER  ///////////////////////////////////////////////////

    // Create and instance of ReadData class and called constructor
    ReadData text_file_read2("/home/arslan/CLionProjects/digitaldesign/data/arithmetic-functions/mult64.txt");

    // Get the data from text File
    std::vector<std::vector<std::string>> data_list2 = text_file_read2.get_data();

    // Create an instance of Circuit class
    Circuits* circuit_obj2 = new Circuits;

    // circuit_obj calling to its member function i.e display_circuit
    circuit_obj2->display_circuit(data_list2);

    std::vector<unsigned int> return_wires2 = circuit_obj2->test_mul64(data_list2, char_array1, char_array2);
    circuit_obj2->display_output(return_wires2);
    delete circuit_obj2;

    return 0;
}
