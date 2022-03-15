main: main.o mthlib.o
	gcc -o main main.c mthlib.c

main.o: main.c
	gcc -c main.c

mthlib.o: mthlib.c mthlib.h
	gcc -c mthlib.c

clean:
	rm *.o main