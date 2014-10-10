/* 
 * File:   Stack.h
 * Author: kreter
 *
 * Created on October 9, 2014, 11:11 PM
 */

#ifndef STACK_H
#define	STACK_H

#include "Node.h"

class Stack {
public:
    Stack();
    void setSize(int size);
    int getSize();
    void push(int data);
    Node* pop();
    Node* top();
    void setHead(Node* n);
    Node* getHead();
    int isEmpty();
    Stack(const Stack& orig);
    virtual ~Stack();
private:
    int size;
    Node* head;

};

#endif	/* STACK_H */

