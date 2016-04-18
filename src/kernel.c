#include "../include/screen.h"
#include "../include/interupt_handler.h"
#include "../include/input.h"
extern cursorpos;
void kmain(void) {
	int color = 0xf0;
	clear(color);
	idt_init();
	kb_init();

	puts("Welcome to tnyOS\n", color);
	char *string = gets();
	puts(string, color);
	while(1);
}
