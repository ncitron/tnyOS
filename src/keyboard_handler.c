#include "../include/screen.h"

extern unsigned char keyboard_map[128];

void keyboard_handler_main(void) {
	unsigned char status;
	char keycode;
	outb(0x20, 0x20);	//EOI

	status = inb(0x64);

	if (status & 0x01) {
		keycode = inb(0x60);
		if(keycode<0) {
			return;
		} else if(keycode == 0x1c) {
			puts("\n", 0xf0);
		}else if(keycode == 0x0e) {
		backspace(0xf0);
		}else {
			putc(keyboard_map[(unsigned char) keycode], 0xf0);
		}
	}
}

