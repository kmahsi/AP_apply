

#include<iostream>

enum nodeType { OR, XOR, PLUS, LEAF };

class Node
{
public:
	Node(std::string _name, nodeType _type = LEAF, bool _mandatory = false);
	std::string getName();
	nodeType getType();
	bool getMandatory();
	bool setType(nodeType);
	bool setMandatory(bool);

private:
	std::string name;
	nodeType type;
	bool mandatory;
};



