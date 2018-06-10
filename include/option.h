#ifndef __PARSEOPT_H
#define __PARSEOPT_H

#include <string>
#include <vector>
#include <iostream>

extern std::vector<std::string> optparams;
extern int optindex;

class option {
  private:
    char short_option;
    int parameters_count;
    std::string long_option;

  public:
    option();
    option(char short_option, int parameters_count = 0, std::string long_option = "");
    char getShortOption() const;
    int getParametersCount() const;
    std::string getLongOption() const;
    void setShortOption(char short_option);
    void setParametersCount(int parameters_count);
    void setLongOption(std::string long_option);
    bool isEmpty() const;
    bool operator==(const option &other);
    bool operator==(const char &other);
    bool operator==(const std::string &other);
    bool operator!=(const option &other);
    bool operator!=(const char &other);
    bool operator!=(const std::string &other);
};

const static option optend = option(-1),
  optunknown = option('?');

option parseopt(const int argc, const char * const * argv, std::vector<option> options);

#endif // __PARSEOPT_H
