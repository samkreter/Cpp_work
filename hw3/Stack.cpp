/* 
 * File:   Stack.cpp
 * Author: kreter
 * 
 * Created on October 9, 2014, 11:11 PM
 */

#include<iostream>

#include "Stack.h"
#include "Node.h"


Stack::Stack() {
    this->head = NULL;
    this->size = 0;
}

Node* Stack::top(){
    return this->head;
   
}

void Stack::push(int data){
    this->size++;
    if(this->head == NULL){
        this->head = new Node(data);
    }
    else{
        Node* temp = new Node(data);
        temp->setNext(this->head);
        this->head->setNext(temp);
    }
}

Node* Stack::pop(){
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

int Stack::isEmpty(){
    if(this->size == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int Stack::getSize(){
    return this->size;
}

void Stack::setHead(Node* n){
    this->head = n;
}

Node* Stack::getHead(){
    return this->head;
}

Stack::~Stack() {
}

