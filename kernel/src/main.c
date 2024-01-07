#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <limine.h>
#include <kernel/requests.h>
#include <kernel/arch.h>

LIMINE_BASE_REVISION(1)

void _start(void) {
    if (LIMINE_BASE_REVISION_SUPPORTED == false) {
        arch_hang();
    }

	arch_init();

    arch_hang();
}
