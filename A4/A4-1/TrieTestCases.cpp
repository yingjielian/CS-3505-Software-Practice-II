// CS-3505 A4: Testing and Travis
// @version 10.05.2018
// @author Yingjie Lian & Tim Vanausdal

#include "gtest/gtest.h"
#include "Trie/Trie.h"
#include <vector>

int refCount = 0;

// Checks if adding one word to the Trie works and if the correct number of nodes are
// generated. We add the word “hiya” to the Trie and it was added correctly along with correctly counting
// 5 nodes in total. One for the root node, and 4 for the 4 letters in “hiya”.
TEST(TrieTestCases, TestAdd1Word) {
    Trie* t1 = new Trie();
    string testWrd("hiya");
    t1->addAWord(testWrd);

    ASSERT_EQ(5, refCount);

    bool word = t1->isAWord(testWrd);
    ASSERT_TRUE(word);
    delete t1;

    ASSERT_EQ(0, refCount);
}

// Does the same thing as the previous test except that it adds two words to the Trie.
// We add two words that don’t have anything in common so that they won’t share any of the same nodes.
// We test to see if both words were added, that the correct number of nodes were added (which with the
// words computer and science) for a total of 16, and then ensuring the Trie and its Nodes have been
// deleted.
TEST(TrieTestCases, TestAdd2Words){
    Trie* t2 = new Trie();

    string testWrd1("computer");

    string testWrd2("science");
    t2->addAWord(testWrd1);

    ASSERT_EQ(9, refCount);

    t2->addAWord(testWrd2);

    ASSERT_EQ(16, refCount);

    bool word1 = t2->isAWord(testWrd1);
    bool word2 = t2->isAWord(testWrd2);
    ASSERT_TRUE(word1);
    ASSERT_TRUE(word2);
    delete t2;

    ASSERT_EQ(0, refCount);
}

// Does the same thing as the past two tests except that it adds two words that would
// share many of the same nodes. This test was to ensure that that the refCount doesn’t over count the
// needed number of nodes.
TEST(TrieTestCases, TestAdd2Similiar){
    Trie* t3 = new Trie();
    string testWrd1("compute");
    string testWrd2("computer");
    t3->addAWord(testWrd1);

    ASSERT_EQ(8, refCount);

    t3->addAWord(testWrd2);

    ASSERT_EQ(9, refCount);

    bool word1 = t3->isAWord(testWrd1);
    bool word2 = t3->isAWord(testWrd2);
    ASSERT_TRUE(word1);
    ASSERT_TRUE(word2);
    delete t3;

    ASSERT_EQ(0, refCount);
}

// Does the same thing as the past three tests except that it adds three words that
// would share many of the same nodes. This test was to ensure that the refCount doesn’t over count the
// needed number of nodes.
TEST(TrieTestCases, TestAdd3Similiar){
    Trie* t4 = new Trie();
    string testWrd1("compute");
    string testWrd2("computer");
    string testWrd3("computing");
    t4->addAWord(testWrd1);

    ASSERT_EQ(8, refCount);
    t4->addAWord(testWrd2);

    ASSERT_EQ(9, refCount);
    t4->addAWord(testWrd3);

    ASSERT_EQ(12, refCount);
    bool word1 = t4->isAWord(testWrd1);
    bool word2 = t4->isAWord(testWrd2);
    bool word3 = t4->isAWord(testWrd3);
    ASSERT_TRUE(word1);
    ASSERT_TRUE(word2);
    ASSERT_TRUE(word3);
    delete t4;

    ASSERT_EQ(0, refCount);
}

// This test checks if the copy constructor works. That if we create one Trie
// object and try to create a new Trie object by copying the original one into a new one that the values and
// not the pointers are copied over. This test specifically tries to copy a Trie with only one word in it. And to
// also ensure that when we delete the two objects no issues occur.
TEST(TrieTestCases, TestTrieCopyConstructor1){
    Trie* t5 = new Trie();
    string testWrd1("computing");
    t5->addAWord(testWrd1);

    ASSERT_EQ(10, refCount);

    Trie* u5 = new Trie(*t5);

    ASSERT_TRUE(u5->isAWord(testWrd1));

    delete t5;
    delete u5;

    ASSERT_EQ(0, refCount);
}

// This test is similar to the above test except that we copy a Trie object that
// contains three values. We also test and ensure that when more words are added to the two different
// Trie objects they aren’t pointers to each other and the word is only added to the respective Trie object.
TEST(TrieTestCases, TestTrieCopyConstructor2){
    Trie* t6 = new Trie();
    string testWrd1("computing");
    string testWrd2("utah");
    t6->addAWord(testWrd1);

    ASSERT_EQ(10, refCount);
    t6->addAWord(testWrd2);

    ASSERT_EQ(14, refCount);
    Trie* u6 = new Trie(*t6);
    ASSERT_TRUE(u6->isAWord(testWrd1));
    ASSERT_TRUE(u6->isAWord(testWrd2));

    u6->addAWord("pickles");

    ASSERT_FALSE(t6->isAWord("pickles"));
    ASSERT_TRUE(u6->isAWord("pickles"));

    delete t6;
    delete u6;

    ASSERT_EQ(0, refCount);
}

// This test sees that when a Trie object that contains three words that have all the
// same prefixes and if the user tries to find a word that contains the prefix that is not in the Trie that the
// method will return the correct list of words beginning with that prefix. Which in this test would be three
// words.
TEST(TrieTestCases, TestTriePrefixFinder1){
    Trie* t7 = new Trie();

    string testWrd1("compute");
    string testWrd2("computing");
    string testWrd3("computer");

    t7->addAWord(testWrd1);
    t7->addAWord(testWrd2);
    t7->addAWord(testWrd3);

    ASSERT_EQ(12, refCount);

    vector<string> testWords;

    testWords.push_back("compute");
    testWords.push_back("computer");
    testWords.push_back("computing");

    vector<string> returnedWords = t7->allWordsStartingWithPrefix("comp");

    ASSERT_TRUE(testWords == returnedWords);

    delete t7;

    ASSERT_EQ(0, refCount);

}

// This test first add three words and then delete t8 which is the Trie pointer.
// So it tested the destructor and addAWord
TEST(TrieTestCases, TestTriePrefixFinder2){
    Trie* t8 = new Trie();

    string testWrd1("compute");
    string testWrd2("computing");
    string testWrd3("computer");

    t8->addAWord(testWrd1);
    t8->addAWord(testWrd2);
    t8->addAWord(testWrd3);

    ASSERT_EQ(12, refCount);

    vector<string> testWords;

    testWords.push_back("compute");
    testWords.push_back("computing");
    testWords.push_back("computer");

    vector<string> returnedWords = t8->allWordsStartingWithPrefix("hard");

    ASSERT_FALSE(testWords == returnedWords);

    ASSERT_EQ(0, returnedWords.size());

    delete t8;

    ASSERT_EQ(0, refCount);

}

// This test basically test out the equal operator in Trie class. Also the
// destructor.
TEST(TrieTestCases, TestTrieEqualOperator1){
    Trie* t9 = new Trie();

    string testWrd1("compute");
    string testWrd2("computing");
    string testWrd3("computer");

    t9->addAWord(testWrd1);
    t9->addAWord(testWrd2);
    t9->addAWord(testWrd3);

    ASSERT_EQ(12, refCount);

    Trie* u9 = new Trie();

    *u9 = *t9;

    ASSERT_TRUE(u9->isAWord(testWrd1));
    ASSERT_TRUE(u9->isAWord(testWrd2));
    ASSERT_TRUE(u9->isAWord(testWrd3));

    

    delete t9;
    delete u9;

    ASSERT_EQ(0, refCount);

}

// This test basically test out the equal operator in Trie class. Also the
// destructor.
TEST(TrieTestCases, TestTrieEqualOperator2){
    Trie* t10 = new Trie();

    string testWrd1("word");

    t10->addAWord(testWrd1);

    ASSERT_EQ(5, refCount);

    Trie* u10 = new Trie();

    *u10 = *t10;

    string testWrd2("hiya");

    ASSERT_TRUE(u10->isAWord(testWrd1));
    ASSERT_FALSE(u10->isAWord(testWrd2));

    delete t10;
    delete u10;

    ASSERT_EQ(0, refCount);

}

//tests constructor. If t is a nullptr fail.
TEST (TrieTest, ConstructTest1) {
  Trie t;
  Trie* tPoint = &t;
  if(tPoint)
    ASSERT_TRUE(true);
  else
    FAIL();
}
//test the addAWord and isAWord
TEST (TrieTest, isAWordTest1) {
  Trie t;
  t.addAWord("hello");
  ASSERT_TRUE(t.isAWord("hello"));
}
//tests that adding an empty string yields false
TEST (TrieTest, isAWordTest2) {
  Trie t;
  t.addAWord("hello");
  ASSERT_FALSE(t.isAWord(""));
}
//Add all 3 digit words to the Trie, makes sure that it adds
//all of them correctly.
TEST (TrieTest, UTest110) {
  Trie t;
  for(int posFirst = 0; posFirst<26; posFirst++){
    char first = posFirst+'a';
    for(int posSecond = 0; posSecond<26; posSecond++){
      char second = posSecond+'a';
      for(int posThird = 0; posThird<26; posThird++){
        char third = posThird+'a';
        std::string hello("");
        hello+=first;
        hello += second;
        hello += third;
        t.addAWord(hello);
        ASSERT_TRUE(t.isAWord(hello));
      }
    }
  }
}

//Add all 3 digit words to the Trie, makes sure that it adds
//all of them correctly. make sure that if you do the process
//again that it doesn't change the results.
TEST (TrieTest, TestAddDuplicate1) {
  Trie t;
  for(int posFirst = 0; posFirst<26; posFirst++){
    char first = posFirst+'a';
    for(int posSecond = 0; posSecond<26; posSecond++){
      char second = posSecond+'a';
      for(int posThird = 0; posThird<26; posThird++){
        char third = posThird+'a';
        std::string hello("");
        hello+=first;
        hello += second;
        hello += third;
        t.addAWord(hello);
        ASSERT_TRUE(t.isAWord(hello));
      }
    }
  }

  for(int posFirst = 0; posFirst<26; posFirst++){
    char first = posFirst+'a';
    for(int posSecond = 0; posSecond<26; posSecond++){
      char second = posSecond+'a';
      for(int posThird = 0; posThird<26; posThird++){
        char third = posThird+'a';
        std::string hello("");
        hello+=first;
        hello += second;
        hello += third;
        t.addAWord(hello);
        ASSERT_TRUE(t.isAWord(hello));
      }
    }
  }
}
//add all 2 digit words to a trie object,
//copy the trie object using the constructor,
//make sure that all of the results are in the new trie.
TEST (TrieTest, UTest111) {
  Trie t;
  //add all 2 digit words to t
  for(int posFirst = 0; posFirst<26; posFirst++){
    char first = posFirst+'a';
    for(int posSecond = 0; posSecond<26; posSecond++){
      char second = posSecond+'a';

        std::string hello("");
        hello+=first;
        hello += second;
        t.addAWord(hello);
    }
  }
//copy the Trie object t.
  Trie c(t);
//verify that all words from c were copied.
  for(int posFirst = 0; posFirst<26; posFirst++){
    char first = posFirst+'a';
    for(int posSecond = 0; posSecond<26; posSecond++){
      char second = posSecond+'a';
        std::string hello("");
        hello+=first;
        hello += second;
        ASSERT_TRUE(c.isAWord(hello));
    }
  }
}
//add all 2 digit words to a trie object,
//copy the tree object using = operator,
//make sure that all of the results are in the new trie.
TEST (TrieTest, UTest112) {
  Trie t;
//add all 2 digit words
  for(int posFirst = 0; posFirst<26; posFirst++){
    char first = posFirst+'a';
    for(int posSecond = 0; posSecond<26; posSecond++){
      char second = posSecond+'a';
        std::string word("");
        word+=first;
        word += second;
        t.addAWord(word);
    }
  }
//Declare c and copy it.
  Trie c;
  c = t;
//make sure all items in c are in t.
  for(int posFirst = 0; posFirst<26; posFirst++){
    char first = posFirst+'a';
    for(int posSecond = 0; posSecond<26; posSecond++){
      char second = posSecond+'a';
        std::string word("");
        word+=first;
        word += second;
        ASSERT_TRUE(c.isAWord(word));
    }
  }
}

//make sure that the wordsWithWildCardPrefix method returns an empty string vector.
TEST(TrieTestCases, TestWildCardMethod1){
  Trie t;
  t.addAWord("hello");
  vector<std::string> empty;
  ASSERT_TRUE(empty==t.wordsWithWildcardPrefix("hello"));
}
