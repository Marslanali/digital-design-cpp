//
// Created by arslan on 7/8/20.
//

#ifndef DIGITALDESIGN_CONVERSATIONS_H
#define DIGITALDESIGN_CONVERSATIONS_H

#include <iostream>
#include <string>
#include <vector>

class Conversations {
 private:
 public:
  static void bits_to_double(const std::string &bits, double &x);
  static void double_to_bits(double x, std::string &bits);
  static void print_bits(const std::string &bits);
  static void test_conversation_all();
  static void long_to_bits(unsigned long x, std::string &bits);
};

#endif  // DIGITALDESIGN_CONVERSATIONS_H
