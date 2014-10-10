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
#include "Stack.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
 
    
    int numOfNodes = 0, edge1 = 0, edge2 = 0, counter = 0;
    GraphList* graph;
    GraphList* graphTrans;
    std::string parseString, substring;
    ifstream inputFile("test0.grph");
   
    if(inputFile.is_open()){
        inputFile>>numOfNodes;
    }
    else{
        cout<<"error reading the file";
    }
    graph = new GraphList(numOfNodes + 1);
    graphTrans = new GraphList(numOfNodes + 1);
   
    
    while(!inputFile.eof()){
        if(counter < graph->getNumOfNodes()){          
            inputFile>>parseString;
            edge1 = atoi(parseString.substr(1, parseString.find(",")).c_str());
            edge2 = atoi(parseString.substr(parseString.find(",")+1,parseString.length()-1).c_str());
            graph->addEdge(edge1,edge2);
            graphTrans->addEdge(edge2,edge1);
            counter++;
        }
        else{break;}

    }
    
    
    
   
   graph->printGraph();
//    std::cout<<std::endl;
//    graphTrans->printGraph();
    
   
    Stack* q;
    Stack* t;
    //graph->BFS(1);
    q = graph->DFS(1);
    
    //while(!q->isEmpty()){
        t = graphTrans->DFS(q->top()->getData());
        while(!q->isEmpty()){
            std::cout<<";alkdsjf"<<q->isEmpty()<<"alkjd;f"<<std::endl;
            std::cout<<q->pop()->getData()<<" ";
        }
//        std::cout<<std::endl;
    //}
   
    inputFile.close();
    
    return 0;
}

