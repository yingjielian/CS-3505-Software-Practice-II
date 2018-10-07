// CS-3505 A4: Testing and Travis
// @version 10.05.2018
// @author Yingjie Lian & Tim Vanausdal

#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <vector>

#include "Node.h"

extern int refCount;

using namespace std;

class Trie
{
public:
    Node* currentNode;

    // The empty constructor for the Trie.
    Trie();
    // The constructor that takes in the root node to copy.
    Trie(const Trie&);
    // This is the deconstructor for the object.
    ~Trie();
    // This will override the = operator.
    Trie operator=(const Trie&);

    // This will add a word to the Trie.
    void addAWord(string);
    // This will check if the argument entered is contained within the Trie.
    bool isAWord(string);
    // This will get the words containing the prefix given.
    vector<string> allWordsStartingWithPrefix(string);
    // This will return empty vector
    vector<string> wordsWithWildcardPrefix(string);
};

#endif
