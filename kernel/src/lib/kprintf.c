#include <vendor/printf.h>
#include <vendor/flanterm.h>
#include <vendor/fb.h>
#include <kernel/requests.h>
#include <kernel/arch/seriallog.h>
#include <kernel/arch/misc.h>
#include <kernel/kprintf.h>
#include <limine.h>

struct limine_framebuffer* framebuffer = NULL;
struct flanterm_context* context = NULL;

void printf_init(void) {
	arch_serial_log_init();

	framebuffer = request_framebuffer.response->framebuffers[0];
	if(framebuffer == NULL) {
		arch_hang_cli();
	}

	uint32_t default_bg_black = 0x000000;
	uint32_t default_fg_yellow = 0xffff00;

	context = flanterm_fb_init(
		NULL, NULL,
		framebuffer->address, framebuffer->width, framebuffer->height,
		framebuffer->pitch, NULL, NULL, NULL, &default_bg_black, &default_fg_yellow, NULL, NULL, NULL, 8, 16, 1, 1, 1, 0);
	context->cursor_enabled = false;
}

void kprintf(const char* fmt, ...) {
	char buffer[1024];

	va_list args;
	va_start(args, fmt);

	int length = vsnprintf(buffer, 1024, fmt, args);
	va_end(args);
	flanterm_write(context, buffer, length);

	for(int i = 0; i <= length; i++) {
		arch_serial_out_char(buffer[i]);
	}
}

void _putchar(char ch) {
	kprintf(ch);
}