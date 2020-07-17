//
// Created by arslan on 7/7/20.
//

#include "../include/Circuits.h"
#include <iostream>
#include <string>
#include <vector>

// print the all circuit data to the console
void Circuits::display_circuit(const std::vector<std::vector<std::string>>& data_list)
{

    total_gates_ = std::stoi(data_list[0][0]);
    total_wires_ = std::stoi(data_list[0][1]);

    total_num_input_ = std::stoi(data_list[1][0]);
    inputs_bits_ = std::stoi(data_list[1][1]);

    total_num_outputs_ = std::stoi(data_list[2][0]);
    outputs_bits_ = std::stoi(data_list[2][1]);

}

// Read inputs A
char* Circuits::read_inputs_A(std::string input_a)
{
    // 64 bits input
    input_a_ = input_a;
    ////////////////////////////////////////////////// Input Data A //////////////////////////////////////////////////////
    int n = input_a_.length();

    static char char_array1[64];

    // copying the contents of the
    // string to char array
    strcpy(char_array1, input_a_.c_str());

    return char_array1;
}

// Read inputs B
char* Circuits::read_inputs_B(std::string input_b)
{
    // 64 bits input
    input_b_ = input_b;
    ////////////////////////////////////////////////// Input Data B //////////////////////////////////////////////////////
    int m = input_b_.length();

    static char char_array2[64];

    // copying the contents of the
    // string to char array
    strcpy(char_array2, input_b_.c_str());

    return char_array2;
}

std::vector<unsigned int> Circuits::arithmetic_functions(const std::vector<std::vector<std::string>>& data_list, char* char_array1, char* char_array2)
{
    // Total wires
    unsigned int wires[total_wires_];
    //////////////////////////////////////////////// Copy Input A and B ////////////////////////////////////////////////
    // gates index and save them in respective arrays start from here
    for (int k = 63; k >= 0; --k)
    {
        // Copy inputs B
        wires[k] = *char_array1 - 48;
        //increment pointer for next element fetch
        char_array1++;
    }
    for (int k = 127; k >= 64; --k)
    {
        // Copy inputs A
        wires[k] = *char_array2 - 48;
        //increment pointer for next element fetch
        char_array2++;
    }
    ////////////////////////////////////////// Arithmetic Function Start From Here ////////////////////////////////////////
    // gates index and save them in respective arrays start from here
    for (int k = 4; k < data_list.size(); ++k)
    {
        // check XOR and AND gates only
        /* std::cout << std::endl;
        std::cout << "\n=========================  XOR/AND BLOCKS # " << k - 4 << "  ============================\n" << std::endl;*/
        if (data_list[k].size() == 6)
        {
            // XOR data to be saved in array
            if (data_list[k][5] == "XOR")
            {
                // stores every gates wires in respective arrays
                wires[std::stoi(data_list[k][4])] = wires[std::stoi(data_list[k][2])] ^ wires[std::stoi(data_list[k][3])];

            }
                // check INV gate only
            else if (data_list[k][5] == "AND")
            {
                // stores every gates wires index in respective arrays
                wires[std::stoi(data_list[k][4])] = wires[std::stoi(data_list[k][2])] & wires[std::stoi(data_list[k][3])];

            }
        }
            // check INV gate only
        else if (data_list[k].size() == 5)
        {
            // INV gate data to be store in array
            if (data_list[k][4] == "INV")
            {
                wires[std::stoi(data_list[k][3])] = !wires[std::stoi(data_list[k][2])];

            }
        }
    }

    std::cout << std::endl;

    // copy array to vector to return
    wires_vec_.resize(total_wires_);
    std::copy(wires, wires + total_wires_, wires_vec_.begin());

    return wires_vec_;
}

