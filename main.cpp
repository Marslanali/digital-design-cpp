//
// Created by arslan on 7/7/20.
//

#include "/home/arslan/CLionProjects/digitaldesign/inlcude/Circuits.h"
#include <iostream>
#include <memory>
#include <string>
#include <vector>

// 64 bits inputs
std::string input_a = "0010101101100010101010101000101010101001010110110011011110001010";
std::string input_b = "0000010101101100010101010101000101010101001010110110011011110000";

int main(int argc, char** argv)
{
    // Create an instance of Circuit class using smart pointers
    Circuits* circuit_instance = new Circuits;

    /*creating an object of Circuits*/
    Circuits circuit_read(argv[1]);

    /*Get the data from text File*/
    std::vector<std::vector<std::string>> data_list = circuit_read.get_data();

    // circuit_instance calling to its member function i.e display_circuit
    circuit_instance->display_circuit(data_list);

    ////////////////////////////////////////////////// Input Data A //////////////////////////////////////////////////////
    int n = input_a.length();

    // declaring character array
    char char_array1[n + 1];

    // copying the contents of the
    // string to char array
    strcpy(char_array1, input_a.c_str());

    std::cout << "Input A (64 bits): " << std::endl;
    for (int i = 0; i < n; i++)
        std::cout << char_array1[i];
    std::cout << std::endl;
    std::cout << std::endl;

    ////////////////////////////////////////////////// Input Data B //////////////////////////////////////////////////////
    int m = input_b.length();

    // declaring character array
    char char_array2[m + 1];

    // copying the contents of the
    // string to char array
    strcpy(char_array2, input_b.c_str());

    std::cout << "Input B (64 bits): " << std::endl;
    for (int i = 0; i < n; i++)
        std::cout << char_array2[i];
    std::cout << std::endl;
    std::cout << std::endl;

    ///////////////////////////////////////////// Call 64-but adder/subtractor /////////////////////////////////////////
    circuit_instance->copy_inputs(data_list, char_array1, char_array2);
    circuit_instance->test_adder64(data_list);
    circuit_instance->display_output();



        return 0;
}
