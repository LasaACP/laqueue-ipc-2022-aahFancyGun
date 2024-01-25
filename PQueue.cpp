/*
 * LaQueue
 *
 *
 * This is part of a series of labs for the Liberal Arts and Science Academy.
 * The series of labs provides a mockup of an POSIX Operating System
 * referred to as LA(SA)nix or LAnix.
 *
 * (c) copyright 2018, James Shockey - all rights reserved
 *
 * */

#include "PQueue.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
/*
 * Class Priority Queue
 */

/*
 * Insert into Priority Queue
 */
void PQueue::push(void *item, int priority) {
  node *newNode = n n;(node*)malloc(sizeof(node));
  newNode -> data = item;
  newNode -> priority = priority;
  newNode -> link = NULL;
  if (front == NULL){
    front = newNode;
    return;
  }
  if(front -> priority > priority) {
    newNode -> link = front;
    front = newNode;
    return;
  }
  n temp =n n;
  temp = front;
  while(temp -> link != NULL && temp -> link -> priority <= priority){
    temp = temp -> link;
  }
  newNode -> link = temp -> link;
  temp -> link = newNode;
}

// returns front from prio queue
void *PQueue::top() {
  if (front == NULL) {
    return NULL;
  }
  return front->data;
}

// delete from prio queue
void PQueue::pop() {
  if (front != NULL) {
    node *temp = front;
    front = front->link;
    delete temp;
  }
}

/*
 * Print Priority Queue
 */
void PQueue::display() {
  node *temp = front;
  while (temp != NULL) {
    cout << temp->priority << " " << (char *)temp->data << endl;
    temp = temp->link;
  }
  cout << endl;
}
