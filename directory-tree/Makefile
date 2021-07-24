all: run 

treedir: main.c tree.c tree.h linked_list.c linked_list.h stack.c stack.h queue.c queue.h
	gcc -g main.c tree.c linked_list.c stack.c queue.c -o treedir 

run: treedir 
	./treedir

clean:
	rm treedir 

check:
	valgrind --leak-check=full treedir
