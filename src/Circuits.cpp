//
// Created by arslan on 7/7/20.
//

#include "../inlcude/Circuits.h"
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::vector<std::string>> Circuits::get_data()
{
    // read the circuit data from file path
    std::string file_path = file_path_;

    // read the circuit data from given file path
    std::ifstream file(file_path);

    if (!file)
        std::cerr << "Could not open the file!" << std::endl;
    else
    {
        // create vector of vector  of type string
        std::vector<std::vector<std::string>> data_list;

        std::string line = "";
        /*Iterate through each line and split the content using delimeter*/
        while (getline(file, line))
        {
            std::vector<std::string> vec;
            boost::algorithm::split(vec, line, boost::is_any_of(delimeter_));
            data_list.push_back(vec);
        }
        /*Close the File*/
        file.close();

        return data_list;
    }
}

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

    total_gates = std::stoi(data_list[0][0]);
    total_wires = std::stoi(data_list[0][1]);

    total_num_input = std::stoi(data_list[1][0]);
    inputs_bits = std::stoi(data_list[1][1]);

    total_num_outputs = std::stoi(data_list[2][0]);
    outputs_bits = std::stoi(data_list[2][1]);

    std::cout << "No. of gates: " << total_gates << std::endl;
    std::cout << "No. of wires: " << total_wires << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "No. of inputs: " << total_num_input << std::endl;
    std::cout << "No. of input bits: " << inputs_bits << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "No. of outputs: " << total_num_outputs << std::endl;
    std::cout << "No. of output bits: " << outputs_bits << std::endl;

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
                xor_count += 1;
            }
            // count AND
            else if (data_list[k][5] == "AND")
            {
                and_count += 1;
            }
        }
        // make sure to count only INV gates
        else if (data_list[k].size() == 5)
        {
            // INV operation
            if (data_list[k][4] == "INV")
            {
                inv_count += 1;
            }
        }
    }

    std::cout << "No. of XOR: " << xor_count << "\n"
              << "No. of AND: " << and_count << "\n"
              << "No. of INV: " << inv_count << std::endl;
}



void Circuits::copy_inputs(const std::vector<std::vector<std::string>>& data_list,  const char& char_array1, const char& char_array2)
{
    //////////////////////////////////////////////// Copy Input A and B //////////////////////////////////////////////////
    // gates index and save them in respective arrays start from here
    for (int k = 4; k <= 67; ++k) {
        // check XOR and AND gates only
        if (data_list[k].size() == 6) {
            // XOR data to be saved in array
            if (data_list[k][5] == "XOR") {
                // Copy inputs A
                wire[std::stoi(data_list[k][2])] = char_array1[k - 4] - 48;
                // Copy inputs B
                wire[std::stoi(data_list[k][3])] = char_array2[k - 4] - 48;
            }
        }
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;


}