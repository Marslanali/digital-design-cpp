//
// Created by arslan on 7/8/20.
//

#include "../include/conversations.h"

// bits to double function
void Conversations::bits_to_double(const std::vector<int> &bits, double &x) {
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
void Conversations::double_to_bits(double x, std::string &bits) {
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
void Conversations::print_bits(const std::string &bits) {
  for (int i = 0; i < 64; i++) {
    std::cout << int(bits[i]);
    if (i == 0 || i == 11) {
      std::cout << " ";
    }
  }
  std::cout << std::endl;
}

void Conversations::test_conversation_all() {
  // Test conversion functions
  double double_value = 3.125;
  std::cout << "\n double value: " << double_value << "\n";

  // Double to bits conversion
  std::string bits(64, 'x');
  double_to_bits(double_value, bits);
  std::cout << "\n double to bits: ";
  print_bits(bits);

  //    // Bits to double conversion
  //    double temp;
  //    bits_to_double(bits, temp);
  //    std::cout << "\n bits to double: " << temp << "\n";
}