#include "graph.h"
#include <algorithm>
using namespace std;

bool Graph::addNode(string nodeName)
{
	if (!nodes[nodeName])
	{
		adjList[nodeName] = new vector<string>;
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

bool Graph::checkCoffeeBFS(list<string> & features)
{
	std::unordered_map <std::string, Node*>::iterator nodesIterator = nodes.begin();
	unordered_map <std::string, bool> visited;
	while(nodesIterator != nodes.end())
	{
        visited[(nodesIterator++)->first] = false;
	}
	list<string> queue;
	visited[root] = true;
	list<string>::iterator findRoot = std::find(features.begin(), features.end(), root);
	if ( findRoot == features.end()) return false;
	features.remove(root);
	queue.push_back(root);
	vector<string>::iterator adjListIterator;
	while(!queue.empty())
    {
        string s = queue.front();
        queue.pop_front();
 		bool visitNoneOfOrVertix = true;
 		int numberOfXorVertixes = 0;
        for (adjListIterator = adjList[s]->begin(); adjListIterator != adjList[s]->end(); adjListIterator++)
        {
            if (!visited[*adjListIterator])
            {
            	visited[*adjListIterator] = true;
            	list<string>::iterator it = std::find(features.begin(), features.end(), *adjListIterator);
            	switch(nodes[s]->getType())
        		{
	        		case PLUS:
	        			if(nodes[*adjListIterator]->getMandatory())
	        			{
	        				if (it == features.end()) return false; else features.remove(*adjListIterator);
	                		queue.push_back(*adjListIterator);
	        			}else
	        			{
	        				if (it != features.end()) 
	        				{
	        					features.remove(*adjListIterator);
	        					queue.push_back(*adjListIterator);	
	        				}
	        			}
	        			break;
	        		case OR:
	        			if (it != features.end()) 
	        			{
	        					visitNoneOfOrVertix = false;
	        					features.remove(*adjListIterator);
	        					queue.push_back(*adjListIterator);	
	        			}
	        			break;
	        		case XOR:
	        			if (it != features.end()) 
	        			{
	        					numberOfXorVertixes++;
	        					features.remove(*adjListIterator);
	        					queue.push_back(*adjListIterator);	
	        			}
	        			break;
        		};	     
            }
        }
        if(nodes[s]->getType() == OR && visitNoneOfOrVertix) return false;
        if(nodes[s]->getType() == XOR && numberOfXorVertixes != 1) return false;
    }
    return true;
}

void Graph::setRoot(string _root)
{
	root = _root;
}

