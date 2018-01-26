
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

void Graph::emptyGraph()
{
	std::unordered_map <std::string, Node*>::iterator nodesIterator = nodes.begin();
	while(nodesIterator != nodes.end())
	{
		delete (nodesIterator++)->second;
	}
	nodes.clear();
	std::unordered_map < std::string, std::vector <std::string>* >::iterator adjListIterator = adjList.begin();
	while(adjListIterator != adjList.end())
	{
		delete (nodesIterator++)->second;
	}
	adjList.clear();
}

bool Graph::checkCoffeeBFS(list<string> features)
{
	std::unordered_map <std::string, Node*>::iterator nodesIterator = nodes.begin();
	unordered_map <std::string, bool> visited;
	while(nodesIterator != nodes.end())
	{
        visited[(nodesIterator++)->first] = false;
	}
	list<string> queue;
	visited[root] = true;
	queue.push_back(root);
}

void Graph::setRoot(string _root)
{
	root = _root;
}