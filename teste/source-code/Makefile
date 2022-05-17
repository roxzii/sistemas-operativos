.PHONY: clean all execute

CC=cc

all: execute

execute : main.o soma.o main .exe ./main.exe clean

main.exe : main.o soma.o
	$(CC) -o main.exe main.o soma.o
    
soma.o : soma.c
	$(CC) -c soma.c

main.o : main.c soma.h
	$(CC) -c main.c

clean :
	rm *.o

