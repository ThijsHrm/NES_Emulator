#include "romreader.h"
#include "disassembler.h"

// =================================
//		Constructor / Desctructor
// =================================

romreader::romreader() {
    byte_reader = new char[1];
}

romreader::~romreader() {
    delete byte_reader;
}

// =================================
//		Public Methods
// =================================

// read_file is the main 
void romreader::read_file(std::string file_name) {

	// Open the rom file, return the file size 
	const unsigned int file_size = open_rom_file(file_name);

	while (current_file.read(byte_reader, 1)) {
		rom_data.push_back(byte_reader[0]);
	}

	// Read meta data
	const int meta_data_start = 4;
	const int meta_data_size = 5;
	const int meta_data_end = meta_data_start + meta_data_size;

	for (int i = meta_data_start; i <= meta_data_end; i++)
		rom_meta_data.push_back(rom_data[i]);

	// meta data mapping:
	// [0] read prg rom size in 16kb blocks
	// [1] read chr rom size in 8kb blocks
	// [2] read flags 6
	// [3] read flags 7
	// [4] read prg ram size in 8kb blocks
	// [5] read flags 9

}

//std::uint_least8_t
std::uint_least8_t romreader::return_opcode(std::uint_least8_t buffer_address) {
	return rom_data[buffer_address];
}

// =================================
//		Private Methods
// =================================

// Validation if opened file is a NES file
bool romreader::validate_ines(char * nes_brand) {
    
    // Check the first 4 bytes which are const for all .nes files
    bool validity = 1;
    if (nes_brand[0] != 0x4e) validity = 0;
    if (nes_brand[1] != 0x45) validity = 0;
    if (nes_brand[2] != 0x53) validity = 0;
    if (nes_brand[3] != 0x1a) validity = 0;
    return validity;
    
}

// Store new rom file in current_file, validate if it's a valid NES
int romreader::open_rom_file(std::string file_name) {
    
    // File opening
    current_file.clear();
    current_file.open(file_name, std::ios::binary | std::ios::in);
    if (current_file.fail()) {
        std::cerr << "Opening file failed" << std::endl;
    }
    
    // Get file size
    current_file.seekg(0, std::ios::end);
    const unsigned int file_size = current_file.tellg();
    
    // Verify if NES rom ...
    current_file.seekg(0, std::ios::beg);
    char * nes_brand = new char [4]; 
    current_file.read(nes_brand, 4);
    if (!validate_ines(nes_brand)) {
        std::cerr << "Specified input file is not a NES rom" << std::endl;
    }
    delete nes_brand;
    
    return file_size;
}