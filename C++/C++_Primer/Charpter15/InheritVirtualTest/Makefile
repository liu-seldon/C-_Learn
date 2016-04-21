InheritVirtual:inherit_virtual_test.o Base.o Derived.o
	g++ -o InheritVirtual inherit_virtual_test.o Base.o Derived.o

inherit_virtual_test.o:inherit_virtual_test.cpp Base.h Derived.h
	g++ -c inherit_virtual_test.cpp -o inherit_virtual_test.o 
Base.o:Base.cpp Base.h
	g++ -c Base.cpp -o Base.o
Derived.o: Derived.cpp Base.h Derived.h
	g++  -c Derived.cpp -o Derived.o
clean:
	rm inherit_virtual_test.o Base.o Derived.o InheritVirtual
