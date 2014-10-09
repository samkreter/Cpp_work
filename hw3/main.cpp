/* 
 * File:   main.cpp
 * Author: kreter
 *
 * Created on October 7, 2014, 4:47 PM
 */

#include <cstdlib>
#include<iostream>
#include<fstream>
#include<string>


#include "GraphList.h"
#include "Queue.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
 
    
    int numOfNodes = 0, edge1 = 0, edge2 = 0, counter = 0;
    GraphList* graph;
    std::string parseString, substring;
    ifstream inputFile("test0.grph");
   
    if(inputFile.is_open()){
        inputFile>>numOfNodes;
    }
    else{
        cout<<"error reading the file";
    }
    graph = new GraphList(numOfNodes);
   
    
    while(!inputFile.eof()){
        if(counter < 4){               ////////////////////////////// <<<test
            inputFile>>parseString;
            edge1 = atoi(parseString.substr(1, parseString.find(",")).c_str());
            edge2 = atoi(parseString.substr(parseString.find(",")+1,parseString.length()-1).c_str());
            graph->addEdge(edge1,edge2);
            counter++;
        }
        else{break;}

    }
    
    graph->printGraph();
    
//    Queue* q = new Queue();
//    
//    q->enqueue(1,4);
//    std::cout<<q->dequeue()->getData();
   graph->BFS(1);
    
    
    inputFile.close();
    
    return 0;
}

