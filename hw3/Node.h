/* 
 * File:   Node.h
 * Author: kreter
 *
 * Created on October 7, 2014, 4:55 PM
 */

#ifndef NODE_H
#define	NODE_H

class Node {
public:
    Node(int data);
    void setDistance(int distance);
    int getDistance();
    void setNext(Node* n);
    void setVisited(int b);
    int getVisited();
    void setData(int data);
    int getData();
    Node* getNext();
    virtual ~Node();
private:
    int distance;
    int visited;
    Node* next;
    int data;

    

};

#endif	/* NODE_H */

