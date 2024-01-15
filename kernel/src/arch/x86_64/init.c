#include <stdint.h>
#include <stddef.h>
#include <kernel/kprintf.h>

extern void gdt_init(void);

void arch_init(void) {
	gdt_init();
	kprintf("Architecture specific systems initialized\n");
}