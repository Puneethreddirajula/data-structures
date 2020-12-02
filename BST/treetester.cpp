/*----- treetester.cpp -----------------------------------------------------
                Program for testing BST.
 ------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

#include "BST.h"

int main()
{
   // Testing Constructor and empty()
   BST intBST;            // test the class constructor
   cout << "Constructing empty BST\n";
   cout << "BST " << (intBST.empty() ? "is" : "is not") << " empty\n";

   std::cout << "testing parameterized constructor: " << std::endl;
   intBST.inorder(intBST.myRoot);

   // Testing insert
   cout << "\nNow insert a bunch of integers into the BST."
           "\nTry items not in the BST and some that are in it:\n";
   int number;
   for (;;)
   {
      cout << "Item to insert (-999 to stop): ";
      cin >> number;
      if (number == -999) break;
      intBST.insert(number);
   }
   cout << "BST " << (intBST.empty() ? "is" : "is not") << " empty\n";

   //Testing search()
   cout << "\n\nNow testing the search() operation."
           "\nTry both items in the BST and some not in it:\n";
   for (;;)
   {
      cout << "Item to find (-999 to stop): ";
      cin >> number;
      if (number == -999) break;
      cout << (intBST.search(number) ? "Found" : "Not found") << endl;
   }
   std::cout << std::endl;
   std::cout << "preorder: ";
   intBST.preorder(intBST.myRoot);
   std::cout << std::endl;
   std::cout << "\ninorder: " ;
   intBST.inorder(intBST.myRoot);
   std::cout << std::endl;
   int total = 0;
   int& count = total;
   intBST.nodeCount(intBST.myRoot, count);
   std::cout << std::endl;
   std::cout << "Number of Nodes: " << count << std::endl;
   std::cout << std::endl;
   


   int n;
   std::cout << "enter number of values to delete";
   std::cin >> n;
   for (int i = 0; i < n; i++)
   {
      int key;
      std::cout << "enter node to delete: ";
      std::cin >> key;
      std::cout << std::endl;
      intBST.deleteNode(intBST.myRoot, key);
      std::cout << "Inorder: ";
      intBST.inorder(intBST.myRoot);
      std::cout << std::endl << std::endl;
   }



}
