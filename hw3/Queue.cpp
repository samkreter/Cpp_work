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

Node* Queue::look(){
    return this->head;
}

void Queue::enqueue(int data, int distance){
    this->size++;
    if(this->head == NULL){
        this->head = new Node(data);
        this->head->setDistance(distance);
        this->tail = this->head;
    }
    else{
        this->tail->setNext(new Node(data));
        this->tail = this->tail->getNext();
        this->tail->setDistance(distance);
    }
}

Node* Queue::dequeue(){
    if(this->head != NULL){
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
        this->size--;
        return q;
    }
    std::cout<<"Error: Queue is empty";
    return 0;
}

int Queue::isEmpty(){
    if(head == NULL){
        return 1;
    }
    else{
        return 0;
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




