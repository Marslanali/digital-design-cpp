//
// Created by arslan on 7/7/20.
//

#include "/home/arslan/CLionProjects/digitaldesign/include/Circuits.h"
#include "/home/arslan/CLionProjects/digitaldesign/include/Constants.h"
#include "/home/arslan/CLionProjects/digitaldesign/include/ReadData.h"
#include <iostream>
#include <memory>
#include <string>
#include <vector>

void test_arithmetic(const std::string& file_path, const int input_a_size, const int input_b_size, const int output_size)
{
    ////////////////////////////////////// Arithmetic Functions ///////////////////////////////////////////////////
    // Create and instance of ReadData class and called constructor
    ReadData text_file_read(file_path);

    // Get the data from text File
    std::vector<std::vector<std::string>> data_list = text_file_read.get_data();

    // Create an instance of Circuit class
    auto* circuit_obj = new Circuits;
    // std::shared_ptr<Circuits> circuit_obj = std::make_shared<Circuits>();

    // circuit_obj calling to its member function i.e display_circuit
    circuit_obj->display_circuit(data_list);

    if (input_b_size != 0)
    {
        // Key
        std::string key(input_a_size, 'x');
        // Key
        for (int i = 0; i < input_a_size; ++i)
        {
            key[i] = '0';
        }

        // Message
        std::string message(input_b_size, 'x');

        // Message
        for (int i = 0; i < input_b_size; ++i)
        {
            message[i] = '1';
        }

        // Input A and B 64-bits
        char* char_array1 = circuit_obj->read_inputs_A(key);
        char* char_array2 = circuit_obj->read_inputs_B(message);

        std::vector<unsigned int> return_wires = circuit_obj->arithmetic_functions(data_list, char_array1, char_array2, input_a_size, input_b_size);

        circuit_obj->display_output(return_wires, output_size);
    }

    else
    {
        // Key
        std::string key1(input_a_size, 'x');
        // Key
        for (int i = 0; i < input_a_size; ++i)
        {
            key1[i] = '0';
        }

        // Input A 64-bits
        char* char_array1 = circuit_obj->read_inputs_A(key1);

        std::vector<unsigned int> return_wires = circuit_obj->arithmetic_functions(data_list, char_array1, nullptr, input_a_size, input_b_size);
        circuit_obj->display_output(return_wires, output_size);
    }
}

int main(int argc, char** argv)
{
    try
    {

        std::cout << "================== Testing a AES-128 Circuit ======================" << std::endl;
        test_arithmetic("../data/cryptographic-functions/aes_128.txt", 128, 128, 128);

        std::cout << "================== Testing aes_192 ======================== " << std::endl;
        test_arithmetic("../data/cryptographic-functions/aes_192.txt", 192, 128, 128);

        std::cout << "================== Testing aes_256 ========================" << std::endl;
        test_arithmetic("../data/cryptographic-functions/aes_256.txt", 256, 128, 128);

        std::cout << "================== Testing Keccak_f ========================" << std::endl;
        test_arithmetic("../data/cryptographic-functions/Keccak_f.txt", 1600, 0, 1600);

        std::cout << "================== Testing sha256 ========================== " << std::endl;
        test_arithmetic("../data/cryptographic-functions/sha256.txt", 512, 256, 256);

        std::cout << "================== Testing sha512.txt ========================== " << std::endl;
        test_arithmetic("../data/cryptographic-functions/sha512.txt", 1024, 512, 512);
    }

    catch (const std::runtime_error& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}
