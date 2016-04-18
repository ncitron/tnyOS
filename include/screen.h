#ifndef SCREEN_H
#define SCREEN_H
void putc(unsigned char character, unsigned int color);
void noscroll_putc(unsigned char character, unsigned int color);
void puts(char *string, unsigned int color);
void newline();
void clear(unsigned int color);
void scroll();
void backspace(unsigned int color);
void update_cursor(unsigned short cursor);
#endif
