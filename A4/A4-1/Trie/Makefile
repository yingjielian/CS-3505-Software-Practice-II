# @version 10.05.2018
# CS-3505 A4: Testing and Travis
#author Yingjie Lian & Tim Vanausdal

# Sets all of the variables.
CC=g++
CFLAGS=-Wall -std=c++11

# This will create the executable
TrieTest: Trie.o Node.o TrieTest.cpp
	$(CC) $(CFLAGS) TrieTest.cpp Trie.o Node.o -o TrieTest

# This will create Node.o
Node.o: Node.cpp Node.h
	$(CC) -c $(CFLAGS) -I. Node.cpp

# This will create Trie.o
Trie.o: Trie.h Trie.cpp
	$(CC) -c $(CFLAGS) -I. Trie.cpp

# Will remove the executable and .o files when you call clean.
clean:
	rm *.o
	rm TrieTest
