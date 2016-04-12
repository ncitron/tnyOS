#include "screen.h"
void kmain(void) {
	int color = 0xf0;
	clear(color);	//clear before outputting text

	puts("You can't see me", color);
	clear(color);
	puts("Welcome to tnyOS\n", color);	// print \n or call newline() for newline
	puts("I wrote an operating system\n", color);
	putc('A', color);
	putc('b', color);
	putc('c', color);
	newline();
	putc('1', color);
	putc('2', color);
	putc('3', color);
}
