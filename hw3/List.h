/* 
 * File:   List.h
 * Author: kreter
 *
 * Created on October 7, 2014, 5:22 PM
 */

#ifndef LIST_H
#define	LIST_H

#include "Node.h"

class List {
public:
    List();
    void add(int data);
    void printList();
    Node* getHead();
    virtual ~List();
private:
    Node* head;

};

#endif	/* LIST_H */

