blockqueueTest : main.o
	g++ main.o -o blockqueueTest -lpthread

main.o : main.cpp BlockQueue.h
	g++ -c main.cpp -o main.o

clean :
	rm blockqueueTest main.o
