/* 
 * File:   GraphList.h
 * Author: kreter
 *
 * Created on October 7, 2014, 4:50 PM
 */

#ifndef GRAPHLIST_H
#define	GRAPHLIST_H

#include "List.h"

class GraphList {
public:
    GraphList(int numOfNodes);
    virtual ~GraphList();
    void setNumOfNodes(int numOfNodes);
    int getNumOfNodes();
    void addEdge(int edge1, int edge2);
    void printGraph();
    void BFS(int start);
    void DFSUtil(int v, bool visited[]);
    void DFS(int v);
    
private:
     int numOfNodes;
     List** graphlist;

};

#endif	/* GRAPHLIST_H */

