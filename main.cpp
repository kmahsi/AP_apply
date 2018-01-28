#include <iostream>
#include <list>
#include <map>
#include "advancedCoffeMaker.h"


// define # and ## instead of using it inside code.
// fix makefile complier / options
// make constructors if you can
// user ifndefine for #( compiler language )
// rename check coffee bfs!
// save number of vertices in graph(you should wright constructor i think)
// remove duplicate code in 

using namespace std;

void printQ(std::list<std::string> q)
{
	cout << "Baghali" << std::endl;
	std::list<std::string>::iterator it = q.begin();
	cout << std::endl << "printing Que" << std::endl;
	while( it != q.end())	
	{
		cout << *it << endl;
		it++;
	}
	cout << std::endl << "printing finished" << std::endl;;
}

int main()
{
	AdvancedCoffeMaker a;

	a.getInputAnProcess();
	list<string> result = a.getOutput();
	printQ(result);
	string featureModelLine;
	while (getline(cin, featureModelLine))
		cout << featureModelLine << endl;
		
}


// int main()
// {
// 	cout << "Hi";	
// }