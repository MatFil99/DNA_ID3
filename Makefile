prog: main.o tree.o data.o entropy.o test_data.o test.o
	g++ -o prog main.o tree.o data.o entropy.o test_data.o test.o

main.o:
	g++ -c main.cpp

tree.o:
	g++ -c tree.cpp tree.h

entropy.o:
	g++ -c entropy.cpp entropy.h data.h

data.o:
	g++ -c data.cpp data.h

test_data.o:
	g++ -c test_data.cpp test_data.h

test.o:
	g++ -c test.cpp test.h

clear:
	rm -f *.o *.gch prog