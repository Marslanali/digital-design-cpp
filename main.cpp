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
std::string input_a1 = "0010101101100010101010101000101010101001010110110011011110001010";
std::string input_b1 = "0000010101101100010101010101000101010101001010110110011011110000";

// to check mult64
std::string input_a2 = "0000000000000000000000000000000000000000000000000000000000001110"; // Decimal = 14
std::string input_b2 = "0000000000000000000000000000000000000000000000000000000000000010"; // Decimal = 2
                                                                                           // Div = 7, Mul = 28
// to check div64
std::string input_a3 = "0000000000000000000000000000000000000000000000000000000000001111"; // Decimal = 15
std::string input_b3 = "0000000000000000000000000000000000000000000000000000000000000011"; // Decimal = 3
                                                                                           // Div = 5, Mul = 45

// to check div64
std::string input_a4 = "0000000000000000000000000000000000000000000000000000000000011110"; // Decimal = 30
std::string input_b4 = "0000000000000000000000000000000000000000000000000000000000001010"; // Decimal = 10
                                                                                           // Div = 3, Mul = 300

std::string input_single = "0000000000000000000000000000000000000000000000000000000000000011";

void test_arithmetic(std::string file_path, int output_size)
{
    ////////////////////////////////////// Arithmetic Functions ///////////////////////////////////////////////////
    // Create and instance of ReadData class and called constructor
    ReadData text_file_read(file_path);

    // Get the data from text File
    std::vector<std::vector<std::string>> data_list = text_file_read.get_data();

    // Create an instance of Circuit class
    Circuits* circuit_obj = new Circuits;

    // circuit_obj calling to its member function i.e display_circuit
    circuit_obj->display_circuit(data_list);

    if (file_path == "../data/arithmetic-functions/neg64.txt" || file_path == "../data/arithmetic-functions/zero_equal.txt")
    {
        // Input A 64-bits
        char* char_array1 = circuit_obj->read_inputs_A(input_single);

        std::vector<unsigned int> return_wires = circuit_obj->arithmetic_functions2(data_list, char_array1);
        circuit_obj->display_output(return_wires, output_size);
    }

    else
    {
        // Input A and B 64-bits
        char* char_array1 = circuit_obj->read_inputs_A(input_a2);
        char* char_array2 = circuit_obj->read_inputs_B(input_b2);

        std::vector<unsigned int> return_wires = circuit_obj->arithmetic_functions(data_list, char_array1, char_array2);
        circuit_obj->display_output(return_wires, output_size);
    }

    delete circuit_obj;
}

int main(int argc, char** argv)
{
    std::cout << "================== Testing adder64 ======================" << std::endl;
    test_arithmetic("../data/arithmetic-functions/adder64.txt", 64);

    std::cout << "================== Testing subt64 ======================== " << std::endl;
    test_arithmetic("../data/arithmetic-functions/sub64.txt", 64);

    std::cout << "================== Testing mult128 ========================" << std::endl;
    test_arithmetic("../data/arithmetic-functions/mult2_64.txt", 128);

    std::cout << "================== Testing mult64 ========================" << std::endl;
    test_arithmetic("../data/arithmetic-functions/mult64.txt", 64);

    std::cout << "================== Testing div64 ========================== " << std::endl;
    test_arithmetic("../data/arithmetic-functions/divide64.txt", 64);

    std::cout << "================== Testing unsigned div64 ========================== " << std::endl;
    test_arithmetic("../data/arithmetic-functions/udivide64.txt", 64);

    std::cout << "================== Testing neg64 ========================== " << std::endl;
    test_arithmetic("../data/arithmetic-functions/neg64.txt", 64);

    std::cout << "================== Testing zero equal ========================== " << std::endl;
    test_arithmetic("../data/arithmetic-functions/zero_equal.txt", 1);

    return 0;
}
