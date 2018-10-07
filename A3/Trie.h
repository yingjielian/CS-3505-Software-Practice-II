// CS-3505 A3: A Trie and the Rule-of-Three
// @version 9.24.2018
// @author Yingjie Lian

// Include unique include gaurds so the .h files won't be confused with others.
#ifndef A3_TRIE_H
#define A3_TRIE_H

// Incldue all desired libraries.
using namespace std;

#include <iostream>
#include <vector>
#include "Node.h"

// This class serves as the heart of the Binary Trie implementaion.
class Trie{

    // Declare the desired varaibles and methods for the class.
public:
    Node* rootNode;
    Trie();
    Trie(const Trie&);
    ~Trie();
    Trie& operator=(Trie);
    void addWord(string);
    bool isWord(string);
    std::vector<string> allWordsStartingWithPrefix(string);

};

#endif
