#ifndef BST_HPP
#define BST_HPP

using namespace std;

struct Node{
    int key;
    Node* left ;
    Node* right;
};

class BST{
    private:
        Node* root;
        Node* createNode(int data);
        Node* searchKeyHelper(Node*, int);
        Node* addNodeHelper(Node*, int);
        void destroyNode(Node *root);
        void print2DUtilHelper(Node *, int);
        void printTreeHelper(Node*);



    public:

        void addNode(int);              // function to insert a node in the tree.
        bool searchKey(int);            // function to search a data in the tree
        void printTree();               //function to print the tree
        BST();

        void print2DUtil(int);
    
};
#endif
