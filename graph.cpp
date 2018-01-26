
#include "graph.h"
 
using namespace std;

bool Graph::addNode(string nodeName)
{
	if (!nodes[nodeName])
	{
		nodes[nodeName] = new Node(nodeName);
		return true;
	}
	return false;
}

bool Graph::setType(string nodeName, nodeType type)
{
	getNode(nodeName)->setType(type);
	return true;
}

bool Graph::setMandatory(string nodeName, bool mandatory)
{
	getNode(nodeName)->setMandatory(mandatory);
	return true;
}

bool Graph::addEdge(string firstNode, string secondNode)
{
	if (!nodes[firstNode] | !nodes[secondNode]) { return false; }
	if (!adjList[firstNode])
	{
		adjList[firstNode] = new vector<string>;
	}
	adjList[firstNode]->push_back(secondNode);
	return true;
}


Node* Graph::getNode(string nodeName)
{
	return nodes[nodeName];
}