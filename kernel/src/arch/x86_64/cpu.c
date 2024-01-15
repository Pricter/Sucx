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

static inline uint64_t read_cr0(void) {
    uint64_t cr0_value;
    asm volatile("mov %%cr0, %0" : "=r" (cr0_value));
    return cr0_value;
}

static inline uint64_t read_cr2(void) {
    uint64_t cr2_value;
    asm volatile("mov %%cr2, %0" : "=r" (cr2_value));
    return cr2_value;
}

static inline uint64_t read_cr3(void) {
    uint64_t cr3_value;
    asm volatile("mov %%cr3, %0" : "=r" (cr3_value));
    return cr3_value;
}

static inline uint64_t read_cr4(void) {
    uint64_t cr4_value;
    asm volatile("mov %%cr4, %0" : "=r" (cr4_value));
    return cr4_value;
}

static inline uint64_t rdmsr(uint32_t msr) {
	uint32_t edx = 0, eax = 0;
	asm volatile (
		"rdmsr\n\t"
		: "=a" (eax), "=d" (edx)
		: "c" (msr)
		: "memory"
	);
	return ((uint64_t)edx << 32) | eax;
}

static inline void wrmsr(uint32_t msr, uint64_t value) {
	uint32_t low = value & 0xFFFFFFFF;
	uint32_t high = (value >> 32) & 0xFFFFFFFF;

	asm volatile ("wrmsr" : : "c" (msr), "a" (low), "d" (high));
}

static inline bool interrupt_state(void) {
    uint64_t flags;
    asm volatile ("pushfq; pop %0" : "=rm"(flags) :: "memory");
    return flags & (1 << 9);
}

static inline void enable_interrupts(void) {
    asm ("sti");
}

static inline void disable_interrupts(void) {
    asm ("cli");
}