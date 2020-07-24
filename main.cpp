//
// Created by arslan on 7/7/20.
//

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "../digitaldesign/include/Circuits.h"
#include "../digitaldesign/include/Constants.h"
#include "../digitaldesign/include/ReadData.h"

/*std::string key =
"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
std::string message =
"11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";*/

/*// Key
std::string key2(192, 'x');
// Message
std::string message2(128, 'x');*/

void test_arithmetic(std::string file_path, int input_a_size, const int input_b_size, const int output_size) {
  ////////////////////////////////////// Arithmetic Functions ///////////////////////////////////////////////////
  // Create and instance of ReadData class and called constructor
  ReadData text_file_read(file_path);

  // Get the data from text File
  std::vector<std::vector<std::string>> data_list = text_file_read.get_data();

  // Create an instance of Circuit class
  Circuits* circuit_obj = new Circuits;

  // circuit_obj calling to its member function i.e display_circuit
  circuit_obj->display_circuit(data_list);

  // Key
  std::string key(input_a_size, 'x');
  // Message
  std::string message(input_b_size, 'x');

  // Key
  for (int i = 0; i < input_a_size; ++i) {
    key[i] = '0';
  }

  // Message
  for (int i = 0; i < input_b_size; ++i) {
    message[i] = '1';
  }


  /*
  if (file_path == "../data/arithmetic-functions/Keccak_f.txt")
  {
      // Input A 64-bits
      char* char_array1 = circuit_obj->read_inputs_A(input_single);

      std::vector<unsigned int> return_wires = circuit_obj->arithmetic_functions(data_list, char_array1, NULL);
      circuit_obj->display_output(return_wires, output_size);
  }

  else
  {*/

  // Input A and B 64-bits
  char* char_array1 = circuit_obj->read_inputs_A(key);
  char* char_array2 = circuit_obj->read_inputs_B(message);

  std::vector<unsigned int> return_wires =
      circuit_obj->arithmetic_functions(data_list, char_array1, char_array2, input_a_size, input_b_size);

  circuit_obj->display_output(return_wires, output_size);


  delete circuit_obj;
}

int main(int argc, char** argv) {
  try {
   /* std::cout << "================== Testing a AES-128 Circuit ======================" << std::endl;
    test_arithmetic("../data/cryptographic-functions/aes_128.txt", 128, 128, 128);
*/
    std::cout << "================== Testing aes_192 ======================== " << std::endl;
    test_arithmetic("../data/cryptographic-functions/aes_192.txt", 192, 128, 128);

    /*        std::cout << "================== Testing aes_256 ========================" << std::endl;
    test_arithmetic("../data/arithmetic-functions/aes_256.txt", 128);

    std::cout << "================== Testing Keccak_f ========================" << std::endl;
    test_arithmetic("../data/arithmetic-functions/Keccak_f.txt", 1600);

    std::cout << "================== Testing sha256 ========================== " << std::endl;
    test_arithmetic("../data/arithmetic-functions/sha256.txt", 256);

    std::cout << "================== Testing sha512.txt ========================== " << std::endl;
    test_arithmetic("../data/arithmetic-functions/sha512.txt", 512);*/
  }

  catch (const std::runtime_error& ex) {
    std::cout << ex.what() << std::endl;
  }
  return 0;
}
