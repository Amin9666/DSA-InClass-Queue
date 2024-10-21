prog1:queue.o
	gcc -o prog2 queue.o
main.o:queue.c
	gcc -c queue.c

clean:
	rm *.o prog2