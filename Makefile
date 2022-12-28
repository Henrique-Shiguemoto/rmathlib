CC=gcc
BIN=main
FLAGS=-Wall -Wextra -g

main: main.o mthlib.o
	$(CC) $(FLAGS) -o $(BIN) main.c mthlib.c

main.o: main.c
	$(CC) -c main.c

mthlib.o: mthlib.c mthlib.h
	$(CC) -c mthlib.c

run: $(BIN)
	$(BIN)

test: test.o
	g++ -o test test.o

test.o: test.cpp
	g++ -c test.cpp

clean:
	del *.o *.exe