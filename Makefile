W=-pedantic -W -Wall -Wconversion -Wextra -Wfatal-errors -Wwrite-strings -Wno-unused-variable -Wno-unused-parameter

all: bindrop

bindrop: bindrop.cpp
	g++ $W -O3 $< -std=c++14 -o $@

clean:
	rm -f bindrop
