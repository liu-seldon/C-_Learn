InheritStaticTest:inherit_static_test.o
	g++ -o InheritStaticTest inherit_static_test.o 

inherit_static_test.o : inherit_static_test.cpp Base.h Derived.h
	g++ -c inherit_static_test.cpp -o inherit_static_test.o

clean:
	rm inherit_static_test.o InheritStaticTest
