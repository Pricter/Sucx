#include <kernel/arch/misc.h>
#include <kernel/arch/seriallog.h>
#include <vendor/printf.h>

#define COM1 0x3F8

void arch_serial_log_init(void) {
	/* Enable DLAB (Divisor Latch Access Bit) */
	arch_outportb(COM1 + 3, 0x80);

	/* Set divisor low byte (115200 baud) */
	arch_outportb(COM1 + 0, 0x03);

	/* Set divisor high byte */
	arch_outportb(COM1 + 1, 0x00);

	/* Set parity */
	arch_outportb(COM1 + 3, 0x03);

	/* Enable FIFO, clear transmit and receive FIFO queues */
    arch_outportb(COM1 + 2, 0xC7);

	/* Clear them */
    arch_outportb(COM1 + 4, 0x0B);

	/* Enable interrupts */
	arch_outportb(COM1 + 1, 0x01);
}

void arch_serial_out_char(uint8_t ch) {
	arch_outportb(COM1, ch);
}