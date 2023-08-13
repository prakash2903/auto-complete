
#include <iostream>
#include <string>

#include "trie.h"
#include "node.h"

using namespace std;

void Trie::insert(string data)
{
	Node* tmp = root;
	char cstr[data.length()];

	data.copy(cstr, data.length());
	for (int i = 0; i < data.length(); i++)
	{
		if (tmp->child[static_cast<int>(cstr[i])] != NULL)
			tmp = tmp->child[static_cast<int>(cstr[i])];
		else
		{
			tmp->child[static_cast<int>(cstr[i])] = new Node();
			tmp = tmp->child[static_cast<int>(cstr[i])];
			tmp->setChar(cstr[i]);
		}
	}
	tmp->setWord(true);
}

void Trie::print_tree(Node* root, string data, string str)
{
	for (int i = 0; i < 128; i++)
	{
		Node* adv = root;
		if (adv->child[i] != NULL)
		{
			adv = adv->child[i];
			str += adv->getChar();
			if (adv->isWord())
			{
				if (this->getSpace() == true)
				{
                    cout << this->getNo_prefix();
				}
				cout << str << endl;
			}
			print_tree(adv, str);
		}
		str = data;
	}
}

void Trie::print_tree(Node* root, string str)
{
	string str_tmp = str;

	for (int i = 0; i < 128; i++)
	{
		Node* adv = root;
		if (adv->child[i] != NULL)
		{
			adv = adv->child[i];
			str += adv->getChar();
			if (adv->isWord())
			{
				if (this->getSpace() == true)
					cout << this->no_prefix;
				cout << str << endl;
			}
			print_tree(adv, str);
		}
		str = str_tmp;
	}
}

void Trie::search(string data)
{
	Node* tmp = root;
	char cstr[data.length()];

	data.copy(cstr, data.length(), 0);
	for (int i = 0; i < data.length(); i++)
	{
		if (tmp->child[static_cast<int>(cstr[i])] == NULL)
		{
			cout << "error:  string not found" << endl;
			return;
		}
		else
			tmp = tmp->child[static_cast<int>(cstr[i])];
		if (tmp->getChar() != cstr[i])
		{
			cout << "error:  string not found" << endl;
			return;
		}
	}
	string str = data;
	print_tree(tmp, data, str);
}

void Trie::is_space(string data)
{
	char cstr[data.length()];

	data.copy(cstr, data.length());
	for (int i = 0; i < data.length(); i++)
	{
		if (cstr[i] == ' ')
		{
			space = true;
			return;
		}
		else
			continue;
	}
}

string Trie::break_string(string data)
{
	char cstr[data.length()];
	string str;
	data.copy(cstr, data.length());

	for (int i = data.length(); i-- > 0;)
	{
		if (cstr[i] == ' ')
			 break;
		else
			str.insert(str.begin(),cstr[i]);
	}
	return str;
}

void Trie::remove_prefix(string data)
{
	char cstr[data.length()];
	data.copy(cstr, data.length());

	for (int i = data.length(); i-- > 0;)
	{
		if (cstr[i] == ' ')
			break;
		else
			cstr[i] = '\0';
	}
	no_prefix = cstr;
}
