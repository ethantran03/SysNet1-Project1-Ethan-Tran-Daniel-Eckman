CXX = g++
CXXFLAGS = -Wall -g

all: myshell

myshell: myshell.o parse.o param.o
	$(CXX) $(CXXFLAGS) -o myshell myshell.o parse.o param.o

myshell.o: myshell.cpp parse.hpp param.hpp
parse.o: parse.cpp parse.hpp param.hpp
param.o: param.cpp param.hpp

clean:
	rm -f *.o myshell
