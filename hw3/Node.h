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
    void setNext(Node *);
    Node* getNext();
    void setData(int data);
    int getData();
    virtual ~Node();
protected:
    Node* next;
    int data;

    

};

#endif	/* NODE_H */

