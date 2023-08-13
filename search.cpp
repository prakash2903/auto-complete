#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

#include "trie.h"
#include "node.h"

int main()
{
	string data;
	fstream dictionary;
	Trie complete_query;
	int ans;

	system("Color E4");
	cout << "\n\n\t\t\t\tWORD PREDICTOR USING PREFIX TREE" << endl;
	cout << "\t\t\t\t--------------------------------\n\n";


        dictionary.open("dictionary.txt",fstream::in);
        if (dictionary.is_open())
        {
            while (dictionary)
            {
                dictionary >> data;
                complete_query.insert(data);
            }
        }
        else
        {
            cout << "error:  file not open." << endl;
            return -1;
        }

        dictionary.close();

        data.clear();
        {

        }
        while(1)
        {
            cout<<"\n1] Predict word .\n2] Exit\n";
            cout<<"\nEnter your choice : ";
            cin>>ans;
            if (ans==1)
            {
                cout << "\nEnter search query: " << endl;
                cin.ignore();
                getline(cin, data);
                complete_query.is_space(data);
                cout << "\nMatching words are...\n  " << endl;

                if (complete_query.getSpace() == true)
                {
                    complete_query.remove_prefix(data);
                    complete_query.search(complete_query.break_string(data));
                }
                else
                    complete_query.search(data);

            }
            else if (ans==2)
            {
                exit(0);
            }
        }



	return 0;
}
