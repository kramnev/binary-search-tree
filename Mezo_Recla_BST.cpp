#include <iostream>

using namespace std;

struct Node{
    int key;
    int count;
    struct Node *left, *right;

    Node(){
        left = NULL;
        right = NULL;
    }

    Node(int val){
        key = val;
        left = NULL;
        right = NULL;
    }
};

struct Node* newNode(int key) {
    struct Node* newNode = new Node(key); 
    return newNode;
}

struct Node* insert(Node* root, int key){
    //If tree is empty, return a new node
    if(root == NULL) {
        root = newNode(key);
        return root;
    }

    //Else, recur down the tree
    if(key < root->key) {
        root->left = insert(root->left, key);
    } 
    else if(key > root->key) {
        root->right = insert(root->right, key);
    }

    //Return the node pointer 
    return root;
}

struct Node* Search(Node* root, int key) {

    if(root == NULL) {
        return root;
    }

    if(key == root->key) {
        return root;
    } else if(key < root->key) {
        root = Search(root->left, key);
    } else if(key > root->key) {
        root = Search(root->right, key);
    }

    return root;
}

int main() {
    struct Node* root = NULL;

    root = insert(root, 15);
    insert(root, 24);
    insert(root, 25);
    insert(root, 2);

    cout << root->right->key << endl;
    cout << root->right->right->key << endl;
    cout << root->left->key << endl;

    if(Search(root, 2)) cout << "true" ;
    else cout << "false";

    return 0;
}