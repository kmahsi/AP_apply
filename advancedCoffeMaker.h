
#include "graph.h"

class AdvancedCoffeMaker
{
public:
	void getInput();
private:
	Graph* featureGraph;
	nodeType findNodeType(std::string);
	bool addEdge(std::string, std::string);
};

