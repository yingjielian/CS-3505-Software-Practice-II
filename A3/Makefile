# CS-3505 A3: A Trie and the Rule-of-Three
# @version 9.24.2018
# @author Yingjie Lian
# Makefile

# Compiler Flags
CC=g++
CFLAGS=-Wall -std=c++11

# Create the executable file
TrieTest: Trie.o Node.o TrieTest.cpp
	$(CC) $(CFLAGS) TrieTest.cpp Trie.o Node.o -o TrieTest

# Generate the Node.o file
Node.o: Node.h Node.cpp
	$(CC) $(CFLAGS) -c -I. Node.cpp

# Generate the Trie.o file
Trie.o: Trie.h Trie.cpp
	$(CC) $(CFLAGS) -c -I. Trie.cpp

# Remove the .o and executable files
clean:
	rm *.o
	rm TrieTest
