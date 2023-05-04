#include<iostream>
using namespace std;
#include "trienode.h"

int main() {
    Trie t;
    t.insertWord("and");
    t.insertWord("or");
    t.insertWord("not");

    cout << t.search("and") << endl;

    t.removeword("and");

    cout << t.search("and") << endl;
     
     return 0;
}