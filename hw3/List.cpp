/* 
 * File:   List.cpp
 * Author: kreter
 * 
 * Created on October 7, 2014, 5:22 PM
 */

#include<iostream>
#include "Node.h"
#include "List.h"





List::List() {
    this->head = NULL;
}

void List::add(int data){
    Node* n = new Node(data);
    Node* temp = NULL;
    if(this->head == NULL){
        this->head = n;
    }
    else{
        temp = head->getNext();
        head->setNext(n);
        n->setNext(temp);
    }
}

void List::printList(){
    Node* curr = head;
    while(curr->getNext() != NULL){
        std::cout<<curr->getData()<<" ";
    }
    std::cout<<std::endl;
}



List::~List() {
    Node *curr = head;
    Node* temp = NULL;
    while(curr->getNext() != NULL){
        temp = curr;
        curr = curr->getNext();
        delete(temp);
    }
    
    delete(curr);
    
}

