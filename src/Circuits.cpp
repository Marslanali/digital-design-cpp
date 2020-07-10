//
// Created by arslan on 7/7/20.
//

#include "../inlcude/Circuits.h"
#include <iostream>
#include <string>
#include <vector>

// print the all circuit data to the console
void Circuits::display_circuit(const std::vector<std::vector<std::string>>& data_list)
{
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
}

// Read inputs
char* Circuits::read_inputs()
{

}

void Circuits::test_adder_sub64(const std::vector<std::vector<std::string>>& data_list, char* char_array1, char* char_array2)
{
    // Total wires
    unsigned int wires[total_wires_];
    //////////////////////////////////////////////// Copy Input A and B ////////////////////////////////////////////////
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

    ////////////////////////////////////////// 64-bit Subtractor Start From Here /////////////////////////////////////////
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

    ///////////////////////////////////////////////// Final Output //////////////////////////////////////////////////////
    std::vector<int> ind_xor_final;
    int counter = 0;

    for (int l = total_wires_ - 1; l > 0; --l)
    {
        ind_xor_final.push_back(l);
        counter += 1;
        if (counter >= 64)
            break;
    }

    for (std::vector<int>::iterator it = ind_xor_final.begin(); it != ind_xor_final.end(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << std::endl;
    std::cout << std::endl;

    for (std::vector<int>::iterator it = ind_xor_final.begin(); it != ind_xor_final.end(); ++it)
    {
        std::cout << wires[*it];
    }
    std::cout << std::endl;
    std::cout << std::endl;
}
