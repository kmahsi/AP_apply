#include<iostream>

enum nodeType { OR, XOR, AND, LEAF };

class Node
{
public:
	Node(std::string _name, nodeType _type, bool _mandatory);
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