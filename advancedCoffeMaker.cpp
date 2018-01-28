#include "utils.cpp"
#include "advancedCoffeMaker.h"
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <list>

using namespace std;

void AdvancedCoffeMaker::getInputAnProcess()
{
	string featureModelLine, descriptionLine ;
	list<string> features;

	featureModelLine.erase(remove_if(featureModelLine.begin(), featureModelLine.end(), ::isspace), featureModelLine.end());
	featureGraph->setRoot(featureModelLine.substr(0, featureModelLine.find("=")));
	while(getline(cin, featureModelLine))
	{
		while (featureModelLine != "#")
		{
							//erase all whitespaces in the input
			string superFeature = featureModelLine.substr(0, featureModelLine.find("="));
			string subFeatures = featureModelLine.substr(featureModelLine.find("=") + 1);
			featureGraph->addNode(superFeature);
			featureGraph->setType(superFeature, findNodeType(subFeatures));
			addEdges(superFeature, subFeatures);

			getline(cin, featureModelLine);
			featureModelLine.erase(remove_if(featureModelLine.begin(), featureModelLine.end(), ::isspace), featureModelLine.end());
		}
		getline(cin, descriptionLine);
		while(descriptionLine != "##")
		{
			descriptionLine.erase(remove_if(descriptionLine.begin(), descriptionLine.end(), ::isspace), descriptionLine.end());
			features = splitByDelimiter(descriptionLine.substr(1, descriptionLine.length() -2), ',');
			getline(cin, descriptionLine);
			bool result = featureGraph->checkCoffeeBFS(features);
			if (result && features.empty()) output.push_back(VALID); else output.push_back(INVALID);
		}
		output.push_back("##");
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

bool AdvancedCoffeMaker::addEdges(string superFeature, string subFeatures)
{
	char delimiter = '+';
	if (subFeatures.find('+') != string::npos) delimiter = '+';
	if (subFeatures.find('|') != string::npos) delimiter = '|';
	if (subFeatures.find('^') != string::npos) delimiter = '^';

	list<string> splitedSubfeatures = splitByDelimiter(subFeatures, delimiter);
	list<string>::iterator adjNodeIterator;
	
	for (adjNodeIterator = splitedSubfeatures.begin(); adjNodeIterator != splitedSubfeatures.end(); adjNodeIterator++)
	{
		*adjNodeIterator = subFeatures.substr(0, subFeatures.find(delimiter));
		bool mandatory = ( (*adjNodeIterator)[0] != '?' && delimiter == '+' ) ?  true : false;
		*adjNodeIterator = ( (*adjNodeIterator)[0] == '?' ) ? adjNodeIterator->substr(1) : *adjNodeIterator;
		featureGraph->addNode(*adjNodeIterator);
		featureGraph->addEdge(superFeature, *adjNodeIterator);
		featureGraph->setMandatory(*adjNodeIterator, mandatory);
		subFeatures = subFeatures.substr(subFeatures.find(delimiter) + 1);
	}

}


AdvancedCoffeMaker::AdvancedCoffeMaker()
{
	featureGraph = new Graph;
}

AdvancedCoffeMaker::~AdvancedCoffeMaker()
{
	delete featureGraph;
}

std::list<string> AdvancedCoffeMaker::getOutput()
{
	return output;
}