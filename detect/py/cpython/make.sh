gcc -c -fPIC test_syscall.c
gcc -shared test_syscall.o -o test_syscall.so 
