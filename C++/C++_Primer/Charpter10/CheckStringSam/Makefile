checkSam:checkSam.o util.o
	g++ -o checkSam checkSam.o util.o

util.o:util.cpp
	g++ -c util.cpp -o util.o

checkSam.o:check_string_sam.cpp
	g++ -c check_string_sam.cpp -o checkSam.o
clean:
	rm checkSam.o util.o checkSam 
