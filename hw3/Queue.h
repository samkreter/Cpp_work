/* 
 * File:   Queue.h
 * Author: kreter
 *
 * Created on October 8, 2014, 9:20 PM
 */

#ifndef QUEUE_H
#define	QUEUE_H

#include "Node.h"



class QueueNode: public Node{
public:
    QueueNode(int data, int distance);
    void setDistance(int distance);
    int getDistance();
    void setNext(QueueNode* n);
    QueueNode* getNext();
private:
    int distance;
    QueueNode* next;
 
};

class Queue {
public:
    Queue();
    void enqueue(int data, int distance);
    QueueNode* dequeue();
    int isEmpty();
    void setTail(QueueNode* n);
    QueueNode* getTail();
    QueueNode* getHead();
    
    virtual ~Queue();
private:
    QueueNode* head = NULL;
    QueueNode* tail = NULL;
    struct DataStruct{
        int value;
        int distance;
    };

};



#endif	/* QUEUE_H */

