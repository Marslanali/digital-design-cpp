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
    // XOR, AND and INV count
    int xor_count_ = 0;
    int and_count_ = 0;
    int inv_count_ = 0;
    // print the all data to the console
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "\n=========================  Print All Data  ============================\n" << std::endl;
    for (int i = 0; i < data_list.size(); ++i)
    {
        for (int j = 0; j < data_list[i].size(); ++j)
        {
            std::cout << data_list[i][j] << " ";
        }
        std::cout << "\n" << std::endl;
    }

    total_gates_ = std::stoi(data_list[0][0]);
    total_wires_ = std::stoi(data_list[0][1]);

    total_num_input_ = std::stoi(data_list[1][0]);
    inputs_bits_ = std::stoi(data_list[1][1]);

    total_num_outputs_ = std::stoi(data_list[2][0]);
    outputs_bits_ = std::stoi(data_list[2][1]);

    std::cout << "No. of gates: " << total_gates_ << std::endl;
    std::cout << "No. of wires: " << total_wires_ << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "No. of inputs: " << total_num_input_ << std::endl;
    std::cout << "No. of input bits: " << inputs_bits_ << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "No. of outputs: " << total_num_outputs_ << std::endl;
    std::cout << "No. of output bits: " << outputs_bits_ << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    ////////////////////////////////////////// Read Circuit Total Gates /////////////////////////////////////////////////
    // read all gates data, count gates to be used in next index arrays
    for (int k = 4; k < data_list.size(); ++k)
    {
        // make sure to count only XOR gates
        if (data_list[k].size() == 6)
        {
            // count XOR
            if (data_list[k][5] == "XOR")
            {
                xor_count_ += 1;
            }
            // count AND
            else if (data_list[k][5] == "AND")
            {
                and_count_ += 1;
            }
        }
        // make sure to count only INV gates
        else if (data_list[k].size() == 5)
        {
            // INV operation
            if (data_list[k][4] == "INV")
            {
                inv_count_ += 1;
            }
        }
    }

    std::cout << "No. of XOR: " << xor_count_ << "\n"
              << "No. of AND: " << and_count_ << "\n"
              << "No. of INV: " << inv_count_ << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
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

    std::cout << "Input A (64 bits): " << std::endl;
    for (int i = 0; i < n; i++)
        std::cout << char_array1[i];
    std::cout << std::endl;
    std::cout << std::endl;

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

    std::cout << "Input B (64 bits): " << std::endl;
    for (int i = 0; i < m; i++)
        std::cout << char_array2[i];
    std::cout << std::endl;
    std::cout << std::endl;

    return char_array2;
}

std::vector<unsigned int> Circuits::test_adder_sub64(const std::vector<std::vector<std::string>>& data_list, char* char_array1, char* char_array2)
{
    // Total wires
    unsigned int wires[total_wires_];
    //////////////////////////////////////////////// Copy Input A and B /////////////////////////////////////////////////
    // gates index and save them in respective arrays start from here
    for (int k = 4; k <= 67; ++k)
    {
        // check XOR and AND gates only
        if (data_list[k].size() == 6)
        {
            // XOR data to be saved in array
            if (data_list[k][5] == "XOR")
            {
                // Copy inputs A
                wires[std::stoi(data_list[k][2])] = *char_array1 - 48;
                //increment pointer for next element fetch
                char_array1++;
                // Copy inputs B
                wires[std::stoi(data_list[k][3])] = *char_array2 - 48;
                //increment pointer for next element fetch
                char_array2++;
            }
        }
    }

    ////////////////////////////////////////// 64-bit ADDER / SUBTRACTOR Start From Here ////////////////////////////////
    // gates index and save them in respective arrays start from here
    for (int k = 4; k < data_list.size(); ++k)
    {
        // check XOR and AND gates only
        std::cout << std::endl;
        std::cout << "\n=========================  XOR/AND BLOCKS # " << k - 4 << "  ============================\n" << std::endl;
        if (data_list[k].size() == 6)
        {
            // XOR data to be saved in array
            if (data_list[k][5] == "XOR")
            {
                // stores every gates wires in respective arrays
                wires[std::stoi(data_list[k][4])] = wires[std::stoi(data_list[k][2])] ^ wires[std::stoi(data_list[k][3])];
                std::cout << "Wires: : " << std::stoi(data_list[k][2]) << " " << std::stoi(data_list[k][3]) << " " << std::stoi(data_list[k][4]) << " "
                          << std::endl;
                std::cout << "XOR GATE : " << wires[std::stoi(data_list[k][2])] << " " << wires[std::stoi(data_list[k][3])] << " "
                          << wires[std::stoi(data_list[k][4])] << " " << std::endl;
            }
            // check INV gate only
            else if (data_list[k][5] == "AND")
            {
                // stores every gates wires index in respective arrays
                wires[std::stoi(data_list[k][4])] = wires[std::stoi(data_list[k][2])] & wires[std::stoi(data_list[k][3])];
                std::cout << "Wires: : " << std::stoi(data_list[k][2]) << " " << std::stoi(data_list[k][3]) << " " << std::stoi(data_list[k][4]) << " "
                          << std::endl;
                std::cout << "AND GATE : " << wires[std::stoi(data_list[k][2])] << " " << wires[std::stoi(data_list[k][3])] << " "
                          << wires[std::stoi(data_list[k][4])] << " " << std::endl;
            }
        }
        // check INV gate only
        else if (data_list[k].size() == 5)
        {
            // INV gate data to be store in array
            if (data_list[k][4] == "INV")
            {
                wires[std::stoi(data_list[k][3])] = !wires[std::stoi(data_list[k][2])];
                std::cout << "Wires: : " << std::stoi(data_list[k][2]) << " " << std::stoi(data_list[k][3]) << " " << std::endl;
                std::cout << "INV GATE : " << wires[std::stoi(data_list[k][2])] << " " << wires[std::stoi(data_list[k][3])] << " " << std::endl;
            }
        }
    }

    std::cout << std::endl;

    // copy array to vector to return
    wires_vec_.resize(total_wires_);
    std::copy(wires + 0, wires + total_wires_ - 1, wires_vec_.begin());

    return wires_vec_;
}

void Circuits::display_output(std::vector<unsigned int> wires_temp)
{
    ///////////////////////////////////////////////// Final Output //////////////////////////////////////////////////////
    std::vector<unsigned int> ind_xor_final;
    int counter = 0;

    for (int l = total_wires_ - 1; l > 0; --l)
    {
        ind_xor_final.push_back(l);
        counter += 1;
        if (counter >= 64)
            break;
    }

    for (std::vector<unsigned int>::iterator it = ind_xor_final.begin(); it != ind_xor_final.end(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << std::endl;
    std::cout << std::endl;

    for (std::vector<unsigned int>::iterator it = ind_xor_final.begin(); it != ind_xor_final.end(); ++it)
    {
        std::cout << wires_temp[*it];
    }
    std::cout << std::endl;
    std::cout << std::endl;
}
