//
// Created by arslan on 13/7/20.
//

#include "../include/Circuits.h"
#include "../include/Constants.h"
#include "../include/ReadData.h"
#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

std::string conversion_fun(std::vector<unsigned int> return_wires, int output_size)
{
    std::ostringstream oss;
    std::string str(output_size, 'x');

    if (!return_wires.empty())
    {
        // Convert all but the last element to avoid a trailing ","
        std::copy(return_wires.begin(), return_wires.end() - 1, std::ostream_iterator<int>(oss, ""));

        // Now add the last element with no delimiter
        oss << return_wires.back();
    }

    std::vector<unsigned int> index;
    int counter = 0;

    for (int l = return_wires.size() - output_size; l <= return_wires.size() - 1; ++l)
    {
        index.push_back(l);
        counter += 1;
        if (counter >= output_size)
            break;
    }

    int c = 0;
    std::cout << std::endl;
    //for (std::vector<unsigned int>::iterator it = index.begin(); it != index.end(); ++it)
    for (unsigned int& it : index)
    {
        str[c] = oss.str()[it];
        c += 1;
        /*  std::cout << oss.str()[*it];*/
    }

    return str;
}

std::string get_output(const std::string& file_path, const int input_a_size, const int input_b_size, int output_size)
{
    // Create and instance of ReadData class and called constructor
    ReadData text_file_read(file_path);

    // Get the data from text File
    std::vector<std::vector<std::string>> data_list = text_file_read.get_data();

    // Create an instance of Circuit class
    auto* circuit_obj = new Circuits;

    // circuit_obj calling to its member function i.e display_circuit
    circuit_obj->display_circuit(data_list);

    if (input_b_size != 0)
    {
        // Key
        std::string key(input_a_size, '0');
        // Message
        std::string message(input_b_size, '1');

        // Input A and B 64-bits
        char* char_array1 = circuit_obj->read_inputs_A(key);
        char* char_array2 = circuit_obj->read_inputs_B(message);

        std::vector<unsigned int> return_wires =
            circuit_obj->arithmetic_functions(data_list, char_array1, char_array2, input_a_size, input_b_size);

        return conversion_fun(return_wires, output_size);
    }

    else
    {
        char* char_array;
        char_array = (char*)malloc(input_a_size * sizeof(char));

        // Key
        std::string key(input_a_size, '0');

        // Input A 64-bits
        char_array = circuit_obj->read_inputs_A(key);

        std::vector<unsigned int> return_wires =
            circuit_obj->arithmetic_functions(data_list, char_array, nullptr, input_a_size, input_b_size);

        return conversion_fun(return_wires, output_size);
    }
}

TEST(DigitalDesignTest, KECCAK_TEST)
{
    /////////////////////////////////////// Load Test Data /////////////////////////////////////
    std::string file_path;
    file_path = "../data/cryptographic-functions/Keccak_f.txt";
    std::string keccak_out = get_output(file_path, 1600, 0, 1600);

    ASSERT_EQ(keccak_out, KECCAK_OUTPUT);
}

TEST(DigitalDesignTest, SHA_512_TEST)
{
    /////////////////////////////////////// Load Test Data /////////////////////////////////////
    std::string file_path;
    file_path = "../data/cryptographic-functions/sha512.txt";
    std::string sha_512_out = get_output(file_path, 1024, 512, 512);

    ASSERT_EQ(sha_512_out, SHA_512_OUTPUT);
}

TEST(DigitalDesignTest, SHA_256_TEST)
{
    /////////////////////////////////////// Load Test Data /////////////////////////////////////
    std::string file_path;
    file_path = "../data/cryptographic-functions/sha256.txt";
    std::string sha_256_out = get_output(file_path, 512, 256, 256);

    ASSERT_EQ(sha_256_out, SHA_256_OUTPUT);
}

TEST(DigitalDesignTest, AES_256_TEST)
{
    /////////////////////////////////////// Load Test Data /////////////////////////////////////
    std::string file_path;
    file_path = "../data/cryptographic-functions/aes_256.txt";
    std::string aes_256_test = get_output(file_path, 256, 128, 128);

    ASSERT_EQ(aes_256_test, AES_256_OUTPUT);
}

TEST(DigitalDesignTest, AES_192_TEST)
{
    /////////////////////////////////////// Load Test Data /////////////////////////////////////
    std::string file_path;
    file_path = "../data/cryptographic-functions/aes_192.txt";
    std::string aes_192_test = get_output(file_path, 192, 128, 128);

    ASSERT_EQ(aes_192_test, AES_192_OUTPUT);
}

TEST(DigitalDesignTest, AES_128_TEST)
{
    /////////////////////////////////////// Load Test Data /////////////////////////////////////
    std::string file_path;
    file_path = "../data/cryptographic-functions/aes_128.txt";
    std::string aes_128_out = get_output(file_path, 128, 128, 128);

    ASSERT_EQ(aes_128_out, AES_128_OUTPUT);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
