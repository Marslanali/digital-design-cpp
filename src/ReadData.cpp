//
// Created by arslan on 10/7/20.
//

#include "../include/ReadData.h"
#include "../include/Exception.h"
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::vector<std::string>> ReadData::get_data()
{
    // read the circuit data from file path
    std::string file_path = file_path_;

    // read the circuit data from given file path
    std::ifstream file(file_path);

    if (!file)
    {
        // throw std::runtime_error("Could not open file");
        throw_line("Could not open file");
    }
    else
    {
        // create vector of vector  of type string
        std::vector<std::vector<std::string>> data_list;

        std::string line = "";
        /*Iterate through each line and split the content using delimeter*/
        while (getline(file, line))
        {
            std::vector<std::string> vec;
            boost::algorithm::split(vec, line, boost::is_any_of(delimeter_));
            data_list.push_back(vec);
        }

        // Close the File
        file.close();

        return data_list;
    }
}
