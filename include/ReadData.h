//
// Created by arslan on 10/7/20.
//

#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <fstream>
#include <iostream>
#include <iterator>
#include <math.h>
#include <memory>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

#ifndef DIGITALDESIGN_READDATA_H
#define DIGITALDESIGN_READDATA_H

class ReadData
{
  private:
    // file reading variables
    std::string file_path_;
    std::string delimeter_;

  public:
    // No argument constructor
    ReadData(){};

    // Two argument constructor
    ReadData(std::string file_path, std::string delimeter_ = " ") : file_path_(file_path), delimeter_(delimeter_) {}

    // Function to fetch data from a text File
    std::vector<std::vector<std::string>> get_data();
};

#endif // DIGITALDESIGN_READDATA_H
