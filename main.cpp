#include <boost/algorithm/string.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <fstream>


int main(int argc, char** argv) { 
   std::string input1 = "1010101101100010101010101000101010101001010110110011011110001010";
   std::string input2 = "0000010101101100010101010101000101010101001010110110011011110001";

   std::string line;
   std::vector<std::vector<std::string>> gates;
   std::ifstream input_file(argv[1]);

   while (getline(input_file, line)) {  
      std::vector<std::string> agate;
      boost::algorithm::split(agate, line, boost::is_any_of(" "));
      gates.push_back(agate);
   }
 
   int num_wires = std::stoi(gates[0][1]);
  int nnum_input = std::stoi(gates[1][0]);
   char input1_bits[nnum_input + 1];
   strcpy(input1_bits, input1.c_str());
   char input2_bits[nnum_input + 1];
   strcpy(input2_bits, input2.c_str());

   int wires[num_wires];
 
   for (int temp = 4; temp <= 67; ++temp) {//first, copy input bits into wires (note:circuit's wires go sequentially as inputbits, hence copy sequentially)
      wires[std::stoi(gates[temp][2])] = input1[temp - 4] - 48;
      wires[std::stoi(gates[temp][3])] = input2[temp - 4] - 48;
      //std::cout << wires[std::stoi(gates[temp][2])] << ":" << wires[std::stoi(gates[temp][3])] << std::endl;
   }
 
   for (int temp = 4; temp < gates.size(); ++temp) {//evaluate each gate
      //std::cout << temp << "::" << gates[temp][5] << std::endl;

      if (gates[temp][5] == "XOR") {//?
         wires[std::stoi(gates[temp][4])] = wires[std::stoi(gates[temp][2])] ^ wires[std::stoi(gates[temp][3])]; 
         std::cout <<"===xor===="<< gates[temp][4] << std::endl;
      }
      else if (gates[temp][5] == "AND") {//?
         wires[std::stoi(gates[temp][4])] = wires[std::stoi(gates[temp][2])] & wires[std::stoi(gates[temp][3])];
         std::cout << "===and===="<< gates[temp][4]  << std::endl;
      }

   }
 
   for (int temp = num_wires - 1; temp >= num_wires - 64; temp--) {
      //std::cout << temp;
      ///std::cout << ":";
      std::cout << wires[temp];
   }
   std::cout << std::endl;

}
