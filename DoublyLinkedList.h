#include <iostream>
#include <fstream>
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "ListNode.h"

using namespace std;

template <class T>
class DoublyLinkedList{
public:
  ListNode<T> *front;
  ListNode<T> *back;
  unsigned int size;

  DoublyLinkedList();
  ~DoublyLinkedList();

  void insertBack(T elem);
  ListNode<T>* getFront();
  T removeFront();

  void deletePos(int p);
  T returnPos(int p);
  void printList();
  bool isEmpty();
  bool find(T elem);
  unsigned int getSize();
}

template<class T> //constructor
DoublyLinkedList<T>::DoublyLinkedList(){
  size = 0;
  front = NULL;
  back = NULL;
}

template <class T> //deconstructor
DoublyLinkedList<T>::~DoublyLinkedList(){
}

template <class T> //insert at back
void DoublyLinkedList<T>::insertBack(T elem){
  ListNode<T> *node = new ListNode<T>(elem);
  if(size ==0){
    front = node;
  }
  else{
    back->next = node;
    node->prev = back;
  }
  back = node;
  ++size;
}

template <class T> //get front
ListNode<T>* DoublyLinkedList<T>::getFront(){
  return front;
}

template <class T> //remove front
T DoublyLinkedList<T>::removeFront(){
  if(!isEmpty()){
    ListNode<T> *node = front;

    if(front->next == NULL){
      front = NULL;
      back = NULL;
    }
    else{
      front->next->prev = NULL;
      front = front->next;
    }

    T temp = node->data;
    delete node;
    size;
    return temp;
  }
  else{
    return T();
  }
}

template <class T> //delete
void DoublyLinkedList<T>::deletePos(int p){
  p--;
  int index = 0;
  ListNode<T> *curr = front;
  ListNode<T> *prev = front;

  while(index != pos){
    prev = curr;
    curr = curr->next;
    index++
  }

  prev->next = curr->next;
  curr->next->prev-> = prev;
  curr->next = NULL;

  size--;
  delete curr;
}

template <class T> //returns the postion
T DoublyLinkedList<T>::returnPos(int p){
  ListNode<T> *curr = front;
  for(int i =0; i <=pos; i++){
    if(i == pos){
      return curr->data;
    }
    curr = curr->next;
  }
  return curr->data;
}

template <class T> //prints thel ist
void DoublyLinkedList<T>::printList(){
  ListNode<T> *curr = front;
  while(curr != NULL){
    cout<<curr->data<<endl;
    if(curr == back){
      break;
    }
    else{
      curr = curr->next;
    }
  }
}

template <class T> //searches and finds element
bool DoublyLinkedList<T>::find(T elem){
  ListNode<T> *curr = front;
  while(curr != NULL){
    if(elem == curr->data){
      return true;
    }
    curr = curr->next;
  }
  return false;
}

template <class T> //checks if empty
boo DoublyLinkedList<T>::isEmpty(){
  return(size == 0);
}

template <class T> //gets the size
unsigned int DoublyLinkedList<T>::getSize(){
  return size;
}

#endif
