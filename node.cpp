#include "node.h"

using namespace std;

Node::Node(std::string _name, nodeType _type = LEAF, bool _mandatory = false)
{
	name = _name;
	type = _type;
	mandatory = _mandatory;
}

bool Node::setType(nodeType _type) 
{ 
	type = _type; 
	return true; 
}
bool Node::setMandatory(bool _mandatory) 
{ 
	mandatory = _mandatory; 
	return true; 
}



std::string Node::getName() { return name; }
nodeType Node::getType() { return type; }
bool Node::getMandatory() { return mandatory; }

