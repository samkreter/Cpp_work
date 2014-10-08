/* 
 * File:   Node.cpp
 * Author: kreter
 * 
 * Created on October 7, 2014, 4:55 PM
 */

#include<iostream>
#include "Node.h"


Node::Node(int data) {
    setData(data);
    setNext(NULL);
}


void Node::setNext(Node* n){
    this->next = n;
}

Node* Node::getNext(){
    return this->next;
}

void Node::setData(int data){
    this->data = data;
}

int Node::getData(){
    return this->data;
}


Node::~Node() {
}

