#include "romreader.h"
#include "cpu.h"
#include <iostream>
#include <fstream>
#include <string>

//
//  NES EMULATOR PROJECT
//

int main() {
    
	Cpu cpu;
    Romreader romreader;

    romreader.read_file("smb.nes");
	for (int i = 0; i < 100; i++) {
		std::pair<std::uint_least8_t, std::uint_least8_t> opcode = romreader.return_opcode(i);
		cpu.disassembler.disassemble(opcode);
	}

	std::getchar();
    
    return 0;
}

