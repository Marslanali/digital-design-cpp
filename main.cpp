//
// Created by arslan on 7/7/20.
//

#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include "../digitaldesign/include/Circuits.h"
#include "../digitaldesign/include/Constants.h"
#include "../digitaldesign/include/ReadData.h"

// bits to double function
void bits_to_double(const std::vector<int> &bits, double &x) {
  uint8_t *ptr = (uint8_t *)&x;

  for (int index = 0; index < 8; index++) {
    uint8_t byte = 0;
    for (int i = 0; i < 8; i++) {
      byte <<= 1;
      byte += bits[56 + i - index * 8];
    }
    ptr[index] = byte;
  }
}

// double to bits conversion
void double_to_bits(double x, std::string &bits) {
  uint8_t *ptr = (uint8_t *)&x;

  for (int index = 0; index < 8; index++) {
    uint8_t byte = ptr[index];
    for (int i = 0; i < 8; i++) {
      bits[63 - i - index * 8] = char(byte & 1);
      byte >>= 1;
    }
  }
}

// prints bits
void print_bits(const std::string &bits) {
  for (int i = 0; i < 64; i++) {
    std::cout << int(bits[i]);
    if (i == 0 || i == 11) {
      std::cout << " ";
    }
  }
  std::cout << std::endl;
}

void test_conversation_all() {
  //  // Test conversion functions
  //  /*std::string bits = "0100000001010101010010000000000000000000000000000000000000000000";*/
  //  double double_value = 3.125;
  //  std::cout << "\n double value: " << double_value << "\n";
  //
  //  // Double to bits conversion
  //  std::string bits(64, 'x');
  //  double_to_bits(double_value, bits);
  //  std::cout << "\n double to bits: ";
  //  print_bits(bits);
  //
  //  // Bits to double conversion
  //  double temp;
  //  bits_to_double(bits, temp);
  //  std::cout << "\n bits to double: " << temp << "\n";
  //
  //  // Bits to ulong conversion
  //  unsigned long ulong_value;
  //  bits_to_ulong(bits, ulong_value);
  //  std::cout << "\n bits to ulong: " << ulong_value << std::endl;
  //
  //  // ulong to double conversion
  //  double value;
  //  ulong_to_double(ulong_value, value);
  //  std::cout << "\n ulong to double: " << value << std::endl;
  //  std::cout << std::endl;
}

std::vector<int> test_arithmetic(const std::string &file_path, const std::string input_a, const std::string input_b,
                                 const int output_size) {
  ////////////////////////////////////// Arithmetic Functions ///////////////////////////////////////////////////
  // Create and instance of ReadData class and called constructor
  ReadData text_file_read(file_path);

  // Get the data from text File
  std::vector<std::vector<std::string>> data_list = text_file_read.get_data();

  // Create an instance of Circuit class
  auto *circuit_obj = new Circuits;

  // circuit_obj calling to its member function i.e display_circuit
  circuit_obj->display_circuit(data_list);

  if (!input_b.empty()) {
    // Input A and B 64-bits
    char *char_array1 = circuit_obj->read_inputs_A(bit);
    char *char_array2 = circuit_obj->read_inputs_B(bit);

    std::vector<int> return_wires = circuit_obj->arithmetic_functions(data_list, char_array1, char_array2, input_a.size(), input_b.size());
    circuit_obj->display_output(return_wires, output_size);

    return return_wires;

  }

  else {
    // Input A 64-bits
    char *char_array = circuit_obj->read_inputs_A(input_a2);

    std::vector<int> return_wires = circuit_obj->arithmetic_functions(data_list, char_array, nullptr, input_a.size(), input_b.size());

    return return_wires;

    // circuit_obj->display_output(return_wires, output_size);
  }
}

int main(int argc, char **argv) {
  try {
    std::cout << "\n================== Testing FP-add With Addition Operator ==========================\n";

    // double value floating points
    double double_value1 = 1.5625;
    double double_value2 = 1.5625;  
    double add = double_value1 + double_value2;
    std::cout << "\nFP-add: " << double_value1 << " + " << double_value2 << " = " << add << std::endl;

    // Double to bits conversion
    std::string input_a_bits(64, 'x');
    std::string input_b_bits(64, 'x');
    std::string output_add_bits(64, 'x');

    double_to_bits(double_value1, input_a_bits);
    double_to_bits(double_value2, input_b_bits);
    double_to_bits(add, output_add_bits);

    std::cout << "\nFP-add Input a bits:\n";
    print_bits(input_a_bits);

    std::cout << "\nFP-add Input b bits:\n";
    print_bits(input_b_bits);

    std::cout << "\nFP-add output bits:\n";
    print_bits(output_add_bits);

    std::cout << "\n====================== Testing FP-add Circuit ====================================\n";
    std::vector<int> ans = test_arithmetic("../data/IEEE-floating-point-operations/FP-add.txt", input_a_bits, input_b_bits, 64);

    //    std::cout << "================== Testing FP-mul Circuit ========================== " << std::endl;
    //    test_arithmetic("../data/IEEE-floating-point-operations/FP-mul.txt", 512, 256, 256);
    //
    //    std::cout << "================== Testing a FP-div Circuit ======================" << std::endl;
    //    test_arithmetic("../data/IEEE-floating-point-operations/FP-div.txt", 128, 128, 128);
    //
    //    std::cout << "================== Testing FP-eq Circuit ======================== " << std::endl;
    //    test_arithmetic("../data/IEEE-floating-point-operations/FP-eq.txt", 192, 128, 128);
    //
    //    std::cout << "================== Testing FP-f2i Circuit ========================" << std::endl;
    //    test_arithmetic("../data/IEEE-floating-point-operations/FP-f2i.txt", 256, 128, 128);
    //
    //    std::cout << "================== Testing FP-f2ii Circuit ========================" << std::endl;
    //    test_arithmetic("../data/IEEE-floating-point-operations/FP-f2ii.txt", 1600, 0, 1600);
    //
    //    std::cout << "================== Testing FP-sqrt Circuit ========================" << std::endl;
    //    test_arithmetic("../data/IEEE-floating-point-operations/FP-sqrt.txt", 1600, 0, 1600);

  }

  catch (const std::runtime_error &ex) {
    std::cout << ex.what() << std::endl;
  }
  return 0;
}
