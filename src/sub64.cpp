#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <fstream>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>
#include <vector>

// global variables
int xor_count, and_count, inv_count, index_xor, index_and, index_inv = 0;

// 64 bits inputs
std::string input_a = "0010101101100010101010101000101010101001010110110011011110001010";
std::string input_b = "0000010101101100010101010101000101010101001010110110011011110000";

int main(int argc, char **argv) {
  // read the circuit data from command line
  std::ifstream config_file(argv[1]);
  std::string delimeter_ = " ";
  std::string line = "";
  // create vector of vector  of type string
  std::vector<std::vector<std::string>> data_list;

  /*Iterate through each line and split the content using delimeter*/
  while (getline(config_file, line)) {
    std::vector<std::string> vec;
    boost::algorithm::split(vec, line, boost::is_any_of(delimeter_));
    data_list.push_back(vec);
  }

  // print the all data to console
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "\n=========================  Print All Data  ============================\n" << std::endl;
  for (int i = 0; i < data_list.size(); ++i) {
    for (int j = 0; j < data_list[i].size(); ++j) {
      std::cout << data_list[i][j] << " ";
    }
    std::cout << "\n" << std::endl;
  }

  int total_gates = std::stoi(data_list[0][0]);
  int total_wires = std::stoi(data_list[0][1]);

  int total_num_input = std::stoi(data_list[1][0]);
  int inputs_bits = std::stoi(data_list[1][1]);

  int total_num_outputs = std::stoi(data_list[2][0]);
  int outputs_bits = std::stoi(data_list[2][1]);

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
  //////////////////////////////////// input data A //////////////////////////////////////////////////////
  int n = input_a.length();

  // declaring character array
  char char_array1[n + 1];

  // copying the contents of the
  // string to char array
  strcpy(char_array1, input_a.c_str());

  std::cout << "Input A (64 bits): " << std::endl;
  for (int i = 0; i < n; i++) std::cout << char_array1[i];
  std::cout << std::endl;
  std::cout << std::endl;

  //////////////////////////////////// input data B //////////////////////////////////////////////////////
  int m = input_b.length();

  // declaring character array
  char char_array2[m + 1];

  // copying the contents of the
  // string to char array
  strcpy(char_array2, input_b.c_str());

  std::cout << "Input B (64 bits): " << std::endl;
  for (int i = 0; i < n; i++) std::cout << char_array2[i];
  std::cout << std::endl;
  std::cout << std::endl;

  //////////////////////////////////// Read rest of the circuit data //////////////////////////////////////////////////////
  // read all gates data, count gates to be used in next index arrays
  for (int k = 4; k < data_list.size(); ++k) {
    // make sure to count only XOR gates
    if (data_list[k].size() == 6) {
      // count XOR
      if (data_list[k][5] == "XOR") {
        xor_count += 1;
      }
      // count AND
      else if (data_list[k][5] == "AND") {
        and_count += 1;
      }
    }
    // make sure to count only INV gates
    else if (data_list[k].size() == 5) {
      // INV operation
      if (data_list[k][4] == "INV") {
        inv_count += 1;
      }
    }
  }

  std::cout << "No. of XOR: " << xor_count << "\n"
            << "No. of AND: " << and_count << "\n"
            << "No. of INV: " << inv_count << std::endl;

  int wire[total_wires];

  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  //////////////////////////////////// Copy Input A and B  //////////////////////////////////////////////////////
  // gates index and save them in respective arrays start from here
  for (int k = 4; k <= 67; ++k) {
    // check XOR and AND gates only
    if (data_list[k].size() == 6) {
      // XOR data to be saved in array
      if (data_list[k][5] == "XOR") {
        // Copy inputs A
        wire[std::stoi(data_list[k][2])]= char_array1[k-4] - 48;
        // Copy inputs B
        wire[std::stoi(data_list[k][3])]= char_array2[k-4] - 48;
      }
    }
  }

  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  /////////////////////////////// 64-bit Subtractor Implementation start from here ////////////////////////////
  // gates index and save them in respective arrays start from here
  for (int k = 4; k < data_list.size(); ++k) {
    // check XOR and AND gates only
    std::cout<<std::endl;
    std::cout << "\n=========================  XOR/AND BLOCKS  ============================\n" << std::endl;
    if (data_list[k].size() == 6) {
      // XOR data to be saved in array
      if (data_list[k][5] == "XOR") {
        // stores every gates wires index_xor in respective arrays
        wire[std::stoi(data_list[k][4])] = wire[std::stoi(data_list[k][2])] ^ wire[std::stoi(data_list[k][3])];
        std::cout << "Wires: : " << std::stoi(data_list[k][2]) << " " << std::stoi(data_list[k][3]) << " " << std::stoi(data_list[k][4]) << " " << std::endl;
        std::cout << "XOR GATE : " << wire[std::stoi(data_list[k][2])] << " " << wire[std::stoi(data_list[k][3])] << " " << wire[std::stoi(data_list[k][4])] << " " << std::endl;

      }
      // check INV gate only
      else if (data_list[k][5] == "AND") {
        // stores every gates wires index in respective arrays
        wire[std::stoi(data_list[k][4])] = wire[std::stoi(data_list[k][2])] & wire[std::stoi(data_list[k][3])];
        std::cout << "Wires: : " << std::stoi(data_list[k][2]) << " " << std::stoi(data_list[k][3]) << " " << std::stoi(data_list[k][4]) << " " << std::endl;
        std::cout << "AND GATE : " << wire[std::stoi(data_list[k][2])] << " " << wire[std::stoi(data_list[k][3])] << " " << wire[std::stoi(data_list[k][4])] << " " << std::endl;
      }
    }
    // check INV gate only
    else if (data_list[k].size() == 5) {
      // INV gate data to be store in array
      if (data_list[k][4] == "INV") {
        wire[std::stoi(data_list[k][3])] = !wire[std::stoi(data_list[k][2])];
        std::cout << "Wires: : " << std::stoi(data_list[k][2]) << " " << std::stoi(data_list[k][3]) << " " << std::endl;
        std::cout << "INV GATE : " << wire[std::stoi(data_list[k][2])] << " " << wire[std::stoi(data_list[k][3])] << " " << std::endl;

      }
    }
  }

  std::cout << std::endl;
  std::vector<int> ind_final_xor;
  for (int l = 502; l <= 566; ++l) {
    ind_final_xor.push_back(l);
  }

  for (std::vector<int>::iterator it = ind_final_xor.begin(); it != ind_final_xor.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  std::cout << std::endl;

  for (std::vector<int>::iterator it = ind_final_xor.begin(); it != ind_final_xor.end(); ++it) {
    std::cout << wire[*it];
  }
  std::cout << std::endl;
  std::cout << std::endl;
  /*Close the File*/
  config_file.close();
  return 0;
}
