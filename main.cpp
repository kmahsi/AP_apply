#include<iostream>
#include <list>

#include "AdvancedCoffeMaker.h"


using namespace std;

bool test(int a= 3, int b = 4, int c = 5)
{
	cout << a + b + c;
}

int main()
{
	
	list<string>::iterator i;
	AdvancedCoffeMaker AMC;
	AMC.getInput();
	list<string> x;
	x.push_back("fi");
	x.push_back("fiasdfa");
	i = x.begin();

	cout << *(++i);
	cout << "a\n";
	test();
}