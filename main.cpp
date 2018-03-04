#include "disassembler.h"
#include "romreader.h"
#include <iostream>
#include <fstream>
#include <string>

//
//  NES EMULATOR PROJECT
//

int main() {
    
    disassembler disassembler_;
    romreader romreader_;

    romreader_.read_file("smb.nes");
	disassembler_.disassemble(romreader_.return_opcode(0));
	disassembler_.disassemble(romreader_.return_opcode(1));
	disassembler_.disassemble(romreader_.return_opcode(2));
	disassembler_.disassemble(romreader_.return_opcode(3));
	disassembler_.disassemble(romreader_.return_opcode(4));
	disassembler_.disassemble(romreader_.return_opcode(5));
	disassembler_.disassemble(romreader_.return_opcode(6));
	disassembler_.disassemble(romreader_.return_opcode(7));
    disassembler_.disassemble(romreader_.return_opcode(8));

	std::getchar();
    
    return 0;
}

