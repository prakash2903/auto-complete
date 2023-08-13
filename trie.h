
using namespace std;
#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <string>
#include "node.h"

class Trie
{
	friend class Node;
private:
	bool space;
	string no_prefix;
	Node* root;

public:

	Trie() {root = new Node(); this->space = false;}
	~Trie()
	{
	}

	void is_space(string data);
	bool getSpace() {return space;}
	void insert(string data);
	void search(string data);
	void print_tree(Node* root, string data, string str);
	void print_tree(Node* root, string str);
	void remove_prefix(string data);
	string getNo_prefix()
	{
	    return no_prefix;
    }
	string break_string(string);
};

#endif
