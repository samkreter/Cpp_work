/* 
 * File:   GraphList.cpp
 * Author: kreter
 * 
 * Created on October 7, 2014, 4:50 PM
 */

#include<iostream>
#include "Node.h"
#include "List.h"
#include "GraphList.h"
#include "Queue.h"


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

void GraphList::addEdge(int edge1, int edge2){
    graphlist[edge1]->add(edge2);
}

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

void GraphList::BFS(int start){
    
//    Queue* q = new Queue();   
//    q->enqueue(1,8);
//    std::cout<<q->dequeue()->getData();
    
    
    
    
    //set array for visited, if 0 not visited, 1 visited
    int* visitedArray = new int[this->numOfNodes]();
    int distance = 0;
    Queue queue = Queue();
    Node* curr = NULL;
    
    
    if(start > 0 && start < numOfNodes){
        visitedArray[start] = 1;
        curr = graphlist[start]->getHead();
        while(curr != NULL){
            std::cout<<"test";
            std::cout<<curr->getData();
            queue.enqueue(4,1);
            curr = curr->getNext();
        }
    }
    else{
        std::cout<<"ERROR: start point is greater then number of NOdes or less than zero";
        return;
    }
    
    while(!queue.isEmpty()){
        std::cout<<"test2";
        curr = queue.dequeue();
        std::cout<<curr->getData()<<" is "<<curr->getDistance()<<" from "<<start<<std::endl;
        if(!visitedArray[curr->getData()]){
            distance = curr->getDistance() + 1;
            while(curr != NULL){
                queue.enqueue(curr->getData(),distance);
                curr = curr->getNext();
            }
        }
    }
    
    
}

void GraphList::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    std::cout << v << " ";
 
    Node* curr = graphlist[v]->getHead();
    while(!visited[curr->getData()] && curr->getNext() != NULL){
        curr = curr->getNext();
    }
    if(curr == NULL){
        return;
    }
    else{
        DFSUtil(curr->getData(),visited);
    }
   
}
 
// DFS traversal of the vertices reachable from v. It uses recursive DFSUtil()
void GraphList::DFS(int v)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[this->numOfNodes];
    for(int i = 0; i < this->numOfNodes; i++)
        visited[i] = false;
 
    // Call the recursive helper function to print DFS traversal
    //DFSUtil(v, visited);
}

GraphList::~GraphList() {
}

