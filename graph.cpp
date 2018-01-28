
#include "graph.h"
#include <algorithm>
using namespace std;


void printQ(list<string> q)
{
	list<string>::iterator it = q.begin();
	cout << endl << "                    We are pring que" << endl;
	while( it != q.end())	
	{
		cout << *it << "    ";
		it++;
	}
	cout << endl << "                   printing finished" << endl;;
}
// void printVector(std::vector<string> *q)
// {
// 	cout << "We are in that fuck" << endl;
// 	vector<string>::iterator it = q->begin();
// 	cout << endl << "                    We are pring vector" << endl;
// 	while( it != q->end())	
// 	{
// 		cout << *it << "    ";
// 		it++;
// 	}
// 	cout << endl << "                   printing finished" << endl;;	
// }

bool Graph::addNode(string nodeName)
{
	if (!nodes[nodeName])
	{
		cout << "The node has created " << nodeName << endl;
		nodes[nodeName] = new Node(nodeName);
		cout << nodes[nodeName]->getType() << endl;
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
	cout << "Beggining of checkCoffeeBFS "<< endl << endl << endl << endl;
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
    	cout << "Q is not empty" << endl;
    	printQ(queue);
        string s = queue.front();
        queue.pop_front();
 		bool visitNoneOfOrVertix = true;
 		int numberOfXorVertixes = 0;
 		cout << "We ahve reached here and s is: " << s << endl;
 		// printVector(adjList[s]);
        for (adjListIterator = adjList[s]->begin(); adjListIterator != adjList[s]->end(); adjListIterator++)
        {
        	cout << "We ahve reached here and adj is : " << *adjListIterator << endl;
            if (!visited[*adjListIterator])
            {
            	visited[*adjListIterator] = true;
            	list<string>::iterator it = std::find(features.begin(), features.end(), *adjListIterator);
            	cout << "The type is : " << nodes[s]->getType() << "   " << nodes[*adjListIterator]->getMandatory() << endl;
            	switch(nodes[s]->getType())
        		{
	        		case PLUS:
	        			if(nodes[*adjListIterator]->getMandatory())
	        			{
	        				if (it == features.end()) return false; else features.remove(*adjListIterator);
	                		queue.push_back(*adjListIterator);
	        			}else
	        			{
	        				cout << "We are in else"  << (it != features.end() ) << endl;
	        				if (it != features.end()) 
	        				{
	        					features.remove(*adjListIterator);
	        					queue.push_back(*adjListIterator);	
	        				}
	        				printQ(queue);
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
        cout << "We are before two ifs!" << endl;
        if(nodes[s]->getType() == OR && visitNoneOfOrVertix) return false;
        if(nodes[s]->getType() == XOR && numberOfXorVertixes != 1) return false;
        cout << "We are after two ifs!" << endl;
        printQ(features); cout << "ggggggggggggggggggggggGG" << endl;
    }
    return true;
}

void Graph::setRoot(string _root)
{
	cout << "Zereshk";
	root = _root;
}

