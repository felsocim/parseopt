/**
 * This file is part of the parseopt library.
 * 
 * Author: Marek Felsoci
 * 
 * MIT License (see LICENSE file)
**/ 
#ifndef __PARSEOPT_H
#define __PARSEOPT_H

#include <string>
#include <vector>
#include <iostream>

extern std::vector<std::string> optparams; // Stores arguments provided (if any) to the currently parsed option
extern int optindex; // Index of the currently parsed option

class option {
  private:
    char short_option;
    int parameters_count;
    std::string long_option;
    bool long_only;

  public:
    option();
    option(char short_option, int parameters_count = 0, std::string long_option = "");
    option(std::string long_option, int parameters_count = 0);
    char getShortOption() const;
    int getParametersCount() const;
    std::string getLongOption() const;
    bool getLongOnly() const;
    void setShortOption(char short_option);
    void setParametersCount(int parameters_count);
    void setLongOption(std::string long_option);
    void setLongOnly(bool long_only);
    bool isEmpty() const;
    bool operator==(const option &other);
    bool operator==(const char &other);
    bool operator==(const std::string &other);
    bool operator!=(const option &other);
    bool operator!=(const char &other);
    bool operator!=(const std::string &other);
};

const static option optend = option(-1), // Defines the end of the list of options
  optunknown = option('?'); // Defines an unknown option

option parseopt(const int argc, const char * const * argv, std::vector<option> options);

#endif // __PARSEOPT_H
