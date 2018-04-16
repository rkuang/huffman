CPP = g++
FLAGS =

all: frequencies huffman encode decode

frequencies: frequencies.cpp
	$(CPP) $(FLAGS) -o $@ $^

huffman.o: huffman.cpp huffman.h
	$(CPP) $(FLAGS) -c -o $@ $<

huffman: huffman.o
	$(CPP) $(FLAGS) -o $@ $^

encode: encode.cpp
	$(CPP) $(FLAGS) -o $@ $^

decode: decode.cpp
	$(CPP) $(FLAGS) -o $@ $^

clean:
	rm -f *.o frequencies huffman encode decode

.PHONY: clean
