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

void GraphList::BFS(){
    int distance = 0;
    
}



GraphList::~GraphList() {
}

