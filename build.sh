nasm -f elf32 kernel.asm -o kasm.o
gcc -m32 -fno-builtin -c kernel.c -o kmain.o
gcc -m32 -fno-builtin -c screen.c -o screen.o
ld -m elf_i386 -T link.ld -o build/kernel kasm.o screen.o kmain.o
rm -f *.o

