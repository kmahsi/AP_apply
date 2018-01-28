#include "graph.h"
#include <list>
#include <string>

#define VALID  "valid"
#define INVALID "invalid"


class AdvancedCoffeMaker
{
public:
	void getInputAnProcess();
	std::list<std::string> getOutput();
	AdvancedCoffeMaker();
	~AdvancedCoffeMaker();
private:
	Graph* featureGraph;
	nodeType findNodeType(std::string);
	bool addEdges(std::string, std::string);
	std::list<std::string> output;
};

