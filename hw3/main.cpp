/* 
 * File:   main.cpp
 * Author: kreter
 *
 * Created on October 7, 2014, 4:47 PM
 */

#include <cstdlib>
#include<iostream>

#include "GraphList.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int numOfNodes = 0, edge1 = 0, edge2 = 0;
    GraphList* graph;
    
    cout<<"Enter the number of elements"<<endl;
    cin>>numOfNodes;
    
    graph = new GraphList(4);
    for(int i=0; i<numOfNodes; i++){
        cout<<"Enter the two edges";
        cin>>edge1>>edge2;
        cout<<edge1<<edge2<<endl;
        graph->addEdge(edge1,edge2);
    }
    
    graph->printGraph();
    
    return 0;
}

