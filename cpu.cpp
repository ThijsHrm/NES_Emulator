#include "cpu.h"

Cpu::Cpu() {
}

void Cpu::disassemble(std::pair<std::uint_least8_t, std::uint_least16_t> opcode_d) {

	std::uint_least8_t opcode = opcode_d.first;
	std::uint_least16_t buffer_address = opcode_d.second;

	switch (opcode) {

	// ADC - Add With Carry
	case 0x69: std::cout << "ADC imm - " << unsigned(buffer_address) << std::endl; break;
	case 0x65: std::cout << "ADC zp" << std::endl; break;
	case 0x75: std::cout << "ADC zp, X" << std::endl; break;
	case 0x6d: std::cout << "ADC abs" << std::endl; break;
	case 0x7d: std::cout << "ADC abs, X" << std::endl; break;
	case 0x79: std::cout << "ADC abs, Y" << std::endl; break;
	case 0x61: std::cout << "ADC (ind, X)" << std::endl; break;
	case 0x71: std::cout << "ADC (ind), Y" << std::endl; break;

	// AND
	case 0x29: std::cout << "AND imm" << std::endl; break;
	case 0x25: std::cout << "AND zp" << std::endl; break;
	case 0x35: std::cout << "AND zp, X" << std::endl; break;
	case 0x2d: std::cout << "AND abs" << std::endl; break;
	case 0x3d: std::cout << "AND abs, X" << std::endl; break;
	case 0x39: std::cout << "AND abs, Y" << std::endl; break;
	case 0x21: std::cout << "AND (ind, X)" << std::endl; break;
	case 0x31: std::cout << "AND (ind), Y" << std::endl; break;

	// ASL - Arithmetic Shift Left
	case 0x0a: std::cout << "ASL" << std::endl; break;
	case 0x06: std::cout << "ASL zp" << std::endl; break;
	case 0x16: std::cout << "ASL zp, X" << std::endl; break;
	case 0x0e: std::cout << "ASL abs" << std::endl; break;
	case 0x1e: std::cout << "ASL abs, X" << std::endl; break;

	// BCC - Branch if Carry Clear
	case 0x90: std::cout << "BCC rel" << std::endl; break;
	// BCS - Branch if Carry Set
	case 0xb0: std::cout << "BCS rel" << std::endl; break;
	// BEQ - Branch if EQual
	case 0xf0: std::cout << "BEQ rel" << std::endl; break;
	// BMI - Branch if Minus
	case 0x30: std::cout << "BMI rel" << std::endl; break;
	// BNE - Branch if Not Equal
	case 0xd0: std::cout << "BNE rel" << std::endl; break;
	// BPL - Branch if Positive
	case 0x10: std::cout << "BPL rel" << std::endl; break;
	// BVC - Branch if oVerflow Clear
	case 0x50: std::cout << "BVC rel" << std::endl; break;
	// BVS - Branch if oVerflow Set
	case 0x70: std::cout << "BVS rel" << std::endl; break;

	// BIT  - Bit Test         
	case 0x24: std::cout << "BIT zp" << std::endl; break;
	case 0x2c: std::cout << "BIT abs" << std::endl; break;

	// BRK - Force Interrupt
	case 0x00: std::cout << "BRK - " << unsigned(buffer_address) << std::endl; break;

	// CLC - Clear Carry Flag
	case 0x18: std::cout << "CLC" << std::endl; break;
	// CLD - Clear Decimal Mode
	case 0xd8: std::cout << "CLD" << std::endl; break;
	// CLI - Clear Interrupt Disable
	case 0x58: std::cout << "CLI" << std::endl; break;
	// CLV - Clear Overflow Flag
	case 0xb8: std::cout << "CLV " << std::endl; break;

	// CMP - Compare
	case 0xc9: std::cout << "CMP imm" << std::endl; break;
	case 0xc5: std::cout << "CMP zp" << std::endl; break;
	case 0xd5: std::cout << "CMP zp, X" << std::endl; break;
	case 0xcd: std::cout << "CMP abs" << std::endl; break;
	case 0xdd: std::cout << "CMP abs, X" << std::endl; break;
	case 0xd9: std::cout << "CMP abs, Y" << std::endl; break;
	case 0xc1: std::cout << "CMP (ind, X)" << std::endl; break;
	case 0xd1: std::cout << "CMP (ind), Y" << std::endl; break;
	// CPX - Compare X Register
	case 0xe0: std::cout << "CPX imm" << std::endl; break;
	case 0xe4: std::cout << "CPX zp" << std::endl; break;
	case 0xec: std::cout << "CPX abs" << std::endl; break;
	// CPY - Compare Y Register
	case 0xc0: std::cout << "CPY imm" << std::endl; break;
	case 0xc4: std::cout << "CPY zp" << std::endl; break;
	case 0xcc: std::cout << "CPY abs" << std::endl; break;

	// DEC - Decrement memory
	case 0xc6: std::cout << "DEC zp" << std::endl; break;
	case 0xd6: std::cout << "DEC zp, X" << std::endl; break;
	case 0xce: std::cout << "DEC abs" << std::endl; break;
	case 0xde: std::cout << "DEC abs, X" << std::endl; break;
	// DEX - Decrement X register
	case 0xca: std::cout << "DEX" << std::endl; break;
	// DEY - Decrement Y register
	case 0x88: std::cout << "DEY" << std::endl; break;

	// EOR - XOR
	case 0x49: std::cout << "EOR imm" << std::endl; break;
	case 0x45: std::cout << "EOR zp" << std::endl; break;
	case 0x55: std::cout << "EOR zp, X" << std::endl; break;
	case 0x4d: std::cout << "EOR abs" << std::endl; break;
	case 0x5d: std::cout << "EOR abs, X" << std::endl; break;
	case 0x59: std::cout << "EOR abs, Y" << std::endl; break;
	case 0x41: std::cout << "EOR (ind, X)" << std::endl; break;
	case 0x51: std::cout << "EOR (ind), Y" << std::endl; break;

	// INC - Increment Memory
	case 0xe6: std::cout << "INC zp" << std::endl; break;
	case 0xf6: std::cout << "INC zp, X" << std::endl; break;
	case 0xee: std::cout << "INC abs" << std::endl; break;
	case 0xfe: std::cout << "INC abs, X" << std::endl; break;
	// INX - Increment X
	case 0xe8: std::cout << "INX" << std::endl; break;
	// INY - Increment Y
	case 0xc8: std::cout << "INY" << std::endl; break;

	// JMP
	case 0x4c: std::cout << "JMP abs" << std::endl; break;
	case 0x6c: std::cout << "JMP ind" << std::endl; break;
	// JSR - Jump to Subroutine
	case 0x20: std::cout << "JSR abs" << std::endl; break;

	// LDA - Load Accumulator
	case 0xa9: std::cout << "LDA imm" << std::endl; break;
	case 0xa5: std::cout << "LDA zp" << std::endl; break;
	case 0xb5: std::cout << "LDA zp, X" << std::endl; break;
	case 0xad: std::cout << "LDA abs" << std::endl; break;
	case 0xbd: std::cout << "LDA abs, X" << std::endl; break;
	case 0xb9: std::cout << "LDA abs, Y" << std::endl; break;
	case 0xa1: std::cout << "LDA (ind, X)" << std::endl; break;
	case 0xb1: std::cout << "LDA (ind), Y" << std::endl; break;

	// LDX - Load X Register
	case 0xa2: std::cout << "LDX imm" << std::endl; break;
	case 0xa6: std::cout << "LDX zp" << std::endl; break;
	case 0xb6: std::cout << "LDX zp, Y" << std::endl; break;
	case 0xae: std::cout << "LDX abs" << std::endl; break;
	case 0xbe: std::cout << "LDX abs, Y" << std::endl; break;

	// LDY - Load Y Register
	case 0xa0: std::cout << "LDY imm" << std::endl; break;
	case 0xa4: std::cout << "LDY zp" << std::endl; break;
	case 0xb4: std::cout << "LDY zp, X" << std::endl; break;
	case 0xac: std::cout << "LDY abs" << std::endl; break;
	case 0xbc: std::cout << "LDY abs, X" << std::endl; break;

	// LSR - Logical Shift Right
	case 0x4a: std::cout << "LSR imm" << std::endl; break;
	case 0x46: std::cout << "LSR zp" << std::endl; break;
	case 0x56: std::cout << "LSR zp, X" << std::endl; break;
	case 0x4e: std::cout << "LSR abs" << std::endl; break;
	case 0x5e: std::cout << "LSR abs, X" << std::endl; break;

	// NOP
	case 0xea: std::cout << "NOP" << std::endl; break;

	// ORA - Logical Inclusive OR
	case 0x09: std::cout << "ORA imm" << std::endl; break;
	case 0x05: std::cout << "ORA zp" << std::endl; break;
	case 0x15: std::cout << "ORA zp, X" << std::endl; break;
	case 0x0d: std::cout << "ORA abs" << std::endl; break;
	case 0x1d: std::cout << "ORA abs, X" << std::endl; break;
	case 0x19: std::cout << "ORA abs, Y" << std::endl; break;
	case 0x01: std::cout << "ORA (ind, X)" << std::endl; break;
	case 0x11: std::cout << "ORA (ind), Y" << std::endl; break;

	// PHA - Push Accumulator
	case 0x48: std::cout << "PHA" << std::endl; break;
	// PHP - Push Processor Status
	case 0x08: std::cout << "PHP" << std::endl; break;
	// PLA - Pull Accumulator
	case 0x68: std::cout << "PLA" << std::endl; break;
	// PLP - Pull Processor Status
	case 0x28: std::cout << "PLP" << std::endl; break;

	// ROL - Rotate Left
	case 0x2a: std::cout << "ROL acc" << std::endl; break;
	case 0x26: std::cout << "ROL zp" << std::endl; break;
	case 0x36: std::cout << "ROL zp, X" << std::endl; break;
	case 0x2e: std::cout << "ROL abs" << std::endl; break;
	case 0x3e: std::cout << "ROL abs, X" << std::endl; break;

	// ROR - Rotate Right
	case 0x6a: std::cout << "ROL acc" << std::endl; break;
	case 0x66: std::cout << "ROL zp" << std::endl; break;
	case 0x76: std::cout << "ROL zp, X" << std::endl; break;
	case 0x6e: std::cout << "ROL abs" << std::endl; break;
	case 0x7e: std::cout << "ROL abs, X" << std::endl; break;

	// RTI - Return from Interrupt
	case 0x40: std::cout << "RTI" << std::endl; break;
	// RTS - Return from Subroutine
	case 0x60: std::cout << "RTS" << std::endl; break;

	// SBC - Subtract with Carry
	case 0xe9: std::cout << "SBC imm" << std::endl; break;
	case 0xe5: std::cout << "SBC zp" << std::endl; break;
	case 0xf5: std::cout << "SBC zp, X" << std::endl; break;
	case 0xed: std::cout << "SBC abs" << std::endl; break;
	case 0xfd: std::cout << "SBC abs, X" << std::endl; break;
	case 0xf9: std::cout << "SBC abs, Y" << std::endl; break;
	case 0xe1: std::cout << "SBC (ind, X)" << std::endl; break;
	case 0xf1: std::cout << "SBC (ind), Y" << std::endl; break;

	// SEC - Set Carry Flag
	case 0x38: std::cout << "SEC" << std::endl; break;
	// SED - Set Decimal Flag
	case 0xf8: std::cout << "SED" << std::endl; break;
	// SEI - Set Interrupt Disable
	case 0x78: std::cout << "SEI" << std::endl; break;

	// STA - Store Accumulator
	case 0x85: std::cout << "STA zp" << std::endl; break;
	case 0x95: std::cout << "STA zp, X" << std::endl; break;
	case 0x8d: std::cout << "STA abs" << std::endl; break;
	case 0x9d: std::cout << "STA abs, X" << std::endl; break;
	case 0x99: std::cout << "STA abs, Y" << std::endl; break;
	case 0x81: std::cout << "STA (ind, X)" << std::endl; break;
	case 0x91: std::cout << "STA (ind), Y" << std::endl; break;

	// STX - Store X Register
	case 0x86: std::cout << "STX zp" << std::endl; break;
	case 0x96: std::cout << "STX zp, Y" << std::endl; break;
	case 0x8e: std::cout << "STX abs" << std::endl; break;

	// STY - Store Y Register
	case 0x84: std::cout << "STY zp" << std::endl; break;
	case 0x94: std::cout << "STY zp, X" << std::endl; break;
	case 0x8c: std::cout << "STY abs" << std::endl; break;

	// TAX - Transfer Accumulator to X
	case 0xaa: std::cout << "TAX" << std::endl; break;
	// TAY - Transfer Accumulator to Y
	case 0xa8: std::cout << "TAY" << std::endl; break;
	// TSX - Transfer Stack pointer to X
	case 0xba: std::cout << "TSX" << std::endl; break;
	// TXA - Transfer X to Accumulator
	case 0x8a: std::cout << "TXA" << std::endl; break;
	// TXS - Transfer X to Stack Pointer
	case 0x9a: std::cout << "TXS" << std::endl; break;
	// TYA - Transfer Y to Accumulator
	case 0x98: std::cout << "TYA" << std::endl; break;

	// The default answer
	default: std::cout << "##############################" << std::endl; break;

	//case 0x00: std::cout << "" << std::endl; break;
	}

}
