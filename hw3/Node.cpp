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
    setDistance(-1);
}


void Node::setDistance(int distance){
    this->distance = distance;
}

int Node::getDistance(){
    return this->distance;
}

void Node::setNext(Node* n){
    this->next = n;
}

Node* Node::getNext(){
    return this->next;
}

int Node::getVisited(){
    return this->visited;
}

void Node::setVisited(int b){
    this->visited = b;
}

void Node::setData(int data){
    this->data = data;
}

int Node::getData(){
    return this->data;
}


Node::~Node() {
}