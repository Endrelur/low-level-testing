nasm -f elf64 ./2/hello.s
ld ./2/hello.o
#run assembly and redirect stderr output to out.txt
./a.out 2>out.txt
#write exitcode to out.txt
echo "Exit code:"$? >>out.txt
rm ./2/hello.o a.out
