/* 
 * File:   Queue.cpp
 * Author: kreter
 * 
 * Created on October 8, 2014, 9:20 PM
 */
#include<iostream>
#include "Node.h"
#include "Queue.h"

Queue::Queue() {
    this->head = NULL;
    setTail(NULL);
}

void Queue::enqueue(int data){
    if(this->head == NULL){
        this->head = new Node(data);
        this->tail = this->head;
    }
    else{
        this->tail->setNext(new Node(data));
        this->tail = this->tail->getNext();
    }
}

Node* Queue::dequeue(){
    if(head != NULL){
        Node* q = this->head;
        Node* temp = this->head;
        if(this->head->getNext() != NULL){
            this->head = this->head->getNext();
        }
        else{
            this->head = NULL;
        }
        delete(temp);
        temp = NULL;
        return q;
    }
    std::cout<<"Error: Queue is empty";
    return 0;
}

int Queue::isEmpty(){
    if(head == NULL){
        return 0;
    }
    else{
        return 1;
    }
}

Node* Queue::getTail(){
    return this->tail;
}

void Queue::setTail(Node* n){
    this->tail = n;
}

Queue::~Queue() {
}




