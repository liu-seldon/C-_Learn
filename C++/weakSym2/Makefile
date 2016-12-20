all: a.c b.c
	gcc a.c b.c -o a.out

a: a.c
	gcc a.c -o a.o

b: b.c
	gcc b.c -o b.o

ab: a b
	gcc a.o b.o -o a.out

clean:
	rm a.o b.o a.out
