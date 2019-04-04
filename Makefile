CXXFLAGS= -Wall -O0 -g


executable: String.o main.o
	g++ -o executable String.o main.o

main.o: main.cpp String.h
	g++ -o main.o -c ${CXXFLAGS} main.cpp

String.o: String.cpp String.h
	g++ -o String.o -c ${CXXFLAGS} String.cpp
 

clean:
	rm main.o String.o executable
leak:
	valgrind --leak-check=full ./executable
