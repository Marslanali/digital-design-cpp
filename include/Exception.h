//
// Created by arslan on 20/7/20.
//

#ifndef DIGITALDESIGN_EXCEPTION_H
#define DIGITALDESIGN_EXCEPTION_H

#define throw_line(arg) throw my_exception(arg, __FILE__, __LINE__);

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

class my_exception : public std::runtime_error
{
  private:
    std::string msg;

  public:
    my_exception(const std::string& arg, const char* file, int line) : std::runtime_error(arg)
    {
        std::ostringstream o;
        o << file << ":" << line << ": " << arg;
        msg = o.str();
    }
    ~my_exception() throw() {}

    const char* what() const throw() { return msg.c_str(); }
};

#endif //DIGITALDESIGN_EXCEPTION_H
