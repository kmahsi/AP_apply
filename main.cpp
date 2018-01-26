
#include <iostream>
#include <list>
#include <map>
#include "advancedCoffeMaker.h"
// #include "node.h"


// define # and ## instead of using it inside code.

using namespace std;
string s = "gholi";

class X
{
public:
	X()
	{
		x = new Node(s);
	}
	~X()
	{
		cout << "hi";
		delete x;
	}

	Node* x;
};

int main()
{
	X t;
	// delete t.x;
	
}


// int main()
// {
// 	cout << "Hi";	
// }