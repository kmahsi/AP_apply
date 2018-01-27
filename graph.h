#include "node.h"
#include <string>
#include <vector>
#include <map>
#include <list>
#include <unordered_map>

class Graph
{
public:
	bool addNode(std::string);
	bool setType(std::string, nodeType);
	bool setMandatory(std::string, bool);
	bool addEdge(std::string, std::string);
	void emptyGraph();
	bool checkCoffeeBFS(std::list<std::string> &);
	void setRoot(std::string);
private:
	std::string root;
	std::unordered_map <std::string, Node*> nodes;
	std::unordered_map < std::string, std::vector <std::string>* >adjList;
	Node* getNode(std::string);
};
