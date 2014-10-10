/* 
 * File:   GraphList.cpp
 * Author: kreter
 * 
 * Created on October 7, 2014, 4:50 PM
 */

#include<iostream>
#include "Node.h"
#include "List.h"
#include "Queue.h"
#include "Stack.h"
#include "GraphList.h"



GraphList::GraphList(int numOfNodes) {
    setNumOfNodes(numOfNodes);
    graphlist = new List* [numOfNodes];
    
    //populating the array of Lists
    for(int i=0; i<this->numOfNodes; i++){
        graphlist[i] = new List();
    }
}


void GraphList::setNumOfNodes(int numOfNodes){
    if(numOfNodes > 0){
        this->numOfNodes = numOfNodes;
    }
    else{
       std::cout<<"Error: number of nodes is not greater than 0"<<std::endl;
    }
}

int GraphList::getNumOfNodes(){
    return this->numOfNodes;
}
//add edges to the graph 
void GraphList::addEdge(int edge1, int edge2){
    if(edge1 < numOfNodes && edge2 < numOfNodes){
        graphlist[edge1]->add(edge2);
    }
    else{
        std::cout<<"Error: edges out of boudn"<<std::endl;
    }
}
//printst the graph 
void GraphList::printGraph(){
    for(int i=0; i<this->numOfNodes; i++){
        std::cout<<i;
        if(graphlist[i]->getHead() != NULL){
            std::cout<<"->";
        }
        if(graphlist[i] != NULL){
            graphlist[i]->printList();
        }
        std::cout<<std::endl;
    }
}
//prints out the distance from the intputed value 
void GraphList::BFS(int start){
    
    
    //set array for visited, if 0 not visited, 1 visited
    int* visitedArray = new int[this->numOfNodes]();
    int distance = 0;
    Queue queue = Queue();
    Node* curr = NULL;
    std::cout<<start<<" is 0 from "<<start<<std::endl;
    
    if(start > 0 && start < numOfNodes){
        visitedArray[start] = 1;
        curr = graphlist[start]->getHead();
        while(curr != NULL){
            queue.enqueue(curr->getData(),1);
            curr = curr->getNext();
        }
    }
    else{
        std::cout<<"ERROR: start point is greater then number of NOdes or less than zero";
        return;
    }
    
    while(!queue.isEmpty()){
        curr = queue.dequeue();
        if(!visitedArray[curr->getData()]){
            std::cout<<curr->getData()<<" is "<<curr->getDistance()<<" from "<<start<<std::endl;
            visitedArray[curr->getData()] = 1;
            distance = curr->getDistance() + 1;
            curr = graphlist[curr->getData()]->getHead();
            while(curr != NULL){
                queue.enqueue(curr->getData(),distance);
                curr = curr->getNext();
            }
        }
    }
    
    for(int i=0;i<this->numOfNodes;i++){
        if(!visitedArray[i]){
            std::cout<<i<<" is not connected to "<<start<<std::endl;
        }
    }
    
    delete(visitedArray);
}

//when each node finishes it is put on the stack 
void GraphList::DFSUtil(int v, int visited[], Stack* q){
    // Mark the current node as visited and print it
    visited[v] = 1;
 
    Node* curr = this->graphlist[v]->getHead();

    if(curr == NULL){
        return;
    }
    while(curr != NULL){
        while(visited[curr->getData()]){
            if(curr == NULL){
                return;
            }
            else{
                curr = curr->getNext();
                if(curr == NULL){
                    return;
                }
            }
        }

        DFSUtil(curr->getData(),visited,q);
        q->push(curr->getData());
    }
   
   
}
 
// DFS traversal of the vertices reachable from v. It uses recursive DFSUtil()
Stack* GraphList::DFS(int v)
{
    // Mark all the vertices as not visited
    int *visited = new int[this->numOfNodes];
    Stack* q = new Stack();
    q->push(v);
    
    for(int i = 0; i < this->numOfNodes; i++)
        visited[i] = 0;
 
    // Call the recursive helper function to print DFS traversal
    DFSUtil(v, visited, q);
    delete(visited);
    return q;
}

GraphList::~GraphList() {
}

