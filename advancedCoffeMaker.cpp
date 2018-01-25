#include "AdvancedCoffeMaker.h"
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
		
		while ((pos = s.find(delimiter)) != std::string::npos) {
 		   	token = s.substr(0, pos);
    		std::cout << token << std::endl;
    		s.erase(0, pos + delimiter.length());
		}


		getline(cin, featureModelLine);
	}
	getline(cin, descriptionLine);
	while(descriptionLine != "##")
	{

		getline(cin, descriptionLine);
	}


}