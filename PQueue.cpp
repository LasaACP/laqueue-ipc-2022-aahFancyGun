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

#define minPrio 1000000000

/*
 * Class Priority Queue
 */

/*
 * Insert into Priority Queue
 */
void PQueue::push(void *item, int priority) {
  node *newNode = new node;
  newNode->data = item;
  newNode->priority = priority;
  newNode->link = nullptr;
  node *temp = front;

  if (front == nullptr) {
    front = newNode;
    return;
  }
  while (temp->link != nullptr) {
    if (temp->link->priority > priority) {
      node *temp2 = temp->link;
      temp->link = newNode;
      newNode->link = temp2;
      return;
    }
    temp = temp->link;
  }
  temp->link = newNode;
}

//returns front from prio queue
void *PQueue::top() {
  if (front == nullptr) {
    return nullptr;
  }
  return front;
}

//delete from prio queue
void PQueue::pop() {
  node *temp = front;
  if (front != nullptr && front->link != nullptr) {
    front = front->link;
  }
}

/*
 * Print Priority Queue
 */
void PQueue::display() {
  node *temp = front;
  while (temp != nullptr) {
    cout << temp->priority << " " << (char *)temp->data << endl;
    if (temp->link != nullptr) {
      temp = temp->link;
    } else {
      break;
    }
  }
}
