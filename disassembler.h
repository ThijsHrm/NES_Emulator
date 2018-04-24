#ifndef DISASSEMBLER_H
#define DISASSEMBLER_H

#include <iostream>
#include <fstream>
#include <string>

class Disassembler {
public:

	// class constructor
    Disassembler();

	// public methods
    void disassemble(std::pair<std::uint_least8_t, std::uint_least8_t> opcode);

private:

};

#endif /* DISASSEMBLER_H */

