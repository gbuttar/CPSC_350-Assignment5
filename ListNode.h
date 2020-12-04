#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>

using namespace std;

template <class T>
class ListNode{
public:
  ListNode();
  ListNode(T elem);
  ~ListNode();

  T data;
  ListNode<T> *next;
  ListNode<T> *prev;
};

template <class T>
ListNode<T>::ListNode(){
}

template <class T>
ListNode<T>::ListNode(T elem){
  data = elem;
  next = NULL;
  prev = NULL;
}

template <class T> //deconstructor
ListNode<T>::~ListNode(){
  next = NULL;
  prev = NULL;
}

#endif
