/*
 Program Name: Week12Lab.cpp
 Programmer: Kevin Fischer
 Date: 5-16-26
 Version: 1.0
 The point of this program is to create
 a binary tree that has nodes containing
 objects from the PartInfo class. The user
 inputs a part number to search for and the
 program says whether or not it found the part
 */

// Implementation file for the IntBinaryTree class
#include <iostream>
using namespace std;

class PartInfo
{
    private:
        int partid;
        string partname;
    
    public:
        PartInfo()
        {
            partid = 0;
            partname = "";
        }
    
        PartInfo(int pid, string pn)
        {
            partid = pid;
            partname = pn;
        }
    
        int getID()
        {
            return partid;
        }
    
        string getName()
        {
            return partname;
        }
};

class IntBinaryTree
{
    private:
        struct TreeNode
        {
            PartInfo part; // The value in the node
            TreeNode *left; // Pointer to left child node
            TreeNode *right; // Pointer to right child node
        };
        
        TreeNode *root; // Pointer to the root node
        
        // Private member functions
        void insert(TreeNode *&, TreeNode *&);
        void destroySubTree(TreeNode *);
        void deleteNode(int, TreeNode *&);
        void makeDeletion(TreeNode *&);
        void displayInOrder(TreeNode *) const;
        void displayPreOrder(TreeNode *) const;
        void displayPostOrder(TreeNode *) const;

    public:
        // Constructor
        IntBinaryTree()
        {
            root = nullptr;
        }
    
        // Destructor
        ~IntBinaryTree()
        {
            destroySubTree(root);
        }
    
        // Binary tree operations
        void insertNode(PartInfo);
        bool searchNode(int);
        void remove(int);
        void displayInOrder() const
        {
            displayInOrder(root);
        }
        void displayPreOrder() const
        {
            displayPreOrder(root);
        }
        void displayPostOrder() const
        {
            displayPostOrder(root);
        }
};

//*************************************************************
// insert accepts a TreeNode pointer and a pointer to a node. *
// The function inserts the node into the tree pointed to by *
// the TreeNode pointer. This function is called recursively. *
//*************************************************************

void IntBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
    if (nodePtr == nullptr)
        nodePtr = newNode; // Insert the node.
    else if (newNode->part.getID() < nodePtr->part.getID())
        insert(nodePtr->left, newNode); // Search the left branch
    else
        insert(nodePtr->right, newNode); // Search the right branch
}

//**********************************************************
// insertNode creates a new node to hold num as its value, *
// and passes it to the insert function. *
//**********************************************************

void IntBinaryTree::insertNode(PartInfo p)
{
    TreeNode *newNode = nullptr; // Pointer to a new node.
    
    // Create a new node and store num in it.
    newNode = new TreeNode;
    newNode->part = p;
    newNode->left = newNode->right = nullptr;
    
    // Insert the node.
    insert(root, newNode);
}

//***************************************************
// destroySubTree is called by the destructor. It *
// deletes all nodes in the tree. *
//***************************************************

void IntBinaryTree::destroySubTree(TreeNode *nodePtr)
{
    if (nodePtr)
    {
        if (nodePtr->left)
            destroySubTree(nodePtr->left);
        if (nodePtr->right)
            destroySubTree(nodePtr->right);
        delete nodePtr;
    }
}

//***************************************************
// searchNode determines if a value is present in *
// the tree. If so, the function returns true. *
// Otherwise, it returns false. *
//***************************************************

bool IntBinaryTree::searchNode(int num)
{
    TreeNode *nodePtr = root;
    
    while (nodePtr)
    {
        if (nodePtr->part.getID() == num)
        {
            cout << "Part found!: " << nodePtr->part.getID() << " " << nodePtr->part.getName() << endl;
            return true;
        }
        else if (num < nodePtr->part.getID())
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }
    
    return false;
}

//**********************************************
// remove calls deleteNode to delete the *
// node whose value member is the same as num. *
//**********************************************

void IntBinaryTree::remove(int num)
{
    deleteNode(num, root);
}

//********************************************
// deleteNode deletes the node whose value *
// member is the same as num. *
//********************************************
void IntBinaryTree::deleteNode(int num, TreeNode *&nodePtr)
{
    if (num < nodePtr->part.getID())
        deleteNode(num, nodePtr->left);
    else if (num > nodePtr->part.getID())
        deleteNode(num, nodePtr->right);
    else
        makeDeletion(nodePtr);
}

//***********************************************************
// makeDeletion takes a reference to a pointer to the node *
// that is to be deleted. The node is removed and the *
// branches of the tree below the node are reattached. *
//***********************************************************

void IntBinaryTree::makeDeletion(TreeNode *&nodePtr)
{
    // Define a temporary pointer to use in reattaching
    // the left subtree.
    TreeNode *tempNodePtr = nullptr;
    if (nodePtr == nullptr)
        cout << "Cannot delete empty node.\n";
    else if (nodePtr->right == nullptr)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left; // Reattach the left child
        delete tempNodePtr;
    }
    else if (nodePtr->left == nullptr)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right; // Reattach the right child
        delete tempNodePtr;
    }
    // If the node has two children.
    else
    {
        // Move one node the right.
        tempNodePtr = nodePtr->right;
        // Go to the end left node.
        while (tempNodePtr->left)
            tempNodePtr = tempNodePtr->left;
        // Reattach the left subtree.
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;
        // Reattach the right subtree.
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
}

//****************************************************************
// The displayInOrder member function displays the values *
// in the subtree pointed to by nodePtr, via inorder traversal. *
//****************************************************************

void IntBinaryTree::displayInOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        displayInOrder(nodePtr->left);
        cout << nodePtr->part.getID() << " " << nodePtr->part.getName() << endl;
        displayInOrder(nodePtr->right);
    }
}

//****************************************************************
// The displayPreOrder member function displays the values *
// in the subtree pointed to by nodePtr, via preorder traversal. *
//****************************************************************
void IntBinaryTree::displayPreOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        cout << nodePtr->part.getID() << " " << nodePtr->part.getName() << endl;
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}

//****************************************************************
// The displayPostOrder member function displays the values *
// in the subtree pointed to by nodePtr, via postorder traversal.*
//****************************************************************
void IntBinaryTree::displayPostOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->part.getID() << " " << nodePtr->part.getName() << endl;
    }
}

//Driver class
// This program builds a binary tree with 5 nodes.
// The nodes are displayed with inorder, preorder,
// and postorder algorithms.
#include <iostream>

using namespace std;

int main()
{
    IntBinaryTree tree;
    int partnum;
    
    PartInfo p1 = PartInfo(1042, "Motherboard");
    tree.insertNode(p1);
    PartInfo p2 = PartInfo(1078, "CPU");
    tree.insertNode(p2);
    PartInfo p3 = PartInfo(2508, "Power Supply");
    tree.insertNode(p3);
    PartInfo p4 = PartInfo(3780, "Modem");
    tree.insertNode(p4);
    PartInfo p5 = PartInfo(1038, "RAM");
    tree.insertNode(p5);
    PartInfo p6 = PartInfo(1287, "Graphic Card");
    tree.insertNode(p6);
    PartInfo p7 = PartInfo(1920, "Hard Disk");
    tree.insertNode(p7);
    PartInfo p8 = PartInfo(4239, "USB Port");
    tree.insertNode(p8);
    
    cout << "Enter part number to search for: ";
    cin >> partnum;
    
    if (!tree.searchNode(partnum))
        cout << "Part is not found\n";
    
    return 0;
}
