#include <iostream>
#include "TreeNode.h"
#include "Person.h"

using namespace std;

template <class T>
class BST{
public:
  BST();
  ~BST();

  void insert(T data);
  T find(int num);
  bool contains(T data);
  bool deleteNode(T data);
  bool isEmpty();

  void deleteT(TreeNode<T> *node);

  TreeNode<T> *getMin();
  TreeNode<T> *getMax();
  TreeNode<T> *getRoot();
  TreeNode<T>* getSuccessor(TreeNode<T> *d);

private:
  TreeNode<T> *root;
};

template <class T> //constuctor
BST<T>::BST(){
  root = NULL;
}

template <class T> //deconstructor
BST<T>::~BST(){
  deleteT(root);
}

template <class T> //delets
void BST<T>::deleteT(TreeNode<T> *node){
  if(node){
    deleteT(node->left);
    deleteT(node->right);
    delete node;
  }
}

template <class T> //gets the root
TreeNode<T>* BST<T>::getRoot(){
  return root;
}

template <class T>
TreeNode<T>* BST<T>::getMin(){
  TreeNode<T> *curr = root;
  if (root == NULL){
    return NULL;
  }
  while(curr->left !=NULL){
    curr = curr->left;
  }
  return curr;
}

template <class T>
TreeNode<T>* BST<T>::getMax(){
  TreeNode<T> *curr = root;
  if (root == NULL){
    return NULL;
  }
  while(curr->right !=NULL){
    curr = curr->right;
  }
  return curr;
}


template <class T> //insert
void BST<T>::insert(T data){
  TreeNode<T> *node = new TreeNode<T>(data);
  if(root == NULL){
    root = node;
  }
  else{
    TreeNode<T> *curr = root;
    TreeNode<T> *parent = NULL;
    while(true){
      parent = curr;
      int a1 = data.getId();
      int a2 = curr->key.getId();
      if(a1<a2){
        curr = curr->left;
        if(curr ==  NULL){
          parent->left = node;
          break;
        }
      }
      else{
        curr = curr -> right;
        if(curr = NULL){
          parent->right=node;
          break;
        }
      }
    }
  }
}

template <class T> //searches
bool BST<T>::contains(T data){
  if(root = NULL){
    return false;
  }
  else{
    TreeNode<T> *curr = root;
    while(curr !=NULL){
      if(current == NULL){
        return false;
      }
      if(data.getId() < curr->key.getId()){
        curr = curr->left;
      }
      else if(data.getId() < curr->key.getId()){
        return true;
      }
      else{
        curr = curr->right;
      }
    }
  }

template <class T> //gets successor 
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d){
  TreeNode<T> *current = d->right;
  TreeNode<T> *sParent = d;
  TreeNode<T> *successor = d;
  while(current != NULL){
    sParent = successor;
    successor = current;
    current = current->left;
  }
  if(successor !=d->right){
    sParent->left = successor->right;
    successor->right = d->right;
  }
  return successor;
}

#endif
