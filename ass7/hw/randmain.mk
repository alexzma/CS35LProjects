OPTIMIZE = -O2

CC = gcc
FLAGS = -ldl -Wl,-rpath=$(PWD)
CFLAGS = $(OPTIMIZE) -g3 -Wall -Wextra -march=native -mtune=native -mrdrnd

default: randall randmain randlibhw.so randlibsw.so

randmain: randmain.c randcpuid.c
	$(CC) $(CFLAGS) -c randcpuid.c -o randcpuid.o
	$(CC) $(CFLAGS) -c randmain.c -o randmain.o
	$(CC) $(CFLAGS) randmain.o randcpuid.o $(FLAGS) -o $@

randlibhw.so: randlibhw.c
	$(CC) $(CFLAGS) -c -fPIC randlibhw.c -o randlibhw.o
	$(CC) $(CFLAGS) -shared randlibhw.o -o $@

randlibsw.so: randlibsw.c
	$(CC) $(CFLAGS) -c -fPIC randlibsw.c -o randlibsw.o
	$(CC) $(CFLAGS) -shared randlibsw.o -o $@
