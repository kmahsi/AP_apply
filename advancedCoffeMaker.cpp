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
		features = getFeatures(descriptionLine);
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
	string adjNode;
	char delimiter = '+';
	if (subFeatures.find('+') != string::npos) delimiter = '+';
	if (subFeatures.find('|') != string::npos) delimiter = '|';
	if (subFeatures.find('^') != string::npos) delimiter = '^';
	cout << "                                       delimiter is :  " << delimiter << endl;
	while( subFeatures.find(delimiter) != string::npos)		
	{
		adjNode = subFeatures.substr(0, subFeatures.find(delimiter));
		cout << "            mandatory is " << adjNode << endl;
		bool mandatory = ( adjNode[0] != '?' && delimiter == '+' ) ?  true : false;
		cout << "            mandatory is " << mandatory << endl;
		adjNode = ( adjNode[0] == '?' ) ? adjNode.substr(1) : adjNode;
		cout << "We are adding and adjNode to feature graph" << adjNode << endl;
		featureGraph->addNode(adjNode);
		featureGraph->addEdge(superFeature, adjNode);
		featureGraph->setMandatory(adjNode, mandatory);
		subFeatures = subFeatures.substr(subFeatures.find(delimiter) + 1);
	}
	adjNode = subFeatures;
	bool mandatory = ( adjNode[0] != '?' && delimiter == '+' ) ?  true : false;
	adjNode = ( adjNode[0] == '?' ) ? adjNode.substr(1) : adjNode;
	cout << "We are adding and adjNode to feature graph" << adjNode << endl;
	featureGraph->addNode(adjNode);
	featureGraph->addEdge(superFeature, adjNode);
	featureGraph->setMandatory(adjNode, mandatory);

}

list<string> AdvancedCoffeMaker::getFeatures(string descriptionLine)
{
	list<string> features;
	descriptionLine = descriptionLine.substr(1, descriptionLine.length() -2);
	while( descriptionLine.find(",") != string::npos)		
	{
		cout << "This is descriptionLine :   " << descriptionLine.substr(0, descriptionLine.find(",")) << endl;
		features.push_back(descriptionLine.substr(0, descriptionLine.find(",")));
		descriptionLine = descriptionLine.substr(descriptionLine.find(",") + 1);
	}
	cout << "This is descriptionLine :   " << descriptionLine << endl;
	features.push_back(descriptionLine);
	return features;
}


AdvancedCoffeMaker::AdvancedCoffeMaker()
{
	featureGraph = new Graph;
	cout << "Zereshkkkkkkkkkkkkkkkkkk" << endl;;
}

AdvancedCoffeMaker::~AdvancedCoffeMaker()
{
	delete featureGraph;
}