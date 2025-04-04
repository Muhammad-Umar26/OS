output: main.o LetterCount.o WordCount.o LineCount.o
		g++ main.o LetterCount.o WordCount.o LineCount.o -o output

main.o: main.cpp
		g++ -c main.cpp

LetterCount.o: LetterCount.cpp LetterCount.h
		g++ -c LetterCount.cpp

WordCount.o: WordCount.cpp WordCount.h
		g++ -c WordCount.cpp

LineCount.o: LineCount.cpp LineCount.h
		g++ -c LineCount.cpp

clean:
	rm *.o output