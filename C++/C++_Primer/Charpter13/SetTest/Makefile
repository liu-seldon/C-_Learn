SetTest:set_test.o fruit.o
	g++ -o SetTest set_test.o fruit.o
set_test.o:set_test.cpp fruit.h
	g++ -c set_test.cpp -o set_test.o
fruit.o:fruit.h fruit.cpp
	g++ -c fruit.cpp -o fruit.o
clean:
	rm fruit.o set_test.o SetTest
