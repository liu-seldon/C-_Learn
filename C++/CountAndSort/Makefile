CountAndSort:count_and_sort.o
	g++ -o CountAndSort count_and_sort.o

count_and_sort.o:InputData.h sort_and_count.cpp
	g++ -c sort_and_count.cpp -o count_and_sort.o

clean:
	rm count_and_sort.o  CountAndSort
