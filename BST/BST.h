#include <iostream>
#include "BinNode.h"
using namespace std;
//using std::vector;  

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

class BST
{
 public:
  /***** Data Members *****/
  BinNode * myRoot; 

  /***** Function Members *****/
  BST();
  
  public:
  bool empty() const;
  bool search(const int & item) const; 
  void insert(const int & item);
  
  void preorder(BinNode * myRoot);
  void inorder(BinNode * node);
  int nodeCount(BinNode * node, int &count);
  BinNode* deleteNode(BinNode* root, int key);

}; // end of class declaration
static int ctr = 0;
#endif
