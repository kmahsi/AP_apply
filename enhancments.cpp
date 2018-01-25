#include<iostream>
#include<string>
#include<algorithm>
#include <stdio.h>
#include <string.h>

enum nodeType { OR, XOR, AND, LEAF };

using namespace std;
int main()
{
	string pch = strtok ("asdfasdfdsaf asdf - fa- afs/+ asdf"," ,.-");
	while (pch != "")
	{
	    cout << pch << endl;
		pch = strtok (NULL, " ,.-");
	}
	
}