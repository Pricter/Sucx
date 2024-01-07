#include <kernel/arch.h>
#include <vendor/printf.h>

void arch_init(void) {
	arch_serial_init();
	printf("Architecture-specific systems initialized\n");
}