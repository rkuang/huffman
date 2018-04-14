CPP = g++
FLAGS = 

frequencies: frequencies.cpp
	$(CPP) $(FLAGS) -o $@ $^
