CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

gobang: mp2.o ai.o
	$(CXX) $(CXXFLAGS) -o gobang main.o NBC.o

mp2.o: mp2.cpp ai.h
	$(CXX) $(CXXFLAGS) -c main.cpp

ai.o: ai.cpp ai.h
	$(CXX) $(CXXFLAGS) -c ai.cpp


clean:
	rm -f *.o
