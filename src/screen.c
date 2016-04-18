#include "../include/screen.h"
int cursorpos = 0;
int enter = 0;
void putc(unsigned char character, unsigned int color) {
	char *vidptr = (char*)0xb8000;
	
	vidptr[cursorpos] = character;
	vidptr[cursorpos+1] = color;
	cursorpos = cursorpos + 2;
	scroll();

}

void noscroll_putc(unsigned char character, unsigned int color) {
	char *vidptr = (char*)0xb8000;
	
	vidptr[cursorpos] = character;
	vidptr[cursorpos+1] = color;
	cursorpos = cursorpos + 2;
}

void puts(char *string, unsigned int color) {
	int i = 0;
	while(string[i] != '\0') {
		if(string[i] == '\n') {
			enter = 1;
			newline();
		} else {
			putc(string[i], color);
		}
		++i;
		scroll();
	}
}
void newline() {
	int line = (cursorpos / 159) + 1;
	cursorpos = (line * 160);
	update_cursor(cursorpos);
}

void clear(unsigned int color) {
	char *vidptr = (char*)0xb8000;
	unsigned int j = 0;
	while(j < 80 * 25 * 2) {
		vidptr[j] = ' ';
		vidptr[j+1] = color;
		j = j + 2;
	}
	cursorpos = 0;
	update_cursor(cursorpos);
}

void scroll() {
	if(cursorpos > (160 * 25)-1) {
		char *vidptr = (char*)0xb8000;
		for(int i=1; i<25; i++) {
			cursorpos = (i - 1) * 160;
			for(int t = 0; t<159; t = t+2) {
				noscroll_putc(vidptr[cursorpos+160], vidptr[cursorpos+1]);
				
			}
		}
	}
	update_cursor(cursorpos);
}

void backspace(unsigned int color) {
	char *vidptr = (char*)0xb8000;
	if((cursorpos/160) * 160 == cursorpos) {	
		while(vidptr[cursorpos-2] == ' ') {
			cursorpos = cursorpos - 2;
			
		}
		putc(' ', color);
	}
	vidptr[cursorpos-1] = color;
	vidptr[cursorpos-2] = ' ';
	cursorpos = cursorpos - 2;
	update_cursor(cursorpos);
}

void update_cursor(unsigned short cursor) {
	cursor = cursor / 2;	
	outb(0x3D4, 14);
	outb(0x3D5, (cursor >> 8) & 0x00ff);
	outb(0x3D4, 15);
	outb(0x3D5, cursor & 0x00ff);
}










