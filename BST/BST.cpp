#include <iostream>
#include "BST.h"
#include "BinNode.h"
//#include <iomanip>

using namespace std;

int nodes[100];
//--- Definition of constructor
BST::BST()
: myRoot(0)
{}

bool BST::empty() const
{ return myRoot == 0; }


bool BST::search(const int & item) const
{
   BinNode * locptr = myRoot;
   bool found = false;
   while (!found && locptr != 0)
   {
      if (item < locptr->data)       // descend left
        locptr = locptr->left;
      else if (locptr->data < item)  // descend right
        locptr = locptr->right;
      else                           // item found
        found = true;
   }
   return found;
}

void BST::preorder(BinNode * node) {
   if (node != NULL) {
      cout << node->data <<" ";
      preorder(node->left);
      preorder(node->right);
   }
}

void BST::inorder(BinNode * node) {
   if (node != NULL) {
      inorder(node->left);
      cout << node->data <<" ";
      nodes[ctr] = node->data;
      ctr++;
      inorder(node->right);
   }
}


BinNode * minValueNode(BinNode* node){
   BinNode* current = node;
   while (current && current->left != NULL)
      current = current->left;
   return current;
}

BinNode* BST::deleteNode(BinNode* root, int key) { 
    if (root == NULL) return root; 
  
    
    if (key < root->data) 
        root->left = deleteNode(root->left, key); 
  
    else if (key > root->data) 
        root->right = deleteNode(root->right, key); 
  
    else
    { 
        if (root->left == NULL) 
        { 
            BinNode *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            BinNode *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        BinNode* temp = minValueNode(root->right); 
  
        root->data = temp->data; 
  
        root->right = deleteNode(root->right, temp->data); 
    } 
    return root; 
} 


int BST::nodeCount(BinNode * node, int &count){
    if (node != NULL) {
      nodeCount(node->left, count);
      count += 1;
      nodeCount(node->right, count);
   }
   return count;
}


void BST::insert(const int & item)
{
   BinNode * locptr = myRoot;   // search pointer
   BinNode * parent = 0;        // pointer to parent of current node
   bool found = false;     // indicates if item already in BST
   while (!found && locptr != 0)
   {
      parent = locptr;
      if (item < locptr->data)       // descend left
         locptr = locptr->left;
      else if (locptr->data < item)  // descend right
         locptr = locptr->right;
      else                           // item found
         found = true;
   }
   if (!found)
   {                                 // construct node containing item
      locptr = new BinNode(item);  
      if (parent == 0)               // empty tree
         myRoot = locptr;
      else if (item < parent->data )  // insert to left of parent
         parent->left = locptr;
      else                           // insert to right of parent
         parent->right = locptr;
   }
   else
      cout << "Item already in the tree\n";
}
