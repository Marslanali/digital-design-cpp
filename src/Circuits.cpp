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
    /* std::cout << std::endl;
    std::cout << "\n=========================  Print All Data  ============================\n" << std::endl;
    for (int i = 0; i < data_list.size(); ++i)
    {
        for (int j = 0; j < data_list[i].size(); ++j)
        {
            std::cout << data_list[i][j] << " ";
        }
        std::cout << "\n" << std::endl;
    }*/

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

    /*    ////////////////////////////////////////// Read Circuit Total Gates /////////////////////////////////////////////////
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
    std::cout << std::endl;*/
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
                /* std::cout << "Wires: : " << std::stoi(data_list[k][2]) << " " << std::stoi(data_list[k][3]) << " " << std::stoi(data_list[k][4]) << " "
                          << std::endl;
                std::cout << "XOR GATE : " << wires[std::stoi(data_list[k][2])] << " " << wires[std::stoi(data_list[k][3])] << " "
                          << wires[std::stoi(data_list[k][4])] << " " << std::endl;*/
            }
            // check INV gate only
            else if (data_list[k][5] == "AND")
            {
                // stores every gates wires index in respective arrays
                wires[std::stoi(data_list[k][4])] = wires[std::stoi(data_list[k][2])] & wires[std::stoi(data_list[k][3])];
                /*    std::cout << "Wires: : " << std::stoi(data_list[k][2]) << " " << std::stoi(data_list[k][3]) << " " << std::stoi(data_list[k][4]) << " "
                          << std::endl;
                std::cout << "AND GATE : " << wires[std::stoi(data_list[k][2])] << " " << wires[std::stoi(data_list[k][3])] << " "
                          << wires[std::stoi(data_list[k][4])] << " " << std::endl;*/
            }
        }
        // check INV gate only
        else if (data_list[k].size() == 5)
        {
            // INV gate data to be store in array
            if (data_list[k][4] == "INV")
            {
                wires[std::stoi(data_list[k][3])] = !wires[std::stoi(data_list[k][2])];
                /*  std::cout << "Wires: : " << std::stoi(data_list[k][2]) << " " << std::stoi(data_list[k][3]) << " " << std::endl;
                std::cout << "INV GATE : " << wires[std::stoi(data_list[k][2])] << " " << wires[std::stoi(data_list[k][3])] << " " << std::endl;*/
            }
        }
    }

    std::cout << std::endl;

    // copy array to vector to return
    wires_vec_.resize(total_wires_);
    std::copy(wires, wires + total_wires_, wires_vec_.begin());

    return wires_vec_;
}
/*

std::vector<unsigned int> Circuits::test_mul64(const std::vector<std::vector<std::string>>& data_list, char* char_array1, char* char_array2)
{
    // Total wires
    unsigned int wires[total_wires_];
    //////////////////////////////////////////////// Copy Input A and B ////////////////////////////////////////////////
    // gates index and save them in respective arrays start from here
    for (int k = 127; k >= 64; --k)
    {
        // Copy inputs A
        wires[k] = *char_array1 - 48;
        //increment pointer for next element fetch
        char_array1++;
    }

    for (int k = 63; k >= 0; --k)
    {
        // Copy inputs B
        wires[k] = *char_array2 - 48;
        //increment pointer for next element fetch
        char_array2++;
    }

    ////////////////////////////////////////// 64-bit mul Start From Here /////////////////////////////////////////
    // gates index and save them in respective arrays start from here
    for (int k = 4; k < data_list.size(); ++k)
    {
        // check XOR and AND gates only
        std::cout << "\n=========================  XOR/AND BLOCKS # " << k - 4 << "  ============================\n" << std::endl;
        if (data_list[k].size() == 6)
        {
            // XOR data to be saved in array
            if (data_list[k][5] == "AND")
            {
                // stores every gates wires in respective arrays
                wires[std::stoi(data_list[k][4])] = wires[std::stoi(data_list[k][2])] & wires[std::stoi(data_list[k][3])];
                std::cout << "Wires: : " << std::stoi(data_list[k][2]) << " " << std::stoi(data_list[k][3]) << " " << std::stoi(data_list[k][4]) << " " << std::endl;
                std::cout << "AND GATE : " << wires[std::stoi(data_list[k][2])] << " " << wires[std::stoi(data_list[k][3])] << " " << wires[std::stoi(data_list[k][4])] << " "
                          << std::endl;
            }
            // check INV gate only
            else if (data_list[k][5] == "XOR")
            {
                // stores every gates wires index in respective arrays
                wires[std::stoi(data_list[k][4])] = wires[std::stoi(data_list[k][2])] ^ wires[std::stoi(data_list[k][3])];
                std::cout << "Wires: : " << std::stoi(data_list[k][2]) << " " << std::stoi(data_list[k][3]) << " " << std::stoi(data_list[k][4]) << " " << std::endl;
                std::cout << "XOR GATE : " << wires[std::stoi(data_list[k][2])] << " " << wires[std::stoi(data_list[k][3])] << " " << wires[std::stoi(data_list[k][4])] << " "
                          << std::endl;
            }
        }
    }

    std::cout << std::endl;

    // copy array to vector to return
    wires_vec_.resize(total_wires_);
    std::copy(wires, wires + total_wires_, wires_vec_.begin());

    return wires_vec_;
}
*/

void Circuits::display_output(std::vector<unsigned int> wires_temp, int output_bit_size)
{
    ///////////////////////////////////////////////// Final Output //////////////////////////////////////////////////////
    std::vector<unsigned int> index;
    int counter = 0;

    for (int l = total_wires_ - 1; l > 0; --l)
    {
        index.push_back(l);
        counter += 1;
        if (counter >= output_bit_size)
            break;
    }

    std::cout << std::endl;
    std::cout << "Output " << output_bit_size << " bits: " << std::endl;
    std::cout << std::endl;

    for (std::vector<unsigned int>::iterator it = index.begin(); it != index.end(); ++it)
    {
        std::cout << wires_temp[*it];
    }

    std::cout << std::endl;
    std::cout << std::endl;
}

void Circuits::display_output_mul64(std::vector<unsigned int> wires_temp, int output_bit_size)
{

    std::vector<unsigned int> index1;
    int counter1 = 0;

    for (int l = 28087; l >= 28033; --l)
    {
        index1.push_back(l);
        counter1 += 1;
        if (counter1 >= 64)
            break;
    }

    std::vector<unsigned int> index2;
    int counter2 = 0;

    for (int l = 28154; l >= 28088; --l)
    {
        index2.push_back(l);
        counter2 += 1;
        if (counter2 >= 64)
            break;
    }

    std::cout << std::endl;
    std::cout << "Output " << 128 << " bits: " << std::endl;
    std::cout << std::endl;

    for (std::vector<unsigned int>::iterator it = index1.begin(); it != index1.end(); ++it)
    {
        std::cout << wires_temp[*it];
    }

    for (std::vector<unsigned int>::iterator it = index2.begin(); it != index2.end(); ++it)
    {
        std::cout << wires_temp[*it];
    }
}