INCLUDE := -I.
SRC = test_header.cpp \
			analyzer.cpp
#all:  test_header

#test_header.o: test_header.cpp analyzer.h
#	g++ -Wall -g -c test_header.cpp analyzer.h

test_header: 
	g++ -Wall -o test_header $(INCLUDE) $(SRC) 

#analyzer.o: analyzer.cpp
#	g++ -Wall -g -c analyzer.cpp

#analyzer: analyzer.o
#	g++ -Wall -g -o analyzer analyzer.o

clean:
	del analyzer.o analyzer.exe test_header.exe test_header.o