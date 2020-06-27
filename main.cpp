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
  std::vector<unsigned int> xor_input1_wires(total_wires, 0);
  std::vector< unsigned int> xor_input2_wires(total_wires, 0);
  std::vector< unsigned  int> xor_output_wires(total_wires, 0);

  // INV wires
  std::vector<unsigned int> inv_input_wires(total_wires, 0);
  std::vector< unsigned int> inv_output_wires(total_wires, 0);

  std::vector< unsigned int> and_input1_wires(total_wires, 0);
  std::vector< unsigned int> and_input2_wires(total_wires, 0);
  std::vector<unsigned int> and_output_wires(total_wires, 0);

  // print input data to be used for XOR
  std::cout << "\n"
            << "\n";
  std::cout << "print actual 64-bits inputs: " << std::endl;
  for (int i = 0; i < n; i++) std::cout << char_array1[i];
  std::cout << std::endl;

  for (int i = 0; i < n; i++) std::cout << char_array2[i];
  std::cout << std::endl;

  /////////////////////////////// Copy 64-bit input A and B to vectors  /////////////////////////////////////////////
  for (int k = 0; k < 64; ++k) {
    // Copy inputs A
    // inserts char_array1      to       xor_input1_wires          at       xor_input1_wires_indexes-th index
    xor_input1_wires.insert(xor_input1_wires.begin() + xor_input1_wires_indexes[k], char_array1[k] - 48);
    // Copy inputs B
    xor_input2_wires.insert(xor_input2_wires.begin() + xor_input2_wires_indexes[k], char_array2[k] - 48);
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
  std::cout << "print XOR on those inputs : " << std::endl;
  for (int i = 0; i < 64; ++i) {
    int binary = xor_input1_wires[xor_input1_wires_indexes[i]] ^ xor_input2_wires[xor_input2_wires_indexes[i]];
    /*std::cout << binary;*/
    xor_output_wires.insert(xor_output_wires.begin() + xor_output_wires_indexes[i], binary);
    std::cout << xor_output_wires_indexes[i] << " ";
  }
  std::cout << std::endl;

  ///////////////////////////////////////////// INV operation  ////////////////////////////////////////////////
  for (int k = 0; k < 63; ++k) {
    // Copy inputs A
    inv_input_wires.insert(inv_input_wires.begin() + inv_input_wires_indexes[k], char_array1[k] - 48);
  }

  std::cout << std::endl;
  for (int i = 0; i < 63; ++i) {
    /* std::cout<< "inv_input_wires_indexes: " << inv_input_wires_indexes[i] << std::endl;*/
    int binary = !inv_input_wires[inv_input_wires_indexes[i]];
    inv_output_wires.insert(inv_output_wires.begin() + inv_output_wires_indexes[i], binary);
    std::cout << inv_output_wires_indexes[i] << " ";
  }
  std::cout << std::endl;

  ////////////////////////////////// AND and XOR operation for first XOR output  ///////////////////////////////
  std::cout << std::endl;
  std::cout << "AND/XOR Block: " << 0 << " " << std::endl;

/*
  unsigned int binary1 = inv_output_wires[and_input1_wires_indexes[0]] & xor_input2_wires[xor_input2_wires_indexes[63]];  // 0 mean index no 314
  and_output_wires.insert(and_output_wires.begin() + and_output_wires_indexes[0], binary1);
  std::cout << inv_output_wires_indexes[0] << " " << xor_input2_wires_indexes[63] << " " << and_output_wires_indexes[0] << std::endl;

  unsigned int binary2 = xor_input2_wires[xor_input2_wires_indexes[62]] ^ and_output_wires[and_output_wires_indexes[0]];  // 0 mean index no 314
  xor_output_wires.insert(xor_output_wires.begin() + xor_output_wires_indexes[64], binary2);
  std::cout << xor_input2_wires_indexes[62] << " " << and_output_wires_indexes[0] << " " << xor_output_wires_indexes[64] << std::endl;

  unsigned int final_binary0 = xor_output_wires[xor_output_wires_indexes[62]] ^ and_output_wires[and_output_wires_indexes[0]];  // 0 mean index no 314
  xor_output_wires.insert(xor_output_wires.begin() + xor_output_wires_indexes[65], final_binary0);
  std::cout << xor_output_wires_indexes[62] << " " << and_output_wires_indexes[0] << " " << xor_output_wires_indexes[65] << std::endl;

  std::cout<<"final_binary0  " <<final_binary0<<" ";

  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
*/

  std::cout<<std::endl;
  std::cout<<std::endl;
  std::cout<<std::endl;

  int ind_xor=65;
  int ind_and=0;

  std::cout<< "[xor_input1_wires[ind_xor]]" << xor_input2_wires_indexes[62] << std::endl;

  unsigned  int binary4 = inv_output_wires[and_input1_wires_indexes[ind_and]] & xor_input2_wires_indexes[and_input2_wires_indexes[ind_and]];
  and_output_wires.insert(and_output_wires.begin() + and_output_wires_indexes[ind_and], binary4);
  std::cout << "XOR/AND: : "<< and_input1_wires_indexes[ind_and] << " " <<  and_input2_wires_indexes[ind_and] << " " <<and_output_wires_indexes[ind_and] << " " << std::endl;
  std::cout << "GDB1 : "<< inv_output_wires[and_input1_wires_indexes[ind_and]]   << " " << xor_input2_wires_indexes[and_input2_wires_indexes[ind_and]] << " " << and_output_wires[and_output_wires_indexes[ind_and]] << " " << std::endl;

  unsigned  int binary5 = xor_input1_wires[xor_input2_wires_indexes[62]] ^ and_output_wires[xor_input2_wires_indexes[ind_xor]];
  xor_output_wires.insert(xor_output_wires.begin() + xor_output_wires_indexes[ind_xor], binary5);
  std::cout << "XOR/AND: : "<< xor_input2_wires_indexes[62] << " " <<xor_input2_wires_indexes[ind_xor]<< " " <<  xor_output_wires_indexes[ind_xor] << " " << std::endl;
  std::cout << "GDB2 : "<<xor_input1_wires[xor_input1_wires[ind_xor]]    << " " <<and_output_wires[xor_input2_wires_indexes[ind_xor]] << " " << xor_output_wires[ xor_output_wires_indexes[ind_xor]] << " " << std::endl;

  ind_xor+=1;

  unsigned int binary6 = xor_output_wires[xor_input1_wires_indexes[ind_xor]] ^ and_output_wires[and_output_wires_indexes[ind_xor]];
  xor_output_wires.insert(xor_output_wires.begin() + xor_output_wires_indexes[ind_xor], binary6);
  std::cout << "XOR/AND: : "<<  xor_input1_wires_indexes[ind_xor] << " " << xor_input2_wires_indexes[ind_xor] << " " << xor_output_wires_indexes[ind_xor] << " " << std::endl;
  std::cout << "GDB3 : "<<  xor_output_wires[xor_input1_wires_indexes[ind_xor]] << " " <<  and_output_wires[and_output_wires_indexes[ind_xor]] << " " << xor_output_wires[xor_output_wires_indexes[ind_xor]] << " " << std::endl;

  std::cout<<std::endl;
  std::cout<<std::endl;
  std::cout<<std::endl;
  ////////////////////////////////// AND and XOR operation for first XOR output  ///////////////////////////////
  /*std::cout << "AND/XOR Block: " << 1 << " " << std::endl;

  int binary3 = inv_output_wires[inv_output_wires_indexes[1]] ^ and_output_wires_indexes[0];  // 0 mean index no 314
  xor_output_wires.insert(xor_output_wires.begin() + xor_output_wires_indexes[63 + 3], binary3);
  std::cout << inv_output_wires_indexes[1] << " " << and_output_wires_indexes[0] << " " << xor_output_wires_indexes[63 + 3] << std::endl;

  int binary4 = xor_output_wires[xor_output_wires_indexes[63 + 3]] & xor_output_wires[xor_output_wires_indexes[64]];  // 0 mean index no 314
  and_output_wires.insert(and_output_wires.begin() + and_output_wires_indexes[1], binary4);
  std::cout << xor_output_wires_indexes[63 + 3] << " " << xor_output_wires_indexes[62 + 2] << " " << and_output_wires_indexes[1] << std::endl;

  int binary5 = and_output_wires[and_output_wires_indexes[1]] ^ and_output_wires[and_output_wires_indexes[0]];  // 0 mean index no 314
  xor_output_wires.insert(xor_output_wires.begin() + xor_output_wires_indexes[67], binary5);
  std::cout << and_output_wires_indexes[1] << " " << and_output_wires_indexes[0] << " " << xor_output_wires_indexes[67] << std::endl;

  int binary6 = xor_input2_wires[xor_input2_wires_indexes[61]] ^ xor_output_wires[xor_output_wires_indexes[67]];  // 0 mean index no 314
  xor_output_wires.insert(xor_output_wires.begin() + xor_output_wires_indexes[68], binary6);
  std::cout << xor_input2_wires_indexes[61] << " " << xor_output_wires_indexes[67] << " " << xor_output_wires_indexes[68] << std::endl;

  int final_binary1 = xor_output_wires[xor_output_wires_indexes[61]] ^ xor_output_wires[xor_output_wires_indexes[67]];  // 0 mean index no 314
  xor_output_wires.insert(xor_output_wires.begin() + xor_output_wires_indexes[69], final_binary1);
  std::cout << xor_output_wires_indexes[61] << " " << xor_output_wires_indexes[67] << " " << xor_output_wires_indexes[69] << std::endl;

  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;*/

  std::cout<<std::endl;
  std::cout<<std::endl;
  std::cout<<std::endl;


  ////////////////////////////////// AND and XOR operation for rest of  XOR output  ///////////////////////////////
  int in_xor=66;
  int in_and=1;
  int inv_index=1;
  std::cout<< "XOR/BLOCKS: " << std::endl;
  for (int k = 0; k < 62; ++k) {
    unsigned int binary3 = inv_output_wires[xor_input1_wires_indexes[in_xor]] ^ xor_input2_wires[xor_input2_wires_indexes[in_xor]];
    xor_output_wires.insert(xor_output_wires.begin() + xor_output_wires_indexes[in_xor], binary3);
    std::cout << "XOR/AND:  : "<< xor_input1_wires_indexes[in_xor] << " " << xor_input2_wires_indexes[in_xor] << " " << xor_output_wires_indexes[in_xor] << " " << std::endl;
    std::cout << "GDB1 : "<< inv_output_wires[xor_input1_wires_indexes[in_xor]] << " " << xor_input2_wires[xor_input2_wires_indexes[in_xor]] << " " << xor_output_wires[xor_output_wires_indexes[in_xor]] << " " << std::endl;
    inv_index+=1;

    unsigned  int binary4 = xor_output_wires[and_input1_wires_indexes[in_and]] & xor_output_wires[and_input2_wires_indexes[in_and]];
    and_output_wires.insert(and_output_wires.begin() + and_output_wires_indexes[in_and], binary4);
    std::cout << "XOR/AND: : "<< and_input1_wires_indexes[in_and] << " " << and_input2_wires_indexes[in_and] << " " <<and_output_wires_indexes[in_and] << " " << std::endl;
    std::cout << "GDB2 : "<< xor_output_wires[and_input1_wires_indexes[in_and]]  << " " << xor_output_wires[and_input2_wires_indexes[in_and]] << " " << and_output_wires[and_output_wires_indexes[in_and]] << " " << std::endl;

    in_xor+=1;
    in_and+=1;

    unsigned  int binary5 = and_output_wires[xor_input1_wires_indexes[in_xor]] ^ xor_output_wires[xor_input2_wires_indexes[in_xor]];
    xor_output_wires.insert(xor_output_wires.begin() + xor_output_wires_indexes[in_xor], binary5);
    std::cout << "XOR/AND: : "<< xor_input1_wires_indexes[in_xor] << " " <<xor_input2_wires_indexes[in_xor] << " " <<  xor_output_wires_indexes[in_xor] << " " << std::endl;
    std::cout << "GDB3 : "<< and_output_wires[xor_input1_wires_indexes[in_xor]] << " " << xor_output_wires[xor_input2_wires_indexes[in_xor]] << " " << xor_output_wires[ xor_output_wires_indexes[in_xor]] << " " << std::endl;

    in_xor+=1;

    unsigned int binary6 = xor_input1_wires[xor_input1_wires_indexes[in_xor]] ^ xor_output_wires[xor_input2_wires_indexes[in_xor]];
    xor_output_wires.insert(xor_output_wires.begin() + xor_output_wires_indexes[in_xor], binary6);
    std::cout << "XOR/AND: : "<<  xor_input1_wires_indexes[in_xor] << " " << xor_input2_wires_indexes[in_xor] << " " << xor_output_wires_indexes[in_xor] << " " << std::endl;
    std::cout << "GDB4 : "<<  xor_input1_wires[xor_input1_wires_indexes[in_xor]] << " " << xor_output_wires[xor_input2_wires_indexes[in_xor]] << " " << xor_output_wires[xor_output_wires_indexes[in_xor]] << " " << std::endl;

    in_xor+=1;

    unsigned int binary7 = xor_input1_wires[xor_input1_wires_indexes[in_xor]] ^ xor_output_wires[xor_input2_wires_indexes[in_xor]];
    xor_output_wires.insert(xor_output_wires.begin() + xor_output_wires_indexes[in_xor], binary7);
    std::cout << "XOR/AND: : "<< xor_input1_wires_indexes[in_xor]  << " " << xor_input2_wires_indexes[in_xor] << " " << xor_output_wires_indexes[in_xor] << " " << std::endl;
    std::cout << "GDB5 : "<< xor_input1_wires[xor_input1_wires_indexes[in_xor]]  << " " << xor_output_wires[xor_input2_wires_indexes[in_xor]] << " " << xor_output_wires[xor_output_wires_indexes[in_xor]] << " " << std::endl;

    std::cout<<std::endl;
    std::cout<<binary4 << " " << binary5 << " " << binary6 << " " << binary7 << " ";
    std::cout<<std::endl;

    in_xor+=1;
  }


  std::vector<int> ind_final_out;
  for (int l = 503; l < 567 ; ++l) {
    ind_final_out.push_back(l);
  }

  for (std::vector<int>::iterator it = ind_final_out.begin(); it != ind_final_out.end(); ++it) {
   std::cout<<*it<< " ";

  }
  std::cout<<std::endl;
  std::cout<<std::endl;
  std::cout<<std::endl;
  std::cout<<std::endl;
  /*for (std::vector<int>::iterator it = ind_final_out.begin(); it != ind_final_out.end(); ++it) {
    std::cout<< xor_output_wires[*it];
  }*/
  std::cout<<std::endl;
  std::cout<<std::endl;
  std::cout<<std::endl;
  std::cout<<std::endl;
  /*Close the File*/
  config_file.close();
  return 0;
}
