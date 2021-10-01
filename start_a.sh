nasm -f elf64 ./2/hello.s
ld ./2/hello.o
./a.out
echo "Exit code:"$?
rm ./2/hello.o a.out
