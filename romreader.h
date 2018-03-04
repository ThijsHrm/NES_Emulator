#ifndef ROMREADER_H
#define ROMREADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <vector>
#include <bitset>

class romreader {
public:

	// class constructor and destructor
    romreader();
    ~romreader();

	// public methods
    void read_file(std::string);
    std::uint_least8_t return_opcode(std::uint_least8_t);

private:

	// for opening rom files
    std::ifstream current_file;
    bool validate_ines(char *);

	// for extracting data from rom files
	std::vector <std::uint_least8_t> rom_data;
	std::vector <std::uint_least8_t> rom_meta_data;
	char * byte_reader;

	// private methods
    int open_rom_file(std::string file_name);
    
};

#endif /* ROMREADER_H */

