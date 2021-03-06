SOURCE = solution.c list.c tree.c
OBJECTS = solution.o list.o tree.o
DE_OBJECTS = de_solution.o de_list.o de_tree.o
DEPS = list.h tree.h

solution: $(OBJECTS) 
	gcc -o solution $(OBJECTS) 


de_%.o: %.c $(DEPS)
	gcc -std=c99 -g -c -o $@ $< $(CFLAGS)

%.o: %.c $(DEPS)
	gcc -std=c99 -c -o $@ $< $(CFLAGS)

debug: $(DE_OBJECTS) 
	gcc -o solution.dbg $(DE_OBJECTS)

.PHONY: clean

clean: 
	-rm -f *.o solution solution.dbg

