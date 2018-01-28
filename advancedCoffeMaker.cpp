#include "utils.cpp"
#include "advancedCoffeMaker.h"
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <list>

using namespace std;

// void printQ(list<string> q)
// {
// 	list<string>::iterator it = q.begin();
// 	cout << endl << "                    We are pring que" << endl;
// 	while( it != q.end())	
// 	{
// 		cout << *it << "    ";
// 		it++;
// 	}
// 	cout << endl << "                   printing finished" << endl;;
// }
void printVector(std::vector<string> *q)
{
	cout << "We are in that fuck" << endl;
	vector<string>::iterator it = q->begin();
	cout << endl << "                    We are pring vector" << endl;
	while( it != q->end())	
	{
		cout << *it << "    ";
		it++;
	}
	cout << endl << "                   printing finished" << endl;;	
}


bool AdvancedCoffeMaker::getInput()
{
	string featureModelLine, descriptionLine ;
	list<string> features;

	getline(cin, featureModelLine);
	featureModelLine.erase(remove_if(featureModelLine.begin(), featureModelLine.end(), ::isspace), featureModelLine.end());
	cout << featureModelLine.substr(0, featureModelLine.find("=")) << endl;
	featureGraph->setRoot(featureModelLine.substr(0, featureModelLine.find("=")));
	while (featureModelLine != "#")
	{
						//erase all whitespaces in the input
		string superFeature = featureModelLine.substr(0, featureModelLine.find("="));
		string subFeatures = featureModelLine.substr(featureModelLine.find("=") + 1);
		cout << "super feature is : " << superFeature << endl;
		featureGraph->addNode(superFeature);
		cout << "We are setting type to :  " << superFeature << endl;
		featureGraph->setType(superFeature, findNodeType(subFeatures));
		addEdges(superFeature, subFeatures);

		getline(cin, featureModelLine);
		featureModelLine.erase(remove_if(featureModelLine.begin(), featureModelLine.end(), ::isspace), featureModelLine.end());
	}
	cout << "HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH" << endl;
	getline(cin, descriptionLine);
	while(descriptionLine != "##")
	{
		descriptionLine.erase(remove_if(descriptionLine.begin(), descriptionLine.end(), ::isspace), descriptionLine.end());
		// features = getFeatures(descriptionLine);
		features = splitByDelimiter(descriptionLine.substr(1, descriptionLine.length() -2), ',');
		cout << "This is featuressssssssssssssssssssssssssssssssssssssssssssssssssssssssssss:   " << endl;
		// printQ(features);
		getline(cin, descriptionLine);
	}
	cout << "HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH" << endl;
	bool result = featureGraph->checkCoffeeBFS(features);
	cout << "HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh" << endl;
	cout << "This is result " << endl;
	cout << result << "   " << features.empty() << endl;
	// printQ(features);
	if (result && features.empty()) return true; else return false;


}

nodeType AdvancedCoffeMaker::findNodeType( string subFeatures )
{
	if(subFeatures.find("+") != string::npos)
		return PLUS;
	else if(subFeatures.find("|") != string::npos)
		return OR;
	else if(subFeatures.find("^") != string::npos)
		return XOR;
	else return LEAF;
}

bool AdvancedCoffeMaker::addEdges(string superFeature, string subFeatures)
{
	char delimiter = '+';
	if (subFeatures.find('+') != string::npos) delimiter = '+';
	if (subFeatures.find('|') != string::npos) delimiter = '|';
	if (subFeatures.find('^') != string::npos) delimiter = '^';

	list<string> splitedSubfeatures = splitByDelimiter(subFeatures, delimiter);
	list<string>::iterator adjNodeIterator;
	
	cout << "                                       delimiter is :  " << delimiter << endl;
	for (adjNodeIterator = splitedSubfeatures.begin(); adjNodeIterator != splitedSubfeatures.end(); adjNodeIterator++)
	{
		*adjNodeIterator = subFeatures.substr(0, subFeatures.find(delimiter));
		cout << "            mandatory is " << *adjNodeIterator << endl;
		bool mandatory = ( (*adjNodeIterator)[0] != '?' && delimiter == '+' ) ?  true : false;
		cout << "            mandatory is " << mandatory << endl;
		*adjNodeIterator = ( (*adjNodeIterator)[0] == '?' ) ? adjNodeIterator->substr(1) : *adjNodeIterator;
		cout << "We are adding and *adjNodeIterator to feature graph" << *adjNodeIterator << endl;
		featureGraph->addNode(*adjNodeIterator);
		featureGraph->addEdge(superFeature, *adjNodeIterator);
		featureGraph->setMandatory(*adjNodeIterator, mandatory);
		subFeatures = subFeatures.substr(subFeatures.find(delimiter) + 1);
	}

}

// list<string> AdvancedCoffeMaker::getFeatures(string descriptionLine)
// {
// 	list<string> features;
// 	descriptionLine = descriptionLine.substr(1, descriptionLine.length() -2);
// 	while( descriptionLine.find(",") != string::npos)		
// 	{
// 		cout << "This is descriptionLine :   " << descriptionLine.substr(0, descriptionLine.find(",")) << endl;
// 		features.push_back(descriptionLine.substr(0, descriptionLine.find(",")));
// 		descriptionLine = descriptionLine.substr(descriptionLine.find(",") + 1);
// 	}
// 	cout << "This is descriptionLine :   " << descriptionLine << endl;
// 	features.push_back(descriptionLine);
// 	return features;
// }


AdvancedCoffeMaker::AdvancedCoffeMaker()
{
	featureGraph = new Graph;
	cout << "Zereshkkkkkkkkkkkkkkkkkk" << endl;;
}

AdvancedCoffeMaker::~AdvancedCoffeMaker()
{
	delete featureGraph;
}