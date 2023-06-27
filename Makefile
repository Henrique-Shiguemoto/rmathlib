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
	$(CC) $(FLAGS) -o test7 $(TEST_DIR)/trig_test.c mthlib.c
	$(CC) $(FLAGS) -o test8 $(TEST_DIR)/convenient_functions_test.c mthlib.c
	$(CC) $(FLAGS) -o test9 $(TEST_DIR)/random_test.c mthlib.c
	$(CC) $(FLAGS) -o test10 $(TEST_DIR)/graphics2D_test.c mthlib.c
	$(CC) $(FLAGS) -o test11 $(TEST_DIR)/graphics3D_test.c mthlib.c
	$(CC) $(FLAGS) -o test12 $(TEST_DIR)/distances_test.c mthlib.c
	$(CC) $(FLAGS) -o test13 $(TEST_DIR)/lines_relative_positions_test.c mthlib.c
	$(CC) $(FLAGS) -o test14 $(TEST_DIR)/distances_test.c mthlib.c
	$(CC) $(FLAGS) -o test15 $(TEST_DIR)/collisions_test.c mthlib.c
	$(CC) $(FLAGS) -o test16 $(TEST_DIR)/area_volume_perimeter_test.c mthlib.c
	test0
	test1
	test2
	test3
	test4
	test5
	test6
	test7
	test8
	test9
	test10
	test11
	test12
	test13
	test14
	test15
	test16

clean:
	del *.exe