#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void Graph::addVertex(string name){
    //TODO

    bool found = false;
	for(int i=0; i < vertices.size(); i++)
	{
		if(vertices[i]->name == name)
		{
			found = true;
			cout << vertices[i]->name << " found." << endl;
		}
	}
	if(found == false)
	{
		vertex *v = new vertex;
		v->name = name;
		v->distance = 0;
		vertices.push_back(v);
	}
    
}

void Graph::addEdge(string v1, string v2){
    //TODO

    for(int i=0; i < vertices.size(); i++)
	{
		if(vertices[i]->name == v1)
		{
			for(int j=0; j < vertices.size(); j++)
			{
				if(vertices[j]->name == v2 && i != j)
				{
					adjVertex av;
					av.v = vertices[j];
					vertices[i]->adj.push_back(av);
					// another vetex for edge in the other direction
					adjVertex av2;
					av2.v = vertices[i];
					vertices[j]->adj.push_back(av2);
				}
			}
		}
	}
    
}

void Graph::displayEdges(){
    //TODO

    for(int i = 0; i < vertices.size(); i++){
        cout << vertices[i]->name << " --> ";
        for(int j = 0; j< vertices[i]->adj.size(); j++){
            cout << vertices[i]->adj[j].v->name << " ";
        }
        cout << endl;
    }
	// for loop - from i=0 to vertices.size()
	// cout << vertices[i]->name << endl
	// inner for loop: from j=0 to vertices[i]->adj.size()
	// 	cout << vertices[i]->adj[j].v->name << endl;
    
}

void Graph::breadthFirstTraverse(string sourceVertex){
    //TODO



    vertex *vertexStart;
    vector<vertex*> vi = getVertices();
    for(vertex* i : vi){
        if(i->name == sourceVertex){
            vertexStart = i;
        }
    }
    cout<< "Starting vertex (root): " << vertexStart->name << "->";
	vertexStart->visited = true;
	// assume sourceVertex = Boulder
	// vertexStart = vertices[2] ----> vertexStart is a pointer to Boulder
	// vertexStart->visited = true; // Boulder's visited = true
	
	// create a queue to keep track of what??? visited vertices!
	// using the STL queue

	queue<vertex*> myqueue;
	myqueue.push(vertexStart);
	vector<adjVertex> adj = vertexStart->adj;
	int counter = 1;

	while(!myqueue.empty()){
		adj = myqueue.front()->adj;
		for(adjVertex i : adj){
			if(i.v->visited == false){
				i.v->distance++;
				i.v->visited = true;
				myqueue.push(i.v);
				cout << i.v->name <<"("<< i.v->distance <<")"<< " ";
			}
    	}
		myqueue.pop();
	}



	// vector<adjVertex> adj = vertexStart->adj;

	// for(adjVertex i : adj){
    //     if(i.v->visited == false){
    //         i.v->distance++;
	// 		i.v->visited = true;
	// 		myqueue.push(i.v);
    //     }
    // }

	
	vertex* item;
	while(!myqueue.empty()){
		item = myqueue.front();
		cout << item->name <<"("<< item->distance <<")"<< " ";
		myqueue.pop();
	}

	cout << " " << endl << endl;
	
	// going through the adj list of each element in the queue
	// check if the vertex visited
	// if vertex is not visited
	//set the distance of that adj vertex to +1
	//....->visited = true
	// push the adv vertex onto the queue
    

}

/*
string::source : source vertex (starting city)
int::k : distance that you can travel from source city with remaining fuel
*/

vector<string> Graph::findReachableCitiesWithinDistanceK(string source, int k){
    //TODO
    return vector<string>();
}
