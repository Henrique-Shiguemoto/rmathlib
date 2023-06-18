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
	$(CC) $(FLAGS) -o test2 $(TEST_DIR)/V3_test.c mthlib.c
	$(CC) $(FLAGS) -o test3 $(TEST_DIR)/V4_test.c mthlib.c
	$(CC) $(FLAGS) -o test4 $(TEST_DIR)/mat2x2_test.c mthlib.c
	$(CC) $(FLAGS) -o test5 $(TEST_DIR)/mat3x3_test.c mthlib.c
	$(CC) $(FLAGS) -o test6 $(TEST_DIR)/mat4x4_test.c mthlib.c
	test0
	test1
	test2
	test3
	test4
	test5
	test6

clean:
	del *.exe