#include "node.h"
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

class Graph
{
public:
	bool addNode(std::string);
	bool setType(std::string, nodeType);
	bool setMandatory(std::string, bool);
	bool addEdge(std::string, std::string);
	void emptyGraph();
private:
	std::unordered_map <std::string, Node*> nodes;
	std::unordered_map < std::string, std::vector <std::string>* >adjList;
	Node* getNode(std::string);

};
