#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <limine.h>
#include <kernel/kprintf.h>

LIMINE_BASE_REVISION(1)

void _start(void) {
    if (LIMINE_BASE_REVISION_SUPPORTED == false) {
        arch_hang();
    }

	printf_init();
	kprintf("This build has been compiled on %s at %s\n", __DATE__, __TIME__);

    arch_hang();
}
