CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJS = main.o LCS.o

proj4 : ${OBJS}
		${CXX} $(CXXFLAGS) -o $@ ${OBJS}

 
main.o : LCS.hpp
LCS.o : LCS.hpp

clean :
		rm ${OBJS}