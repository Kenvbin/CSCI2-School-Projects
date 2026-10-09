/*
 Program Name: Week13HW.cpp
 Programmer: Kevin Fischer
 Date: 5-23-26
 Version: 1.0
 The point of this program is to write a
 member function that counts and returns the
 number of nodes in the tree and then i need
 to write a member function that counts and returns the number of
 leaf nodes in a tree
 */

#include <iostream>
using namespace std;

class IntBinaryTree
{
    private:
        struct TreeNode
        {
            int value; // The value in the node
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
        int countNodes(TreeNode *) const;
        int countLeafNodes(TreeNode *) const;

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
        void insertNode(int);
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
        int countNodes() const
        {
            return countNodes(root);
        }
        int countLeafNodes() const
        {
            return countLeafNodes(root);
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
    else if (newNode->value < nodePtr->value)
        insert(nodePtr->left, newNode); // Search the left branch
    else
        insert(nodePtr->right, newNode); // Search the right branch
}

//**********************************************************
// insertNode creates a new node to hold num as its value, *
// and passes it to the insert function. *
//**********************************************************

void IntBinaryTree::insertNode(int num)
{
    TreeNode *newNode = nullptr; // Pointer to a new node.
    
    // Create a new node and store num in it.
    newNode = new TreeNode;
    newNode->value = num;
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
        if (nodePtr->value == num)
        {
            return true;
        }
        else if (num < nodePtr->value)
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
    if (nodePtr == nullptr)
        return;
    else if (num < nodePtr->value)
        deleteNode(num, nodePtr->left);
    else if (num > nodePtr->value)
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
        cout << nodePtr->value << endl;
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
        cout << nodePtr->value << endl;
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
        cout << nodePtr->value << endl;
    }
}

int IntBinaryTree::countNodes(TreeNode *nodePtr) const
{
    if (nodePtr == nullptr)
        return 0;

    return 1 + countNodes(nodePtr->left) + countNodes(nodePtr->right);
}

int IntBinaryTree::countLeafNodes(TreeNode *nodePtr) const
{
    if (nodePtr == nullptr)
        return 0;

    if (nodePtr->left == nullptr && nodePtr->right == nullptr)
        return 1;

    return countLeafNodes(nodePtr->left) + countLeafNodes(nodePtr->right);
}

//Driver class
int main()
{
    IntBinaryTree tree;
    int num;
    
    tree.insertNode(1042);
    tree.insertNode(1078);
    tree.insertNode(2508);
    tree.insertNode(3780);
    tree.insertNode(1038);
    tree.insertNode(1287);
    tree.insertNode(1920);
    tree.insertNode(4239);
    
    cout << "Inorder traversal:" << endl;
    tree.displayInOrder();

    cout << "Total number of nodes: " << tree.countNodes() << endl;
    cout << "Total number of leaf nodes: " << tree.countLeafNodes() << endl;
    
    cout << "Enter number to search for: ";
    cin >> num;
    
    if (tree.searchNode(num))
        cout << "Number is found" << endl;
    else
        cout << "Number is not found" << endl;
    
    return 0;
}
