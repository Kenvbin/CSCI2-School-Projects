/*
 Program Name: Week14HW.cpp
 Programmer: Kevin Fischer
 Date: 5-29-26
 Version: 1.0
 The goal of this program to make a library
 with a collection of books and it should be able
 to store the title, author, ISBN, and its availability
 */

#include <iostream>
#include <string>
using namespace std;

class BookInfo
{
    private:
        
        int ISBN;
        string title, author;
        bool availability;
    
    public:
    
        BookInfo()
        {
            ISBN = 0;
            title = "";
            author = "";
            availability = false;
        }
    
        BookInfo(int num, string name, string a, bool avail)
        {
            ISBN = num;
            title = name;
            author = a;
            availability = avail;
        }
    
        int getISBN()
        {
            return ISBN;
        }
    
        string getTitle()
        {
            return title;
        }
    
        bool getAvailability()
        {
            return availability;
        }
};

class Book
{
    private:
        
        struct TreeNode
        {
            BookInfo book;
            TreeNode *left;
            TreeNode *right;
        };
    
        TreeNode *root;
    
    public:
    
        Book()
        {
            root = nullptr;
        }
    
        void insert(TreeNode *&nodePtr, TreeNode *&newNode)
        {
           if(nodePtr == nullptr)
               nodePtr = newNode;
           else if (newNode -> book.getISBN() < nodePtr -> book.getISBN())
                insert(nodePtr -> left, newNode);
           else
               insert(nodePtr -> right, newNode);
        }
    
        void addBook(BookInfo p)
        {
            TreeNode *newNode = nullptr;
            newNode = new TreeNode;
            newNode -> book = p;
            newNode -> left = newNode -> right = nullptr;
            insert(root, newNode);
        }
    
        bool searchBook(int num)
        {
            TreeNode *nodePtr = root;
            
            while (nodePtr)
            {
                if (nodePtr -> book.getISBN() == num)
                {
                    cout << "Book found!: " << nodePtr -> book.getISBN() << " " << nodePtr -> book.getTitle() << endl;
                    return nodePtr -> book.getAvailability();
                }
                else if (num < nodePtr -> book.getISBN())
                    nodePtr = nodePtr -> left;
                else
                    nodePtr = nodePtr -> right;
            }
            cout << "Book not found!\n";
            return false;
        }
    
        void makeDeletion(TreeNode *&nodePtr)
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

    
        void remove(int num, TreeNode *&nodePtr)
        {
            if (nodePtr == nullptr)
            {
                cout << "Book not found.\n";
                return;
            }
            
            if (num < nodePtr -> book.getISBN())
               remove(num, nodePtr -> left);
            else if (num > nodePtr -> book.getISBN())
                remove(num, nodePtr -> right);
            else
                makeDeletion(nodePtr);
        }
    
        void removeBook(int num)
        {
            remove(num, root);
        }
};

int main()
{
    Book list;
    
    BookInfo b1(1111, "Harry Potter", "J.K. Rowling", true);
    BookInfo b2(2222, "The Lord of the Rings", "J. R. R. Tolkien", false);
    BookInfo b3(3333, "If You Give a Mouse a Cookie", "Laura Numeroff", true);
    BookInfo b4(4404, "The Cat in the Hat", "Dr. Seuss", true);
    
    list.addBook(b1);
    list.addBook(b2);
    list.addBook(b3);
    list.addBook(b4);
    
    cout << "Search for 1111\n";
    list.searchBook(1111);
    
    cout << "Remove id 4404\n";
    list.removeBook(4404);
    
    cout << "Search for 4404 after deleting it\n";
    list.searchBook(4404);
    
    return 0;
}
