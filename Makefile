COMPILER_C=clang
COMPILER_FLAGS_C=-Wall -Wextra -pedantic -g -std=c11
COMPILER_CPP=clang++
COMPILER_FLAGS_CPP=-Wall -Wextra -pedantic -g -std=c++11
SRC_C=main.c rmathlib.c
SRC_CPP=main.cpp rmathlib.cpp
BIN=main.exe
DEBUGGER=gdb

all:
	$(COMPILER_C) $(COMPILER_FLAGS_C) $(SRC_C) -o $(BIN)

cpp:
	$(COMPILER_CPP) $(COMPILER_FLAGS_CPP) $(SRC_CPP) -o $(BIN)

run: 
	$(BIN)

debug: 
	$(DEBUGGER) $(BIN)

clean:
	del *.o *.exe