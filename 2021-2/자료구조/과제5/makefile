tree:tree.o tree_main.o
	gcc -o tree tree.o tree_main.o
tree.o: tree.o tree.h
	gcc -c tree.c -o tree.o
tree_main.o: tree_main.c
	gcc -c tree_main.c -o tree_main.o
clean:
	rm -f  tree*o

