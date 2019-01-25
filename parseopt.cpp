/**
 * This file is part of the parseopt library.
 * 
 * Author: Marek Felsoci
 * 
 * MIT License (see LICENSE file)
**/ 
#include "parseopt.h"

std::vector<std::string> optparams;
int optindex = 1;

option::option() {
  this->setShortOption('?');
  this->setParametersCount(0);
  this->setLongOption("");
  this->setLongOnly(false);
}

option::option(char short_option, int parameters_count, std::string long_option) {
  this->setShortOption(short_option);
  this->setParametersCount(parameters_count);
  this->setLongOption(long_option);
  this->setLongOnly(false);
}

option::option(std::string long_option, int parameters_count) {
  this->setShortOption('?');
  this->setLongOption(long_option);
  this->setParametersCount(parameters_count);
  this->setLongOnly(true);
}

char option::getShortOption() const {
  return this->short_option;
}

int option::getParametersCount() const {
  return this->parameters_count;
}

std::string option::getLongOption() const {
  return this->long_option;
}

bool option::getLongOnly() const {
  return this->long_only;
}

void option::setShortOption(char short_option) {
  this->short_option = short_option;
}

void option::setParametersCount(int parameters_count) {
  this->parameters_count = parameters_count;
}

void option::setLongOption(std::string long_option) {
  this->long_option = long_option;
}

void option::setLongOnly(bool long_only) {
  this->long_only = long_only;
}

bool option::isEmpty() const {
  return (this->short_option == '?' && this->long_option.empty());
}

bool option::operator==(const option &other) {
  return (this->long_only ? !this->long_option.compare(other.long_option) : this->short_option == other.short_option);
}

bool option::operator==(const char &other) {
  return this->short_option == other;
}

bool option::operator==(const std::string &other) {
  return !this->long_option.compare(other);
}

bool option::operator!=(const option &other) {
  return !this->operator == (other);
}

bool option::operator!=(const char &other) {
  return !this->operator == (other);
}

bool option::operator!=(const std::string &other) {
  return !this->operator == (other);
}

option parseopt(const int argc, const char * const * argv, std::vector<option> options) {
  if(argc < 2) return optend; // If there is no arguments/options, return end of options list.

  optparams.clear();

  // Skip all the arguments (if any)
  while(optindex < argc && argv[optindex][0] != '-' && argv[optindex][0] != '/') {
    optindex++;
  }

  // If there were arguments but no options, return end of options list.
  if(optindex >= argc) {
    optindex = 1;
    return optend;
  }

  std::string long_argument(argv[optindex]); // Get the current option.
  
  bool is_short = long_argument.size() == 2; // If there are only two chars (e. g. '-x') it's a short option.
  char short_argument = argv[optindex][1]; // Get the option name (e. g. 'x') without the dash or the slash. 
  
  if(!is_short)
	long_argument = argv[optindex][0] == '/' ? long_argument.erase(0, 1) : long_argument.erase(0, 2); // Remove dashes or slash from the beginning of a long option name.
	
  option current;
  std::vector<option>::iterator i;
  bool found = false;

  // Search the parsed option among supported options.
  for(i = options.begin(); i != options.end(); i++) {
    current = *i;
    if((is_short && current == short_argument) || (!is_short && current == long_argument)) {
      found = true;
      break;
    }
  }

  optindex++;

  if(!found) { // If the option is not recognized, return unknown option.
    return optunknown;
  }

  int shift = optindex;

  // Parse option's argument(s) to the 'optparams' list and check if there is the expected number of them, otherwise show debug info and return end of options list.
  for(int j = shift; j < shift + current.getParametersCount(); j++) {
	if(j >= argc || argv[j][0] == '-' || argv[j][0] == '/') {
		std::cerr << "Option '" << (current.getLongOnly() ? current.getLongOption() : std::string(1, current.getShortOption())) << "' expects " << current.getParametersCount() << " argument" << (current.getParametersCount() > 1 ? "s!" : "!") << std::endl;
		optindex = 1;
		return optend;
	}
	
    optparams.push_back(std::string(argv[j]));
    optindex++;
  }

  return current;
}
