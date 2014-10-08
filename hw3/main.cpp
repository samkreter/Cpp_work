/* 
 * File:   main.cpp
 * Author: kreter
 *
 * Created on October 7, 2014, 4:47 PM
 */

#include <cstdlib>
#include<iostream>
#include<fstream>


#include "GraphList.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    
    int numOfNodes = 0, edge1 = 0, edge2 = 0;
    GraphList* graph;
    ifstream inputFile("test0.grph");
    string thestring; 
    if(inputFile.is_open()){
        while(!inputFile.eof()){
        inputFile >> thestring;
        cout<<thestring<<endl;
        }
    }
    
    
    
    
    /*
    cout<<"Enter the number of elements"<<endl;
    cin>>numOfNodes;

    graph = new GraphList(numOfNodes);
    for(int i=0; i<numOfNodes; i++){
        edge1 = i;
        edge2 = i + 5;
        graph->addEdge(edge1,edge2);
    }
    graph->addEdge(1,3);
    graph->addEdge(1,78);
    graph->printGraph();
    */
    return 0;
}

