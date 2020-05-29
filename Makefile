#
# the worst idea for a sorting algorithm
#


CXX = g++
CFLAGS = -ggdb -Wall
LDFLAGS = -lpthread



badsort: badsort.o
	$(CXX) $(CFLAGS) -o $@ $^ $(LDFLAGS)

#g++ -Wall -ggdb test.cpp -o test -lboost_regex -lpcre2
