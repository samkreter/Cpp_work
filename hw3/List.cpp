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
    Node* curr = NULL;
    if(head != NULL){
        curr = head;
    }
    else{
        std::cout<<"->NULL";
        return;
    }
 
    while(curr->getNext() != NULL){
        std::cout<<curr->getData()<<"->";
        curr = curr->getNext();
    }
    std::cout<<curr->getData()<<"->NULL";
 
}

Node* List::getHead(){
    return this->head;
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

