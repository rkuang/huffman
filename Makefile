CPP = g++
FLAGS = -g

frequencies: frequencies.cpp
	$(CPP) $(FLAGS) -o $@ $^
