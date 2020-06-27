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

  /* std::cout << "\nfirst line: " << std::endl;
   for (int j = 0; j < 2; ++j) {
     std::cout << data_list[0][j] << " ";
   }
   std::cout << "\n";*/

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
  /*std::cout << "input A size: " << n << std::endl;*/

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
  /*std::cout << "input B size: " << m << std::endl;*/

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

  /* // print XOR
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
   }*/

  /////////////////////////////// 64-bit Subtractor FIRST STAGE Implementation start from here ////////////////////////////

  // XOR gate vector inputer wires
  // Create a vector of size  with
  // all values as 0
  std::vector<unsigned int> xor_input1_wires(total_wires, 0);
  std::vector<unsigned int> xor_input2_wires(total_wires, 0);
  std::vector<unsigned int> xor_output_wires(total_wires, 0);

  // INV wires
  std::vector<unsigned int> inv_input_wires(total_wires, 0);
  std::vector<unsigned int> inv_output_wires(total_wires, 0);

  std::vector<unsigned int> and_input1_wires(total_wires, 0);
  std::vector<unsigned int> and_input2_wires(total_wires, 0);
  std::vector<unsigned int> and_output_wires(total_wires, 0);

  /*  // print input data to be used for XOR
    std::cout << "\n"
              << "\n";
    std::cout << "print actual 64-bits inputs: " << std::endl;
    for (int i = 0; i < n; i++) std::cout << char_array1[i];
    std::cout << std::endl;

    for (int i = 0; i < n; i++) std::cout << char_array2[i];
    std::cout << std::endl;*/

  /////////////////////////////// Copy 64-bit input A and B to vectors  /////////////////////////////////////////////
  for (int k = 0; k < 64; ++k) {
    // Copy inputs A
    // inserts char_array1      to       xor_input1_wires          at       xor_input1_wires_indexes-th index
    xor_input1_wires.insert(xor_input1_wires.begin() + xor_input1_wires_indexes[k], char_array1[k] - 48);
    // Copy inputs B
    xor_input2_wires.insert(xor_input2_wires.begin() + xor_input2_wires_indexes[k], char_array2[k] - 48);
  }

  // print
  std::cout << "\n"
            << "\n";
  // print
  std::cout << "\n"
            << "\n";
  std::cout << "sdfdfsdfsdfdf" << std::endl;
  for (int a = 0; a < 64; ++a) {
    std::cout << xor_input1_wires_indexes[a] << " ";
    std::cout << std::endl;
  }

  // print
  std::cout << "\n"
            << "\n";
  // print
  std::cout << "\n"
            << "\n";
  // print
  std::cout << "\n"
            << "\n";
  std::cout << "print XOR 64 bit inputs (inverted): " << std::endl;
  for (int i = 0; i < n; i++) std::cout << xor_input1_wires[xor_input1_wires_indexes[i]];
  std::cout << std::endl;

  for (int i = 0; i < n; i++) std::cout << xor_input2_wires[xor_input2_wires_indexes[i]];
  std::cout << std::endl;
  std::cout << std::endl;

  ///////////////////////////////////////////// XOR operation first stage ////////////////////////////////////////////////
  std::cout << "print XOR on those inputs : " << std::endl;
  for (int i = 0; i < 64; ++i) {
    int binary = xor_input1_wires[xor_input1_wires_indexes[i]] ^ xor_input2_wires[xor_input2_wires_indexes[i]];
    std::cout << binary;
    xor_output_wires.insert(xor_output_wires.begin() + xor_output_wires_indexes[i], binary);
  }
  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << "Print XOR wires Indexes: " << std::endl;
  for (int i = 0; i < 64; ++i) {
    std::cout << xor_output_wires_indexes[i] << " ";
  }
  std::cout << std::endl;
  std::cout << std::endl;

  /*  /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "print XOR 64 bit inputs (inverted): " << std::endl;
    for (int i = 0; i < n; i++) std::cout << ;
    std::cout << std::endl;*/

  ///////////////////////////////////////////// INV operation  ////////////////////////////////////////////////
  /*std::cout << "INV wires indexes: " << std::endl;
  for (int k = 0; k < 63; ++k) {
    // Copy inputs A
    inv_input_wires.insert(inv_input_wires.begin() + inv_input_wires_indexes[k], xor_input1_wires[xor_input1_wires_indexes[k]]);
    std::cout << inv_input_wires_indexes[k] << " ";
  }
  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << "INV Input on those wire indexes: " << std::endl;
  for (int k = 0; k < 63; ++k) {
    std::cout << inv_input_wires[inv_input_wires_indexes[k]];
  }
  std::cout << std::endl;
  std::cout << std::endl;
*/
  std::cout << std::endl;
  std::cout << "~ INV operation: " << std::endl;
  int ind_inv = 0;
  for (int i = 63; i >= 1; --i) {
    /* std::cout<< "inv_input_wires_indexes: " << inv_input_wires_indexes[i] << std::endl;*/
    int binary = !xor_input1_wires[xor_input1_wires_indexes[i]];
    inv_output_wires.insert(inv_output_wires.begin() + inv_output_wires_indexes[ind_inv], binary);
    std::cout << "Wires: : " << xor_input1_wires_indexes[i] << " " << inv_output_wires_indexes[ind_inv] << " " << std::endl;
    std::cout << "Binary : " << xor_input1_wires[xor_input1_wires_indexes[i]] << " " << !xor_input1_wires[xor_input1_wires_indexes[i]] << " " << std::endl;

    ind_inv += 1;
  }
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  ////////////////////////////////// AND and XOR operation for first XOR output  ///////////////////////////////
  std::cout << std::endl;
  std::cout << "AND/XOR Block: " << 0 << " " << std::endl;

  unsigned int binary1 = inv_output_wires[inv_output_wires_indexes[0]] & xor_input2_wires[xor_input2_wires_indexes[63]];  // 0 mean index no 314
  and_output_wires.insert(and_output_wires.begin() + and_output_wires_indexes[0], binary1);
  std::cout << "Wires: : " << and_input1_wires_indexes[0] << " " << and_input2_wires_indexes[0] << " " << and_output_wires_indexes[0] << " " << std::endl;
  std::cout << "Binary : " << inv_output_wires[and_input1_wires_indexes[0]] << " " << xor_input2_wires[and_input2_wires_indexes[0]] << " "
            << and_output_wires[and_output_wires_indexes[0]] << " " << std::endl;

  unsigned int binary2 = xor_input2_wires[xor_input2_wires_indexes[62]] ^ and_output_wires[and_output_wires_indexes[0]];  // 0 mean index no 314
  xor_output_wires.insert(xor_output_wires.begin() + xor_output_wires_indexes[64], binary2);
  std::cout << "Wires: : " << xor_input1_wires_indexes[64] << " " << xor_input2_wires_indexes[64] << " " << xor_output_wires_indexes[64] << " " << std::endl;
  std::cout << "Binary : " << xor_input2_wires[xor_input1_wires_indexes[64]] << " " << and_output_wires[xor_input2_wires_indexes[64]] << " "
            << xor_output_wires[xor_output_wires_indexes[64]] << " " << std::endl;

  unsigned int final_binary0 = xor_output_wires[xor_output_wires_indexes[62]] ^ and_output_wires[and_output_wires_indexes[0]];  // 0 mean index no 314
  xor_output_wires.insert(xor_output_wires.begin() + xor_output_wires_indexes[65], final_binary0);
  std::cout << "Wires: " << xor_input1_wires_indexes[65] << " " << xor_input2_wires_indexes[65] << " " << xor_output_wires_indexes[65] << " " << std::endl;
  std::cout << "Binary: " << xor_output_wires[xor_input1_wires_indexes[65]] << " " << and_output_wires[xor_input2_wires_indexes[65]] << " "
            << xor_output_wires[xor_output_wires_indexes[65]] << " " << std::endl;

  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  int ind_xor = 65;
  int ind_and = 0;

  std::cout << "AND/XOR Block: " << 1 << " " << std::endl;

  unsigned int binary4 = inv_output_wires[inv_output_wires_indexes[1]] & and_output_wires[and_output_wires_indexes[0]];
  xor_output_wires.insert(xor_output_wires.begin() + xor_output_wires_indexes[66], binary4);
  std::cout << "Wires: : " << xor_input1_wires_indexes[66] << " " << xor_input2_wires_indexes[66] << " " << xor_output_wires_indexes[66] << " " << std::endl;
  std::cout << "XOR GATE : " << inv_output_wires[xor_input1_wires_indexes[66]] << " " << and_output_wires[xor_input2_wires_indexes[66]] << " "
            << xor_output_wires[xor_output_wires_indexes[66]] << " " << std::endl;

  unsigned int binary5 = xor_output_wires[xor_output_wires_indexes[66]] ^ xor_output_wires[xor_output_wires_indexes[64]];
  and_output_wires.insert(and_output_wires.begin() + and_output_wires_indexes[1], binary5);
  std::cout << "Wires: : " << and_input1_wires_indexes[1] << " " << and_input2_wires_indexes[1] << " " << and_output_wires_indexes[1] << " " << std::endl;
  std::cout << "AND GATE : " << xor_output_wires[and_input1_wires_indexes[1]] << " " << xor_output_wires[and_input2_wires_indexes[1]] << " "
            << and_output_wires[and_output_wires_indexes[1]] << " " << std::endl;

  unsigned int binary6 = and_output_wires[and_output_wires_indexes[1]] ^ and_output_wires[and_output_wires_indexes[0]];
  xor_output_wires.insert(xor_output_wires.begin() + xor_output_wires_indexes[67], binary6);
  std::cout << "Wires: : " << xor_input1_wires_indexes[67] << " " << xor_input2_wires_indexes[67] << " " << xor_output_wires_indexes[67] << " " << std::endl;
  std::cout << "XOR GATE : " << and_output_wires[xor_input1_wires_indexes[67]] << " " << and_output_wires[xor_input2_wires_indexes[67]] << " "
            << xor_output_wires[xor_output_wires_indexes[ind_xor]] << " " << std::endl;

  unsigned int binary7 = xor_input2_wires[xor_input2_wires_indexes[61]] ^ xor_output_wires[xor_output_wires_indexes[67]];
  xor_output_wires.insert(xor_output_wires.begin() + xor_output_wires_indexes[68], binary7);
  std::cout << "Wires: : " << xor_input1_wires_indexes[68] << " " << xor_input2_wires_indexes[68] << " " << xor_output_wires_indexes[68] << " " << std::endl;
  std::cout << "XOR GATE : " << xor_input2_wires[xor_input1_wires_indexes[68]] << " " << xor_output_wires[xor_input2_wires_indexes[68]] << " "
            << xor_output_wires[xor_output_wires_indexes[68]] << " " << std::endl;

  unsigned int binary8 = xor_output_wires[xor_output_wires_indexes[61]] ^ xor_output_wires[xor_output_wires_indexes[67]];
  xor_output_wires.insert(xor_output_wires.begin() + xor_output_wires_indexes[69], binary8);
  std::cout << "Wires: : " << xor_input1_wires_indexes[69] << " " << xor_input2_wires_indexes[69] << " " << xor_output_wires_indexes[69] << " " << std::endl;
  std::cout << "XOR GATE : " << xor_output_wires[xor_input1_wires_indexes[69]] << " " << xor_output_wires[xor_input2_wires_indexes[69]] << " "
            << xor_output_wires[xor_output_wires_indexes[69]] << " " << std::endl;

  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  int index_of_xor1 = 67;
  int index_of_xor2 = 70;
  int index_of_xor3 = 68;
  int index_of_xor4 = 68;
  int index_of_xor5 = 71;
  unsigned int index_of_xor6 = 60;
  int index_of_xor7 = 71;
  int index_of_xor8 = 72;
  unsigned int index_of_xor9 = 60;
  int index_of_xor10 = 71;
  int index_of_xor11 = 73;
  int index_of_and1 = 2;
  int index_of_inv = 2;

  int in_xor = 70;
  int in_and = 2;
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  std::cout << "XOR/BLOCKS: 2 " << std::endl;
  for (int k = 0; k < 60; ++k) {
    unsigned int binary3 = inv_output_wires[inv_output_wires_indexes[index_of_inv]] ^ xor_output_wires[xor_output_wires_indexes[index_of_xor1]];
    xor_output_wires.insert(xor_output_wires.begin() + xor_output_wires_indexes[index_of_xor2], binary3);

    index_of_inv += 1;
    index_of_xor1 += 3;

    unsigned int binary4 = xor_output_wires[xor_output_wires_indexes[index_of_xor2]] & xor_output_wires[xor_output_wires_indexes[index_of_xor4]];
    and_output_wires.insert(and_output_wires.begin() + and_output_wires_indexes[index_of_and1], binary4);

    index_of_xor2 += 3;
    index_of_xor3 += 3;
    index_of_xor4 += 2;

    unsigned int binary5 = and_output_wires[and_output_wires_indexes[index_of_and1]] ^ xor_output_wires[xor_output_wires_indexes[index_of_xor1]];
    xor_output_wires.insert(xor_output_wires.begin() + xor_output_wires_indexes[index_of_xor5], binary5);

    index_of_and1 += 1;
    index_of_xor5 += 1;

    unsigned int binary6 = xor_input2_wires[xor_input2_wires_indexes[index_of_xor6]] ^ xor_output_wires[xor_output_wires_indexes[index_of_xor7]];
    xor_output_wires.insert(xor_output_wires.begin() + xor_output_wires_indexes[index_of_xor8], binary6);

    index_of_xor6 -= 1;
    index_of_xor7 += 3;
    index_of_xor8 += 3;

    unsigned int binary7 = xor_output_wires[xor_output_wires_indexes[index_of_xor9]] ^ xor_output_wires[xor_output_wires_indexes[index_of_xor10]];
    xor_output_wires.insert(xor_output_wires.begin() + xor_output_wires_indexes[index_of_xor11], binary7);
    index_of_xor9 -= 1;

    index_of_xor10 += 3;
    index_of_xor11 += 3;

    std::cout << "Wires:   " << xor_input1_wires_indexes[in_xor] << " " << xor_input2_wires_indexes[in_xor] << " " << xor_output_wires_indexes[in_xor] << " " << std::endl;
    std::cout << "Wires:   " << and_input1_wires_indexes[in_and] << " " << and_input2_wires_indexes[in_and] << " " << and_output_wires_indexes[in_and] << " " << std::endl;

    in_xor += 1;
    in_and += 1;

    std::cout << "Wires:  " << xor_input1_wires_indexes[in_xor] << " " << xor_input2_wires_indexes[in_xor] << " " << xor_output_wires_indexes[in_xor] << " " << std::endl;

    in_xor += 1;

    std::cout << "Wires:  " << xor_input1_wires_indexes[in_xor] << " " << xor_input2_wires_indexes[in_xor] << " " << xor_output_wires_indexes[in_xor] << " " << std::endl;

    in_xor += 1;

    std::cout << "Wires:  " << xor_input1_wires_indexes[in_xor] << " " << xor_input2_wires_indexes[in_xor] << " " << xor_output_wires_indexes[in_xor] << " " << std::endl;

    in_xor += 1;

    std::cout << std::endl;
    std::cout << std::endl;
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  unsigned int binary33 = inv_output_wires[inv_output_wires_indexes[index_of_inv]] ^ xor_output_wires[xor_output_wires_indexes[index_of_xor1]];
  xor_output_wires.insert(xor_output_wires.begin() + xor_output_wires_indexes[index_of_xor2], binary33);

  index_of_inv += 1;
  index_of_xor1 += 3;

  unsigned int binary44 = xor_output_wires[xor_output_wires_indexes[index_of_xor2]] & xor_output_wires[xor_output_wires_indexes[index_of_xor4]];
  and_output_wires.insert(and_output_wires.begin() + and_output_wires_indexes[index_of_and1], binary44);

  index_of_xor2 += 3;
  index_of_xor3 += 3;
  index_of_xor4 += 2;

  unsigned int binary55 = and_output_wires[and_output_wires_indexes[index_of_and1]] ^ xor_output_wires[xor_output_wires_indexes[index_of_xor1]];
  xor_output_wires.insert(xor_output_wires.begin() + xor_output_wires_indexes[index_of_xor5], binary55);

  index_of_and1 += 1;
  index_of_xor5 += 1;

  unsigned int binary66 = xor_input2_wires[xor_input2_wires_indexes[index_of_xor6]] ^ xor_output_wires[xor_output_wires_indexes[index_of_xor7]];
  xor_output_wires.insert(xor_output_wires.begin() + xor_output_wires_indexes[index_of_xor8], binary66);

  index_of_xor6 -= 1;
  index_of_xor7 += 3;
  index_of_xor8 += 3;

  ////////////////////////////////// AND and XOR operation for rest of  XOR output  ///////////////////////////////





  /*std::cout << "XOR/BLOCKS: " << std::endl;
  for (int k = 0; k < 60; ++k) {
    std::cout << "Wires:   " << xor_input1_wires_indexes[in_xor] << " " << xor_input2_wires_indexes[in_xor] << " " << xor_output_wires_indexes[in_xor] << " " << std::endl;
    std::cout << "Wires:   " << and_input1_wires_indexes[in_and] << " " << and_input2_wires_indexes[in_and] << " " << and_output_wires_indexes[in_and] << " " << std::endl;

    in_xor += 1;
    in_and += 1;

    std::cout << "Wires:  " << xor_input1_wires_indexes[in_xor] << " " << xor_input2_wires_indexes[in_xor] << " " << xor_output_wires_indexes[in_xor] << " " << std::endl;

    in_xor += 1;

    std::cout << "Wires:  " << xor_input1_wires_indexes[in_xor] << " " << xor_input2_wires_indexes[in_xor] << " " << xor_output_wires_indexes[in_xor] << " " << std::endl;

    in_xor += 1;

    std::cout << "Wires:  " << xor_input1_wires_indexes[in_xor] << " " << xor_input2_wires_indexes[in_xor] << " " << xor_output_wires_indexes[in_xor] << " " << std::endl;

    in_xor += 1;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
  }
*/
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  /*std::cout << "XOR/BLOCKS: Final " << std::endl;

  unsigned int binary33 = inv_output_wires[xor_input1_wires_indexes[in_xor]] ^ xor_output_wires[xor_input2_wires_indexes[in_xor]];
  xor_output_wires.insert(xor_output_wires.begin() + xor_output_wires_indexes[in_xor], binary33);
  std::cout << "Wires:  : " << xor_input1_wires_indexes[in_xor] << " " << xor_input2_wires_indexes[in_xor] << " " << xor_output_wires_indexes[in_xor] << " " << std::endl;
  std::cout << "XOR GATE : " << inv_output_wires[xor_input1_wires_indexes[in_xor]] << " " << xor_output_wires[xor_input2_wires_indexes[in_xor]] << " "
            << xor_output_wires[xor_output_wires_indexes[in_xor]] << " " << std::endl;

  unsigned int binary44 = xor_output_wires[and_input1_wires_indexes[in_and]] & xor_output_wires[and_input2_wires_indexes[in_and]];
  and_output_wires.insert(and_output_wires.begin() + and_output_wires_indexes[in_and], binary44);
  std::cout << "Wires: : " << and_input1_wires_indexes[in_and] << " " << and_input2_wires_indexes[in_and] << " " << and_output_wires_indexes[in_and] << " " << std::endl;
  std::cout << "AND GATE : " << xor_output_wires[and_input1_wires_indexes[in_and]] << " " << xor_output_wires[and_input2_wires_indexes[in_and]] << " "
            << and_output_wires[and_output_wires_indexes[in_and]] << " " << std::endl;

  in_xor += 1;
  in_and += 1;

  unsigned int binary55 = and_output_wires[xor_input1_wires_indexes[in_xor]] ^ xor_output_wires[xor_input2_wires_indexes[in_xor]];
  xor_output_wires.insert(xor_output_wires.begin() + xor_output_wires_indexes[in_xor], binary55);
  std::cout << "Wires: : " << xor_input1_wires_indexes[in_xor] << " " << xor_input2_wires_indexes[in_xor] << " " << xor_output_wires_indexes[in_xor] << " " << std::endl;
  std::cout << "XOR GATE : " << and_output_wires[xor_input1_wires_indexes[in_xor]] << " " << xor_output_wires[xor_input2_wires_indexes[in_xor]] << " "
            << xor_output_wires[xor_output_wires_indexes[in_xor]] << " " << std::endl;

  in_xor += 1;

  unsigned int binary66 = xor_input2_wires[xor_input1_wires_indexes[in_xor]] ^ xor_output_wires[xor_input2_wires_indexes[in_xor]];
  xor_output_wires.insert(xor_output_wires.begin() + xor_output_wires_indexes[in_xor], binary66);
  std::cout << "Wires: : " << xor_input1_wires_indexes[in_xor] << " " << xor_input2_wires_indexes[in_xor] << " " << xor_output_wires_indexes[in_xor] << " " << std::endl;
  std::cout << "XOR GATE : " << xor_input2_wires[xor_input1_wires_indexes[in_xor]] << " " << xor_output_wires[xor_input2_wires_indexes[in_xor]] << " "
            << xor_output_wires[xor_output_wires_indexes[in_xor]] << " " << std::endl;
*/

  int index_final[64] = {65,  70,  74,  78,  82,  86,  90,  95,  99,  103, 107, 111, 115, 119, 123, 127, 131, 135, 139, 143, 147, 151,
                         154, 159, 162, 166, 171, 175, 178, 183, 186, 191, 195, 198, 202, 206, 210, 214, 219, 222, 226, 230, 235, 238,
                         243, 246, 250, 255, 259, 263, 267, 271, 275, 279, 282, 286, 291, 295, 299, 102, 105, 108, 111, 115};

  std::vector<int> ind_final_out;
  for (int l = 0; l < 64; ++l) {
    ind_final_out.push_back(index_final[l]);
  }

  for (std::vector<int>::iterator it = ind_final_out.begin(); it != ind_final_out.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  for (std::vector<int>::iterator it = ind_final_out.begin(); it != ind_final_out.end(); ++it) {
    std::cout << xor_output_wires[xor_output_wires_indexes[*it]];
  }
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  /*Close the File*/
  config_file.close();
  return 0;
}
