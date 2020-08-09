//
// Created by arslan on 7/7/20.
//

#include "../include/Circuits.h"
#include <iostream>
#include <string>
#include <vector>

// print the all circuit data to the console
void Circuits::display_circuit(const std::vector<std::vector<std::string>>& data_list) {
  total_gates_ = std::stoi(data_list[0][0]);
  total_wires_ = std::stoi(data_list[0][1]);

  total_num_input_ = std::stoi(data_list[1][0]);
  inputs_bits_ = std::stoi(data_list[1][1]);

  total_num_outputs_ = std::stoi(data_list[2][0]);
  outputs_bits_ = std::stoi(data_list[2][1]);
}

// Read inputs A
char* Circuits::read_inputs_A(const std::string& input_a) {
  // 64 bits input
  input_a_ = input_a;

  int n = input_a_.length();

  static char* char_array1 = new char[n];

  // copying the contents of the
  // string to char array
  strcpy(char_array1, input_a_.c_str());

  /*std::cout << "Input A (" << n << " bits): " << std::endl;*/
  /*for (int i = 0; i < n; i++) std::cout << char_array1[i];*/
  /*std::cout << std::endl;*/
  /*std::cout << std::endl;*/

  return char_array1;
}

// Read inputs B
char* Circuits::read_inputs_B(const std::string& input_b) {
  // 64 bits input
  input_b_ = input_b;

  int m = input_b_.length();

  static char* char_array2 = new char[m];

  // copying the contents of the
  // string to char array
  strcpy(char_array2, input_b_.c_str());

  /*std::cout << "Input B (" << m << " bits): " << std::endl;*/
  /*for (int i = 0; i < m; i++) std::cout << char_array2[i];*/

  return char_array2;
}

std::vector<int> Circuits::arithmetic_functions(const std::vector<std::vector<std::string>>& data_list, char* char_array1,
                                                char* char_array2, int input_a_size, int input_b_size) {
  // Total wires
  int wires[total_wires_];

  // gates index and save them in respective arrays start from here
  for (int k = 0; k <= input_a_size - 1; ++k) {
    // Copy inputs B
    wires[k] = *char_array1 - 48;
    // increment pointer for next element fetch
    char_array1++;
  }

  if (char_array2 != nullptr) {
    for (int k = input_a_size; k <= input_a_size + input_b_size - 1; ++k) {
      // Copy inputs A
      wires[k] = *char_array2 - 48;
      // increment pointer for next element fetch
      char_array2++;
    }
  }

  // gates index and save them in respective arrays start from here
  for (int k = 4; k < data_list.size(); ++k) {
    // check XOR and AND gates only
    if (data_list[k].size() == 6) {
      // XOR data to be saved in array
      if (data_list[k][5] == GATE[XOR]) {
        // stores every gates wires in respective arrays
        wires[std::stoi(data_list[k][4])] = wires[std::stoi(data_list[k][2])] ^ wires[std::stoi(data_list[k][3])];
      }
      // check INV gate only
      else if (data_list[k][5] == GATE[AND]) {
        // stores every gates wires index in respective arrays
        wires[std::stoi(data_list[k][4])] = wires[std::stoi(data_list[k][2])] & wires[std::stoi(data_list[k][3])];
      }
    }
    // check INV gate only
    else if (data_list[k].size() == 5) {
      // INV gate data to be store in array
      if (data_list[k][4] == GATE[INV]) {
        wires[std::stoi(data_list[k][3])] = !wires[std::stoi(data_list[k][2])];
      }

      else if (data_list[k][4] == GATE[EQW]) {
        wires[std::stoi(data_list[k][3])] = wires[std::stoi(data_list[k][2])];
      }
    }
  }

  std::cout << std::endl;

  // copy array to vector to return
  wires_vec_.resize(total_wires_);
  std::copy(wires, wires + total_wires_, wires_vec_.begin());

  return wires_vec_;
}

void Circuits::display_output(std::vector<int> wires_temp, int output_bit_size) {
  std::cout << "Output " << output_bit_size << " bits: " << std::endl;
  std::vector<unsigned int> index;
  int counter = 0;

  for (unsigned int l = total_wires_ - 1; l > 0; --l)
  /*for (unsigned int l = total_wires_ - output_bit_size; l <= total_wires_ - 1; ++l)*/ {
    index.push_back(l);
    counter += 1;
    if (counter >= output_bit_size) break;
  }

  for (std::vector<unsigned int>::iterator it = index.begin(); it != index.end(); ++it) {
    std::cout << wires_temp[*it];
  }
  std::cout << std::endl;
  std::cout << std::endl;
}
