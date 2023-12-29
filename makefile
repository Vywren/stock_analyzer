all: analyzer

analyzer: analyzer.o
	g++ -o analyzer analyzer.o
analyzer.co: analyzer.cpp
	g++ -c  analyzer.cpp
clean:
	rm analyzer.o analyzer