# parseopt

Object-oriented extended command-line options parsing library for C++

## About

This library provides an object-oriented C++ version of the well-known C *getopt* function allowing to parse command-line options of console applications. The motivation to create this library was to create a full-C++ *getopt* alternative in order to be able to walk-around the low-level C types and memory allocations and facilitate the syntax which is behind options parsing.

## Features

**parseopt** allows you to define the list of options and their arguments. Each option can be defined in its short (only one character) or its long (possibly multiple characters) form. Options can be either preceded by a dash or a slash, depending on the target operating system or user's preference.

## Usage

### Options definition

Firstly, you have to define a *vector* contaning the list of the options (expressed as instances of the *option* class) to support. 

### Parsing

The parsing is done in the same way as in the case of 'getopt' using a while loop calling the parsing function 'parseopt' until the last option get parsed.

The only difference is, that you can't you a switch construct inside the while loop to associate an action to different options as they are not expressed using basic data types. Nevertheless, provided comparison operator overloads allows you to use simple if conditions to test the (in)equality of two options.

## Example

See the [example file](example.cpp). You can build the example using `make example` command. The output binary should have the default name *a.out*.

## Installation instructions

After extracting the source files, run `make` and then `sudo make install` to install the library on your Linux system.

**CAUTION:** The installation script works only on Linux distributions! On other operating systems you will have to install the library manually.

**IMPORTANT:** Whenever you use the library in your project, do not forget to add `#include <parseopt.h>` to concerned source files and **-lparseopt** to your compilation command in order to link the library properly with your project!

*To uninstall the library, run `sudo make uninstall`.*

## Author

[Marek Felsoci](mailto:marek.felsoci@gmail.com) - Master's degree student at the [University of Strasbourg](http://www.unistra.fr)

## License

This library is released under the MIT Licence. See the [license file](LICENSE) for further details.

