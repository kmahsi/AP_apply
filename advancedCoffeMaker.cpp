#include "advancedCoffeMaker.h"
#include<iostream>
#include<algorithm>
using namespace std;
#include <stdio.h>
#include <string.h>

void AdvancedCoffeMaker::getInput()
{
	string featureModelLine, descriptionLine ;
	getline(cin, featureModelLine);
	while (featureModelLine != "#")
	{
						//erase all whitespaces in the input
		featureModelLine.erase(remove_if(featureModelLine.begin(), featureModelLine.end(), ::isspace), featureModelLine.end());
		string superFeature = featureModelLine.substr(0, featureModelLine.find("="));
		string subFeatures = featureModelLine.substr(featureModelLine.find("=") + 1);

		featureGraph->addNode(superFeature);
		featureGraph->setType(superFeature, findNodeType(subFeatures));
		addEdge(superFeature, subFeatures);
		

		getline(cin, featureModelLine);
	}
	getline(cin, descriptionLine);
	while(descriptionLine != "##")
	{

		getline(cin, descriptionLine);
	}


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

bool AdvancedCoffeMaker::addEdge(string superFeature, string subFeatures)
{
	string adjNode;

	while( subFeatures.find("+") != string::npos)		
	{
		adjNode = subFeatures.substr(0, subFeatures.find("+"));
		bool mandatory = ( adjNode[0] == "?" ) ?  true : false;
		adjNode = ( adjNode[0] == "?" ) ? adjNode.substr(1) : adjNode;
		featureGraph->addNode(adjNode);
		featureGraph->setMandatory(mandatory);
		subFeatures = subFeatures.substr(subFeatures.find("+") + 1);
	}
	adjNode = subFeatures;
	bool mandatory = ( adjNode[0] == "?" ) ?  true : false;
	adjNode = ( adjNode[0] == "?" ) ? adjNode.substr(1) : adjNode;
	featureGraph->addNode(adjNode);
	featureGraph->setMandatory(mandatory);

}