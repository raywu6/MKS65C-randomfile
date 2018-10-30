all: 
	gcc main.c

run: all
	./a.out

clean:
	rm -f *~ *.gch* a.out *.o *#*
