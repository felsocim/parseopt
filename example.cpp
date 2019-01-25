/**
 * This is a test file for the parseopt library.
 * 
 * Author: Marek Felsoci
 * 
 * MIT License (see LICENSE file)
 * 
 * Notes:
 * 
 * While compiling this file, do not forget to include '-lparseopt' to your compilation command (e. g. 'g++ test.cpp -lparseopt') to link the parseopt library with properly!
 * 
 * Example of execution: './a.out -w Word1 Word2' gives "Your words are 'Word1' and 'Word2'" on the standard output.
**/ 

#include <parseopt.h>
#include <iostream>

int main(int argc, char ** argv) {
	// Define the list supported options
	std::vector<option> options;
	    
	options.push_back(option('w', 2, "words")); // Option with both short and long name expecting 2 arguments.
	options.push_back(option('v', 0, "version")); // Option with both short and long name which does not expect any argument.
	options.push_back(option('s')); // Option with short name only which does not expect any argument.
	options.push_back(option("long-only")); // Option with long name only which does not expect any argument.
		  
	option current;
		    
	while((current = parseopt(argc, argv, options)) != optend) { // Parse until the end is reached (natural or caused by a parsing error).
		if(current == 'w') { // An option can be simply compared to a short name.
			std::cout << "Your words are: '" << optparams.at(0) << "' and '" << optparams.at(1) << "'" << std::endl; // We can access the option's arguments (of type std::string) thanks to the 'optparams' vector (index 0 points to the first argument and so on).
		} else if(current == 'v') {
			std::cout << "Ver. 1.0" << std::endl;
		} else if(current == 's') {
			std::cout << "short-only option" << std::endl;
		} else if(current == "long-only") { // An option can be also compared to a long name or another option.
			std::cout << "long-only option" << std::endl;
		} else {
			std::cout << "Unknown option!" << std::endl;
			return 1;
		}
	}
	
    return 0;
}
