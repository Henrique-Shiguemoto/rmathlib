COMPILER=gcc
COMPILER_FLAGS=-Wall -Wextra -pedantic -g -std=c11
SRC=main.c
BIN=main.exe
DEBUGGER=gdb

all:
	$(COMPILER) $(COMPILER_FLAGS) $(SRC) -o $(BIN)

run: all
	$(BIN)

debug: all
	$(DEBUGGER) $(BIN)

clean:
	del *.o *.exe