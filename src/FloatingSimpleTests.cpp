//
// Created by arslan on 7/8/20.
//

#include "../include/FloatingSimpleTests.h"
#include <iostream>
#include "../include/conversations.h"

void FloatingTests::test_fp_add() {
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

  Conversations::double_to_bits(double_value1, input_a_bits);
  Conversations::double_to_bits(double_value2, input_b_bits);
  Conversations::double_to_bits(add, output_add_bits);

  std::cout << "\nFP-add Input a bits:\n";
  Conversations::print_bits(input_a_bits);

  std::cout << "\nFP-add Input b bits:\n";
  Conversations::print_bits(input_b_bits);

  std::cout << "\nFP-add output bits:\n";
  Conversations::print_bits(output_add_bits);

  //  // Bits to double conversion
  //  double temp;
  //  Conversations::bits_to_double(output_add_bits, temp);
  //  std::cout << "\nFP-add output (double): " << temp << "\n";
}