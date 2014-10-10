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
    std::string file;
    
    std::cout<<"Enter the file name"<<std::endl;
    std::cin>>file;
    ifstream inputFile(file);
   
    if(inputFile.is_open()){
        inputFile>>numOfNodes;
    }
    else{
        cout<<"error reading the file";
    }
    graph = new GraphList(numOfNodes + 1);
    graphTrans = new GraphList(numOfNodes + 1);
   
    
    while(!inputFile.eof()){
       // if(counter < graph->getNumOfNodes()){          
            inputFile>>parseString;
            edge1 = atoi(parseString.substr(1, parseString.find(",")).c_str());
            edge2 = atoi(parseString.substr(parseString.find(",")+1,parseString.length()-1).c_str());
            graph->addEdge(edge1,edge2);
            graphTrans->addEdge(edge2,edge1);
            counter++;
        //}
        //else{break;}

    }
    
    
    
   
   graph->printGraph();

    
   //bulding the stack to test the connected componets 
    Stack* q;
    Stack* t;
    graph->BFS(1);
    q = graph->DFS(1);
    //creating the place holder for whats on the stack to test in the reverse graph
    int size = q->getSize();
    int* holder = new int[size];
    /*
    for(int i; i<size; i++){
        holder[i] = q->pop()->getData();
        std::cout<<holder[i]<<" ";
    }
    
    std::cout<<std::endl;
     t = graphTrans->DFS(holder[0]);
     //get the data from the stack 
     while(!t->isEmpty()){
         std::cout<<t->pop()->getData()<<" ";
     }
     */
    //close the file 
    inputFile.close();
    
    return 0;
}

