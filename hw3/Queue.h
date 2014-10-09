/* 
 * File:   Queue.h
 * Author: kreter
 *
 * Created on October 8, 2014, 9:20 PM
 */

#ifndef QUEUE_H
#define	QUEUE_H




class Queue {
public:
    Queue();
    void enqueue(int data, int distance);
    Node* dequeue();
    int isEmpty();
    void setTail(Node* n);
    Node* getTail();
    Node* getHead();
    
    virtual ~Queue();
private:
    Node* head = NULL;
    Node* tail = NULL;

};



#endif	/* QUEUE_H */

