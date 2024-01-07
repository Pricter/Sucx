#include <limine.h>
#include <kernel/requests.h>

volatile struct limine_framebuffer_request request_framebuffer = {
    .id = LIMINE_FRAMEBUFFER_REQUEST,
    .revision = 0
};

volatile struct limine_hhdm_request request_hhdm = {
    .id = LIMINE_HHDM_REQUEST,
    .revision = 0
};

volatile struct limine_kernel_address_request request_kernel_addr = {
    .id = LIMINE_KERNEL_ADDRESS_REQUEST,
    .revision = 0
};

volatile struct limine_memmap_request request_memmap = {
    .id = LIMINE_MEMMAP_REQUEST,
    .revision = 0
};

volatile struct limine_rsdp_request request_rsdp = {
    .id = LIMINE_RSDP_REQUEST,
    .revision = 0
};

volatile struct limine_smp_request request_smp = {
    .id = LIMINE_SMP_REQUEST,
    .revision = 0
};