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
    
    //set array for visited, if 0 not visited, 1 visited
    int* visitedArray = new int[this->numOfNodes]();
    int distance = 0;
    Queue* queue = new Queue();
    Node* curr = NULL;
    
    if(start > 0 && start < numOfNodes){
        visitedArray[start] = 1;
        curr = graphlist[start]->getHead();
        while(curr != NULL){
            queue->enqueue(curr->getData(),1);
            curr = curr->getNext();
        }
    }
    else{
        std::cout<<"ERROR: start point is greater then number of NOdes or less than zero";
        return;
    }
        
    while(!queue->isEmpty()){
        curr = queue->dequeue();
        std::cout<<curr->getData()<<" is "<<curr->getDistance()<<" from "<<start<<std::endl;
        if(!visitedArray[curr->getData()]){
            distance = curr->getDistance() + 1;
            while(curr != NULL){
                queue->enqueue(curr->getData(),distance);
                curr = curr->getNext();
            }
        }
    }
    
    
}



GraphList::~GraphList() {
}

