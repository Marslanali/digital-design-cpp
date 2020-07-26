//
// Created by arslan on 20/7/20.
//

#ifndef DIGITALDESIGN_CONSTANTS_H
#define DIGITALDESIGN_CONSTANTS_H

// 64 bits inputs
std::string input_a1 = "0010101101100010101010101000101010101001010110110011011110001010";
std::string input_b1 = "0000010101101100010101010101000101010101001010110110011011110000";

// to check mult64
std::string input_a2 = "0000000000000000000000000000000000000000000000000000000000001110"; // Decimal = 14
std::string input_b2 = "0000000000000000000000000000000000000000000000000000000000000010"; // Decimal = 2
                                                                                            // Div = 7, Mul = 28

// to check div64
std::string input_a3 = "0000000000000000000000000000000000000000000000000000000000001111"; // Decimal = 15
std::string input_b3 = "0000000000000000000000000000000000000000000000000000000000000011"; // Decimal = 3
                                                                                          // Div = 5, Mul = 45

// to check div64
std::string input_a4 = "0000000000000000000000000000000000000000000000000000000000011110"; // Decimal = 30
std::string input_b4 = "0000000000000000000000000000000000000000000000000000000000001010"; // Decimal = 10
                                                                                           // Div = 3, Mul = 300

// to check zero_equal and neg64
std::string input_single = "0001000110011101000100001111111100010111111101111001001010000101";







#endif //DIGITALDESIGN_CONSTANTS_H
