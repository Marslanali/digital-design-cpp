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
  // read circuit data from command line
  std::ifstream config_file(argv[1]);
  std::string delimeter_ = " ";
  std::string line = "";
  // create vector of type string
  std::vector<std::vector<std::string>> data_list;

  /*Iterate through each line and split the content using delimeter*/
  while (getline(config_file, line)) {
    std::vector<std::string> vec;
    boost::algorithm::split(vec, line, boost::is_any_of(delimeter_));
    data_list.push_back(vec);
  }

  for (int i = 0; i < data_list.size(); ++i) {
    for (int j = 0; j < data_list[i].size(); ++j) {
      std::cout << data_list[i][j] << " ";
    }
    std::cout << "\n" << std::endl;
  }

  std::cout << "\nfirst line: " << std::endl;
  for (int j = 0; j < 2; ++j) {
    std::cout << data_list[0][j] << " ";
  }
  std::cout << "\n";

  int total_gates = std::stoi(data_list[0][0]);
  int total_wires = std::stoi(data_list[0][1]);

  int total_num_input = std::stoi(data_list[1][0]);
  int inputs_bits = std::stoi(data_list[1][1]);

  int total_num_outputs = std::stoi(data_list[2][0]);
  int outputs_bits = std::stoi(data_list[2][1]);

  std::cout << "total_gates: " << total_gates << std::endl;
  std::cout << "total_wires: " << total_wires << std::endl;

  //////////////////////////////////// input data A //////////////////////////////////////////////////////
  int n = input_a.length();
  /*std::cout << "input A size: " << n << std::endl;*/

  // declaring character array
  char char_array1[n + 1];

  // copying the contents of the
  // string to char array
  strcpy(char_array1, input_a.c_str());

  for (int i = 0; i < n; i++) std::cout << char_array1[i];
  std::cout << std::endl;

  //////////////////////////////////// input data B //////////////////////////////////////////////////////
  int m = input_b.length();
  /*std::cout << "input B size: " << m << std::endl;*/

  // declaring character array
  char char_array2[m + 1];

  // copying the contents of the
  // string to char array
  strcpy(char_array2, input_b.c_str());

  for (int i = 0; i < n; i++) std::cout << char_array2[i];
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

  std::cout << "XOR count : " << xor_count << " "
            << "AND count : " << and_count << " "
            << "INV count : " << inv_count << std::endl;

  // XOR gate inputs wires index array
  int xor_input1_wires_indexes[xor_count];
  int xor_input2_wires_indexes[xor_count];
  int xor_output_wires_indexes[xor_count];

  // AND gate inputs wires index array
  int and_input1_wires_indexes[and_count];
  int and_input2_wires_indexes[and_count];
  int and_output_wires_indexes[and_count];

  // INV gate inputs wires index array
  int inv_input_wires_indexes[inv_count];
  int inv_output_wires_indexes[inv_count];

  // gates index and save them in respective arrays start from here
  for (int k = 4; k < data_list.size(); ++k) {
    // check XOR and AND gates only
    if (data_list[k].size() == 6) {
      // XOR data to be saved in array
      if (data_list[k][5] == "XOR") {
        // stores every gates wires index_xor in respective arrays
        xor_input1_wires_indexes[index_xor] = std::stoi(data_list[k][2]);  // input 1
        xor_input2_wires_indexes[index_xor] = std::stoi(data_list[k][3]);  // input 2
        xor_output_wires_indexes[index_xor] = std::stoi(data_list[k][4]);  // output
        index_xor += 1;

      }
      // check INV gate only
      else if (data_list[k][5] == "AND") {
        // stores every gates wires index in respective arrays
        and_input1_wires_indexes[index_and] = std::stoi(data_list[k][2]);  // input 1
        and_input2_wires_indexes[index_and] = std::stoi(data_list[k][3]);  // input 2
        and_output_wires_indexes[index_and] = std::stoi(data_list[k][4]);  // output
        index_and += 1;
      }
    }
    // check INV gate only
    else if (data_list[k].size() == 5) {
      // INV gate data to be store in array
      if (data_list[k][4] == "INV") {
        // stores every gates wires index in respective arrays
        inv_input_wires_indexes[index_inv] = std::stoi(data_list[k][2]);   // input
        inv_output_wires_indexes[index_inv] = std::stoi(data_list[k][3]);  // output
        index_inv += 1;
      }
    }
  }

  // print XOR
  std::cout << "\n"
            << "\n";
  std::cout << "print XOR " << std::endl;
  for (int l = 0; l < xor_count; ++l) {
    std::cout << xor_input1_wires_indexes[l] << " " << xor_input2_wires_indexes[l] << " " << xor_output_wires_indexes[l] << " " << std::endl;
  }

  // print AND
  std::cout << "\n"
            << "\n";
  std::cout << "print AND " << std::endl;
  for (int l = 0; l < and_count; ++l) {
    std::cout << and_input1_wires_indexes[l] << " " << and_input2_wires_indexes[l] << " " << and_output_wires_indexes[l] << " " << std::endl;
  }

  // print INV
  std::cout << "\n"
            << "\n";
  std::cout << "print INV " << std::endl;
  for (int l = 0; l < inv_count; ++l) {
    std::cout << inv_input_wires_indexes[l] << " " << inv_output_wires_indexes[l] << " " << std::endl;
  }

  /////////////////////////////// 64-bit Subtractor FIRST STAGE Implementation start from here ////////////////////////////

  // XOR gate vector inputer wires
  // Create a vector of size  with
  // all values as 0
  std::vector<int> xor_input1_wires(total_wires, 0);
  std::vector<int> xor_input2_wires(total_wires, 0);
  std::vector<int> xor_output_wires(total_wires, 0);

  /* for (int x : xor_input1_wires)
     std::cout << x << " ";*/

  // print input data to be used for XOR
  std::cout << "\n"
            << "\n";
  std::cout<< "print actual 64-bits inputs: " << std::endl;
  for (int i = 0; i < n; i++) std::cout << char_array1[i];
  std::cout << std::endl;

  for (int i = 0; i < n; i++) std::cout << char_array2[i];
  std::cout << std::endl;

  // test copy data to vector
  // copied inputs data to vectors
  /*
    for (int m = 0; m < 64; ++m){
      // Copy inputs
      // inserts 7 at xor_input1_wires_indexes-th index
      auto it = xor_input1_wires.insert(xor_input1_wires.begin() + xor_input1_wires_indexes[0], 1);

    }
  */

  /////////////////////////////// Copy 64-bit input A and B to vectors  /////////////////////////////////////////////
  for (int m = 0; m < 64; ++m) {
    // Copy inputs A
    // inserts char_array1      to       xor_input1_wires          at       xor_input1_wires_indexes-th index
    xor_input1_wires.insert(xor_input1_wires.begin() + xor_input1_wires_indexes[m], char_array1[m] - 48);
    // Copy inputs B
    xor_input2_wires.insert(xor_input2_wires.begin() + xor_input2_wires_indexes[m], char_array2[m] - 48);
  }

  std::cout << "\n"
            << "\n";

  /////////////////////////////// Print copied input A /////////////////////////////////////////////
  // print copied input A
  for (int j = 0; j < 64; ++j) {
    // print copied input A
    /*  std::cout << "at index no:  "  << xor_input1_wires_indexes[j] << " value is: " << xor_input1_wires[xor_input1_wires_indexes[j]] << std::endl;*/
  }

  std::cout << "\n"
            << "\n";

  /////////////////////////////// Print copied input B /////////////////////////////////////////////
  for (int j = 0; j < 64; ++j) {
    // print copied input B
    /*  std::cout << "at index no:  "  << xor_input2_wires_indexes[j] << " value is: " << xor_input2_wires[xor_input2_wires_indexes[j]] << std::endl;*/
  }
  std::cout << "\n"
            << "\n";

  // print
  std::cout << "\n"
            << "\n";
  std::cout << "print XOR inputs (inverted): " << std::endl;
  for (int i = 0; i < n; i++) std::cout << xor_input1_wires[xor_input1_wires_indexes[i]];
  std::cout << std::endl;

  for (int i = 0; i < n; i++) std::cout << xor_input2_wires[xor_input2_wires_indexes[i]];
  std::cout << std::endl;

  ///////////////////////////////////////////// XOR operation first stage ////////////////////////////////////////////////
  for (int i = 0; i < 64; ++i) {
    int binary = xor_input1_wires[xor_input1_wires_indexes[i]] ^ xor_input2_wires[xor_input2_wires_indexes[i]];
    /*
        std::cout<<xor_output_wires_indexes[i]<<" ";
    */
    /*std::cout << binary;*/
    xor_output_wires.insert(xor_output_wires.begin() + xor_output_wires_indexes[m], binary);
  }
/*
  // print for debug
  std::cout << "\n"
            << "\n";
  for (int l = 0; l < 64; ++l) {
    // debug XOR operation
    std::cout << xor_input1_wires[l];
  }
  std::cout << "\n";
  for (int l = 0; l < 64; ++l) {
    // debug XOR operation
    std::cout << xor_input2_wires[l];
  }*/

  /////////////////////////////////////////////////////////////debgus xor wires indexes///////////////////////////////////
  /*// debug indexes
  std::cout << "\n"
            << "\n";

  for (int l = 0; l < xor_count; ++l) {
    // debug XOR operation
    std::cout << xor_input1_wires_indexes[l] << " ";
  }
  std::cout << "\n"
            << "\n";
  for (int l = 0; l < xor_count; ++l) {
    // debug XOR operation
    std::cout << xor_input2_wires_indexes[l] << " ";
  }
  std::cout << "\n";
  std::cout << "\n"
            << "\n";
  for (int l = 0; l < xor_count; ++l) {
    // debug XOR operation
    std::cout << xor_output_wires_indexes[l] << " ";
  }
  std::cout << "\n";*/

  /*Close the File*/
  config_file.close();
  return 0;
}
