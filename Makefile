CC=gcc
BIN=main
DEBUGGER=gdb
FLAGS=-Wall -Wextra -g
TEST_DIR=samples

main: main.c mthlib.c
	$(CC) $(FLAGS) -o $(BIN) main.c mthlib.c

run: $(BIN)
	$(BIN)

debug: $(BIN)
	$(DEBUGGER) $(BIN)

test: 
	$(CC) $(FLAGS) -o test0 $(TEST_DIR)/GetPlatformTime_test.c mthlib.c
	$(CC) $(FLAGS) -o test1 $(TEST_DIR)/V2_test.c mthlib.c

clean:
	del *.exe