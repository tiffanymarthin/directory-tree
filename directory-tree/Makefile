all: run 

treedir: main.c tree2.c tree.h linked_list.c linked_list.h stack.c stack.h queue.c queue.h files.h files.c
	gcc -g main.c files.c tree2.c linked_list.c stack.c queue.c -o treedir 

run: treedir 
	./treedir

clean:
	rm treedir 

check:
	valgrind --leak-check=full treedir
