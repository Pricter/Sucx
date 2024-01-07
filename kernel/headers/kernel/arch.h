#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

void arch_init(void);

void arch_hang(void);
void arch_hang_cli(void);

uint8_t arch_inportb(uint16_t _port);
void arch_outportb(uint16_t _port, uint8_t _data);

void arch_serial_init(void);
void arch_serial_log(const char* fmt, ...);