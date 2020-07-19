//
// Created by arslan on 13/7/20.
//

#include "/home/arslan/CLionProjects/digitaldesign/include/Circuits.h"
#include "/home/arslan/CLionProjects/digitaldesign/include/ReadData.h"
#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

// Inputs
const std::string input_a = "0000000000000000000000000000000000000000000000000000000000001110";
const std::string input_b = "0000000000000000000000000000000000000000000000000000000000000010";
std::string input_single = "0000000000000000000000000000000000000000000000000000000000000000";

// Expected outputs
const std::string ADDER_OUTPUT = "0000000000000000000000000000000000000000000000000000000000010000";
const std::string SUBTRACTOR_OUTPUT = "0000000000000000000000000000000000000000000000000000000000001100";
const std::string MULT64_OUTPUT = "0000000000000000000000000000000000000000000000000000000000011100";
const std::string  DIVISION_OUTPUT = "0000000000000000000000000000000000000000000000000000000000000111";
const std::string ZERO_EQUAL_OUTPUT = "1";

std::string get_output(std::string file_path, int output_bit_size)
{
    // Create and instance of ReadData class and called constructor
    ReadData text_file_read(file_path);

    // Get the data from text File
    std::vector<std::vector<std::string>> data_list = text_file_read.get_data();

    // Create an instance of Circuit class
    Circuits* circuit_obj = new Circuits;

    // circuit_obj calling to its member function i.e display_circuit
    circuit_obj->display_circuit(data_list);

    // Input A and B 64-bits
    char* char_array1 = circuit_obj->read_inputs_A(input_a);
    char* char_array2 = circuit_obj->read_inputs_B(input_b);

    std::vector<unsigned int> return_wires = circuit_obj->arithmetic_functions(data_list, char_array1, char_array2);

    std::ostringstream oss;
    std::string str(output_bit_size, 'x');

    if (!return_wires.empty())
    {
        // Convert all but the last element to avoid a trailing ","
        std::copy(return_wires.begin(), return_wires.end() - 1, std::ostream_iterator<int>(oss, ""));

        // Now add the last element with no delimiter
        oss << return_wires.back();
    }

    std::vector<unsigned int> index;
    int counter = 0;

    for (int l = return_wires.size() - 1; l > 0; --l)
    {
        index.push_back(l);
        counter += 1;
        if (counter >= 64)
            break;
    }

    int c = 0;
    std::cout << std::endl;
    for (std::vector<unsigned int>::iterator it = index.begin(); it != index.end(); ++it)
    {
        str[c] = oss.str()[*it];
        c += 1;
        /*  std::cout << oss.str()[*it];*/
    }
    delete circuit_obj;

    return str;
}

TEST(DigitalDesignTest, adder_test)
{
    /////////////////////////////////////// Load Test Data /////////////////////////////////////
    std::string file_path;
    file_path = "../data/arithmetic-functions/adder64.txt";
    std::string adder_out = get_output(file_path, 64);

    ASSERT_EQ(adder_out, ADDER_OUTPUT);
}

TEST(DigitalDesignTest, subtractor_test)
{
    /////////////////////////////////////// Load Test Data /////////////////////////////////////
    std::string file_path;
    file_path = "../data/arithmetic-functions/sub64.txt";
    std::string subtractor_out = get_output(file_path, 64);

    ASSERT_EQ(subtractor_out, SUBTRACTOR_OUTPUT);
}

TEST(DigitalDesignTest, multiplication_test)
{
    /////////////////////////////////////// Load Test Data /////////////////////////////////////
    std::string file_path;
    file_path = "../data/arithmetic-functions/mult2_64.txt";
    std::string subtractor_out = get_output(file_path,64);

    ASSERT_EQ(subtractor_out, MULT64_OUTPUT);
}


TEST(DigitalDesignTest, division_test)
{
    /////////////////////////////////////// Load Test Data /////////////////////////////////////
    std::string file_path;
    file_path = "../data/arithmetic-functions/divide64.txt";
    std::string subtractor_out = get_output(file_path,64);

    ASSERT_EQ(subtractor_out, DIVISION_OUTPUT);
}



TEST(DigitalDesignTest, zero_equal_test)
{
    /////////////////////////////////////// Load Test Data /////////////////////////////////////
    std::string file_path;
    file_path = "../data/arithmetic-functions/zero_equal.txt";
    std::string zero_equal_output = get_output(file_path,1);

    ASSERT_EQ(zero_equal_output, ZERO_EQUAL_OUTPUT);
}



int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}