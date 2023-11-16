#include <iostream>

using namespace std;

struct Node{
    int key;
    int count;
    struct Node *left, *right;

    Node(){
        left = NULL;
        right = NULL;
        count = 0;
    }

    Node(int val){
        key = val;
        left = NULL;
        right = NULL;
        count = 0;
    }
};

struct Node* newNode(int key) {
    struct Node* newNode = new Node(key); 
    return newNode;
}

struct Node* inOrderTraverse(Node* root) {
    if(root == NULL) {
        return root;
    }

    inOrderTraverse(root->left);
    cout << root->key << " ";
    inOrderTraverse(root->right);
    return root;
}

struct Node* preOrderTraverse(Node* root) {
    if(root == NULL) {
        return root;
    }
    if(root->key )cout << root->key << " ";
    preOrderTraverse(root->left);
    cout << root->key << " ";
    preOrderTraverse(root->right);
    return root;
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

void deleteBranch(Node*& root) {
    // cout << "in" ;
    if(root != NULL) {
        deleteBranch(root->left);
        deleteBranch(root->right);
        delete root;
        root = NULL;
    }
}

struct Node* deleteNode(Node* root, int key) {
    if(root == NULL) {
        return root;
    }

    // Traverse and find key in the tree
    if(key < root->key) {
        root->left = deleteNode(root->left, key);
        return root;
    } else if(key > root->key) {
        root->right = deleteNode(root->right, key);
        return root;
    } 

    deleteBranch(root);
    return root;
}

struct Node* Search(Node* root, int key) {

    if(root == NULL) {
        return root;
    }

    // Traverse the tree 
    if(key == root->key) {
        return root;
    } else if(key < root->key) {
        root = Search(root->left, key);
    } else if(key > root->key) {
        root = Search(root->right, key);
    }

    return root;

}

struct Node* findMaximum(Node* root) {
    if(root == NULL) {
        return root;
    } else if(root->right != NULL) {
        root = findMaximum(root->right);
    }

    return root;
}

struct Node* findMinimum(Node* root) {
    if(root == NULL) {
        return root;
    } else if(root->left != NULL) {
        root = findMinimum(root->left);
    }

    return root;
}

int main() {
    struct Node* root = NULL;
    struct Node* temp = NULL;
    int choice = 1;
    int key;

    while(choice != 0) {
        cout << "Binary Search Tree\n [1] Insert Item\n [2] Delete Item\n [3] Search Item\n [4] Find Maximum\n [5] Find Minimum\n [6] Find Successor\n [7] Find Predecessor\n [8] Display Tree\n [0] Exit\n\nChoice: ";
        cin >> choice;
        system("cls");
        switch(choice){
            case 1:
            {
                cout << "Enter Tree Data: ";
                cin >> key;

                root = insert(root, key);

                system("cls");

                cout << "Tree: ";
                //traverseTree(root);
                cout << "\n\n";
            }
            break;

            case 2:
                //traverseTree(root);
                if(root == NULL) {
                    cout << "Tree is Empty!\n\n";
                    break;
                }
                cout << "Enter data to delete: ";
                cin >> key;

                temp = deleteNode(root, key);

                system("cls");
                cout << "Node " << temp->key << " deleted.\n\n";
            break;

            case 3:
            break;

            case 4:
            break;

            case 8:
            {
                int c;
                cout << "Choose Traversal Method: \n [1] Inorder\n [2] Pre-order\n [3] Post-Order\nChoice: ";
                cin >> c;
                system("cls");
                switch (c)
                {
                case 1:
                    cout << "Tree: ";
                    inOrderTraverse(root);
                    cout << "\n\n";
                    break;
                
                case 2:
                    cout << "Tree: ";
                    preOrderTraverse(root);
                    cout << "\n\n";
                    break;

                case 3:
                    /* code */
                    break;
                
                default:
                    break;
                }
            }
            break;

            default:
            break;
        }
    }

    // root = insert(root, 15);
    // insert(root, 24);
    // insert(root, 100);
    // insert(root, 25);
    // insert(root, 2);

    // traverseTree(root);

    // if(Search(root, 25)) cout << "true\n" ;
    // else cout << "false\n";

    // // deleteNode(root, 24);

    // // if(Search(root, 24)) cout << "true\n" ;
    // // else cout << "false\n";

    // Node* max = findMaximum(root);
    // cout << "\nMaximum:\nKey: " << max->key << "\nCount: " << max->count << endl;

    // Node* min = findMinimum(root);
    // cout << "\nMinimum:\nKey: " << min->key << "\nCount: " << min->count << endl;

    // if(root != nullptr) traverseTree(root);
    // else cout << "Tree is empty!\n";
    return 0;
}