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
#include "../digitaldesign/include/FloatingSimpleTests.h"
#include "../digitaldesign/include/ReadData.h"
#include "../digitaldesign/include/conversations.h"

std::vector<int> test_arithmetic(const std::string &file_path, const std::string &input_a, const std::string &input_b,
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
    char *char_array1 = circuit_obj->read_inputs_A(input_a);
    char *char_array2 = circuit_obj->read_inputs_B(input_b);

    std::vector<int> return_wires = circuit_obj->arithmetic_functions(data_list, char_array1, char_array2, input_a.size(), input_b.size());
    circuit_obj->display_output(return_wires, output_size);

    return return_wires;

  }

  else {
    // Input A 64-bits
    char *char_array = circuit_obj->read_inputs_A(input_a);

    std::vector<int> return_wires = circuit_obj->arithmetic_functions(data_list, char_array, nullptr, input_a.size(), input_b.size());
    circuit_obj->display_output(return_wires, output_size);

    return return_wires;
  }
}

int main(int argc, char **argv) {
  try {
    reverse(input_a1.begin(), input_a1.end());
    reverse(input_b1.begin(), input_b1.end());

    FloatingTests::test_fp_add();
    std::cout << "\n==================== Testing FP-add Circuit ====================\n";
    test_arithmetic("../data/IEEE-floating-point-operations/FP-add.txt", input_a1, input_b1, 64);

    FloatingTests::test_fp_mul();
    std::cout << "\n==================== Testing FP-mul Circuit ====================\n " << std::endl;
    test_arithmetic("../data/IEEE-floating-point-operations/FP-mul.txt", input_a1, input_b1, 64);

    FloatingTests::test_fp_div();
    std::cout << "\n==================== Testing a FP-div Circuit ====================\n" << std::endl;
    test_arithmetic("../data/IEEE-floating-point-operations/FP-div.txt", input_a1, input_b1, 64);

    FloatingTests::test_fp_sqrt();
    std::cout << "\n==================== Testing FP-sqrt Circuit ====================\n" << std::endl;
    test_arithmetic("../data/IEEE-floating-point-operations/FP-sqrt.txt", input_a1, empty, 64);

    FloatingTests::test_fp_f2i();
    std::cout << "================== Testing FP-f2i Circuit ========================" << std::endl;
    test_arithmetic("../data/IEEE-floating-point-operations/FP-f2i.txt", input_a1, empty, 64);

    FloatingTests::test_fp_i2f();
    std::cout << "================== Testing FP-i2f Circuit ========================" << std::endl;
    test_arithmetic("../data/IEEE-floating-point-operations/FP-i2f.txt", input_a1, empty, 64);

    //    std::cout << "================== Testing FP-eq Circuit ======================== " << std::endl;
    //    test_arithmetic("../data/IEEE-floating-point-operations/FP-eq.txt", 192, 128, 128);
    //

  }

  catch (const std::runtime_error &ex) {
    std::cout << ex.what() << std::endl;
  }
  return 0;
}
