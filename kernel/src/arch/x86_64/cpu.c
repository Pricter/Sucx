#include <kernel/arch/misc.h>

void arch_hang(void) {
	asm ("1: hlt; jmp 1");
}

void arch_hang_cli(void) {
	asm ("cli; 1: hlt; jmp 1");
}

uint8_t arch_inportb(uint16_t _port) {
	uint8_t rv;
	asm volatile ("inb %1, %0" : "=a" (rv) : "dN" (_port));
	return rv;
}

void arch_outportb(uint16_t _port, uint8_t _data) {
	asm volatile ("outb %1, %0" : : "dN" (_port), "a" (_data));
}