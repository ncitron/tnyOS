#include "../include/input.h"
#include "../include/screen.h"
extern int cursorpos;
extern int enter;

unsigned char getc() {
	char *vidptr = (char*)0xb8000;
	enter = 0;

	unsigned char character;
	int temp_cursor = cursorpos;
	while(enter == 0);

	if(vidptr[temp_cursor+2] != ' ') {
		return 0;
	}
	character = vidptr[temp_cursor];
	return character;
}

unsigned char *gets() {
	char *vidptr = (char*)0xb8000;
	enter = 0;
	char *str;
	int i = 0;

	int line_start = cursorpos;
	while(enter == 0);
	backspace(0xf0);
	int line_end = cursorpos;
	cursorpos = line_start;

	while(line_end > cursorpos) {
		str[i] = vidptr[cursorpos];
		++i;
		cursorpos += 2;
	}
	newline();
	return str;
}
