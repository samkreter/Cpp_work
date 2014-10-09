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

void Queue::enqueue(int data, int distance){
    if(this->head == NULL){
        this->head = new QueueNode(data,distance);
        this->tail = this->head;
    }
    else{
        this->tail->setNext(new QueueNode(data,distance));
        this->tail = this->tail->getNext();
    }
}

QueueNode* Queue::dequeue(){
    if(head != NULL){
        QueueNode* q = this->head;
        QueueNode* temp = this->head;
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

QueueNode* Queue::getTail(){
    return this->tail;
}

void Queue::setTail(QueueNode* n){
    this->tail = n;
}

Queue::~Queue() {
}


QueueNode::QueueNode(int data, int distance):Node(data){
    this->distance = distance;
}

void QueueNode::setDistance(int distance){
    this->distance = distance;
}

int QueueNode::getDistance(){
    return this->distance;
}

void QueueNode::setNext(QueueNode* n){
    this->next = n;
}

QueueNode* QueueNode::getNext(){
    return this->next;
}





