//
// Created by arslan on 7/8/20.
//
#include <math.h>
#include <iostream>

#include "../include/FloatingSimpleTests.h"
#include "../include/conversations.h"

void FloatingTests::test_fp_add() {
  std::cout << "\n============ Testing FP-add With Addition Operator ============\n";
  // double value floating points
  double double_value1 = 2.5625;
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

  std::cout << "\nInput A (64 bits): \n";
  Conversations::print_bits(input_a_bits);

  std::cout << "\nInput B (64 bits): \n";
  Conversations::print_bits(input_b_bits);

  std::cout << "\nOutput 64 bits: \n";
  Conversations::print_bits(output_add_bits);

  // Bits to double conversion
  double temp;
  Conversations::bits_to_double(output_add_bits, temp);
  std::cout << "\nFP-add output (double): " << temp << "\n";
}

void FloatingTests::test_fp_mul() {
  std::cout << "\n============ Testing FP-mul With Multiplication Operator ============\n";
  // double value floating points
  double double_value1 = 2.5625;
  double double_value2 = 1.5625;
  double mul = double_value1 * double_value2;
  std::cout << "\nFP-mul: " << double_value1 << " * " << double_value2 << " = " << mul << std::endl;

  // Double to bits conversion
  std::string input_a_bits(64, 'x');
  std::string input_b_bits(64, 'x');
  std::string output_add_bits(64, 'x');

  Conversations::double_to_bits(double_value1, input_a_bits);
  Conversations::double_to_bits(double_value2, input_b_bits);
  Conversations::double_to_bits(mul, output_add_bits);

  std::cout << "\nInput A (64 bits): \n";
  Conversations::print_bits(input_a_bits);

  std::cout << "\nInput B (64 bits): \n";
  Conversations::print_bits(input_b_bits);

  std::cout << "\nOutput 64 bits: \n";
  Conversations::print_bits(output_add_bits);

  // Bits to double conversion
  double temp;
  Conversations::bits_to_double(output_add_bits, temp);
  std::cout << "\nFP-mul output (double): " << temp << "\n";
}

void FloatingTests::test_fp_div() {
  std::cout << "\n============ Testing FP-div With Division Operator ============\n";
  // double value floating points
  double double_value1 = 2.5625;
  double double_value2 = 1.5625;
  double div = double_value1 / double_value2;
  std::cout << "\nFP-div: " << double_value1 << " / " << double_value2 << " = " << div << std::endl;

  // Double to bits conversion
  std::string input_a_bits(64, 'x');
  std::string input_b_bits(64, 'x');
  std::string output_add_bits(64, 'x');

  Conversations::double_to_bits(double_value1, input_a_bits);
  Conversations::double_to_bits(double_value2, input_b_bits);
  Conversations::double_to_bits(div, output_add_bits);

  std::cout << "\nInput A (64 bits): \n";
  Conversations::print_bits(input_a_bits);

  std::cout << "\nInput B (64 bits): \n";
  Conversations::print_bits(input_b_bits);

  std::cout << "\nOutput 64 bits: \n";
  Conversations::print_bits(output_add_bits);

  // Bits to double conversion
  double temp;
  Conversations::bits_to_double(output_add_bits, temp);
  std::cout << "\nFP-div output (double): " << temp << "\n";
}

void FloatingTests::test_fp_sqrt() {
  std::cout << "\n============ Testing FP-sqrt With Pow Operator ============\n";
  // double value floating points
  double double_value1 = 2.5625;
  double sqrt = pow(double_value1, 0.5);
  std::cout << "\nFP-sqrt: " << double_value1 << " = " << sqrt << std::endl;

  // Double to bits conversion
  std::string input_a_bits(64, 'x');
  std::string output_add_bits(64, 'x');

  Conversations::double_to_bits(double_value1, input_a_bits);
  Conversations::double_to_bits(sqrt, output_add_bits);

  std::cout << "\nInput A (64 bits): \n";
  Conversations::print_bits(input_a_bits);

  std::cout << "\nOutput 64 bits: \n";
  Conversations::print_bits(output_add_bits);

  // Bits to double conversion
  double temp;
  Conversations::bits_to_double(output_add_bits, temp);
  std::cout << "\nFP-sqrt output (double): " << temp << "\n";
}

void FloatingTests::test_fp_f2i() {
  std::cout << "\n============ Testing FP-f2i With (long)nearbyint Operator ============\n";
  // double value floating points
  double double_value1 = 2.5625;
  auto f2i = (long)nearbyint(double_value1);  // Round nearest-even rounding
  std::cout << "\nFP-f2i: " << double_value1 << " = " << f2i << std::endl;

  // Double to bits conversion
  std::string input_a_bits(64, 'x');
  std::string output_add_bits(64, 'x');

  Conversations::double_to_bits(double_value1, input_a_bits);
  Conversations::long_to_bits(f2i, output_add_bits);

  std::cout << "\nInput A (64 bits): \n";
  Conversations::print_bits(input_a_bits);

  std::cout << "\nOutput 64 bits: \n";
  Conversations::print_bits(output_add_bits);
}

void FloatingTests::test_fp_i2f() {
    std::cout << "\n============ Testing FP-i2f With (double) Operator ============\n";
    long int int_value1 = 2;
    auto i2f = (double)(int_value1);  // Round nearest-even rounding
    std::cout << "\nFP-i2f: " << int_value1 << " = " << i2f << std::endl;

    // Double to bits conversion
    std::string input_a_bits(64, 'x');
    std::string output_add_bits(64, 'x');

    Conversations::long_to_bits(int_value1, input_a_bits);
    Conversations::double_to_bits(i2f, output_add_bits);

    std::cout << "\nInput A (64 bits): \n";
    Conversations::print_bits(input_a_bits);

    std::cout << "\nOutput 64 bits: \n";
    Conversations::print_bits(output_add_bits);
}