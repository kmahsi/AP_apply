
#include<iostream>
#include<string>
// #include<algorithm>
// #include <stdio.h>
#include <string.h>
// #include <vector>

enum nodeType { OR, XOR, AND, LEAF };

using namespace std;
int main()
{
	// cout << "Hi"<< endl;
	// string pch = strtok ("asdfasdfdsaf asdf - fa- afs/+ asdf"," ,.-");
	// while (pch != "")
	// {
	//     cout << pch << endl;
	// 	pch = strtok (NULL, " ,.-");
	// }
	string s = "HI+kami+I'm+Here+Baby";
	do
	{
		string adjNode = s.substr(0, s.find("+"));
		cout << adjNode << "   " << s << "          " << s.find("+") << "     " << s.length() <<endl;
		s = s.substr(s.find("+") + 1);
	}while(s.find("+") != string::npos);
	// cout << s;
	
	// list<

	// std::vector<char> *v;
	
}