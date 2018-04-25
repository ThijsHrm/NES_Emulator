#ifndef ROMREADER_H
#define ROMREADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <vector>
#include <bitset>

// Type specification for returning rom data
typedef std::pair<std::vector <std::uint_least8_t>, std::vector <std::uint_least8_t>> romdata;

// Type specification for returning opcodes
typedef std::pair<std::uint_least8_t, std::uint_least8_t> opcode;

class Romreader {
public:

	// class constructor and destructor
	Romreader();
	~Romreader();

	// public methods
	romdata read_file(std::string);
	opcode return_opcode(std::uint_least16_t);

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

