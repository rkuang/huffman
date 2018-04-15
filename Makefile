CPP = g++
FLAGS =

frequencies: frequencies.cpp
	$(CPP) $(FLAGS) -o $@ $^

huffman.o: huffman.cpp huffman.h
	$(CPP) $(FLAGS) -c -o $@ $<

huffman: huffman.o
	$(CPP) $(FLAGS) -o $@ $^
