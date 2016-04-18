nasm -f elf32 ../asm/kernel.asm -o kasm.o
gcc -m32 -fno-builtin -fno-stack-protector -c ../src/kernel.c -o kmain.o
gcc -m32 -fno-builtin -fno-stack-protector -c ../src/screen.c -o screen.o
gcc -m32 -fno-builtin -fno-stack-protector -c ../src/interupt_handler.c -o int_handler.o
gcc -m32 -fno-builtin -fno-stack-protector -c ../src/keyboard_handler.c -o key_handler.o
gcc -m32 -fno-builtin -fno-stack-protector -c ../src/input.c -o input.o
ld -m elf_i386 -T link.ld -o kernel kasm.o screen.o int_handler.o key_handler.o input.o kmain.o
rm -f *.o

