#include iostream
using namespace std;

template class<T>
class TreeNode{
public:
  TreeNode();
  TreeNode(T k);
  ~TreeNode();

  T key;
  TreeNode *right;
  TreeNode *left;

};

template<class T>
TreeNode<T>::TreeNode(){
  left = NULL;
  right = NULL;
}

template<class T>
TreeNode<T>::TreeNode(T k){
  key = k;
  left = NULL;
  right = NULL;
}

template<class T>
TreeNode<T>::~TreeNode(){
}

#endif
