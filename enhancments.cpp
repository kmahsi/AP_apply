
#include <iostream>
#include <string>
#include<algorithm>
// #include <stdio.h>
#include<list>
#include <string>
// #include <vector>
#include <unordered_map>
#include <list>
enum nodeType { OR, XOR, AND, LEAF };

using namespace std;
int main()
{
	list<int>  features;
	features.push_back(3);
	features.push_back(4);
	features.remove(3);
	list<int>::iterator it = std::find(features.begin(), features.end(), 3);
	cout << (it == features.end());
	// cout << "Hi"<< endl;
	// string pch = strtok ("asdfasdfdsaf asdf - fa- afs/+ asdf"," ,.-");
	// while (pch != "")
	// {
	//     cout << pch << endl;
	// 	pch = strtok (NULL, " ,.-");
	// }
	// string s = "HI+kami+I'm+Here+Baby";
	// int n = 5;
	// while ( s.find("+") != string::npos )
	// {
	// 	string adjNode = s.substr(0, s.find("+"));
	// 	cout << adjNode << "   " << s << "          " << s.find("+") << "     " << s.length() <<endl;
	// 	s = s.substr(s.find("+") + 1);
	// }
	// cout << s;
	
	// int * a = new int;
	// *a = 3;
	// cout << *a << endl;
	// delete a;
	// cout << *a << endl;
	// unordered_map< int, string > a;
	// a[0] = "3";
	// a[1] = "6";
	// unordered_map< int, string >::iterator it = a.begin();
	// while(it != a.end())
	// {
	// 	cout << it->first << "  " << it->second << endl;
	// 	it++;
	// }
	// vector<string> *a = new std::vector<string>;
	// a->push_back("G");
	// delete a;
	// std::vector<char> *v;
	
};