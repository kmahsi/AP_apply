#include "graph.h"
#include <list>
class AdvancedCoffeMaker
{
public:
	bool getInput();
	AdvancedCoffeMaker();
	~AdvancedCoffeMaker();
private:
	Graph* featureGraph;
	nodeType findNodeType(std::string);
	bool addEdges(std::string, std::string);
	std::list<std::string> getFeatures(std::string);
};

