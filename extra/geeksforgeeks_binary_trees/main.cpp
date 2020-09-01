#include <iostream>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Allocates a new node with the given data and NULL pointers
struct node* newNode(int data)
{
    struct node* node = new(struct node);
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

/*
 Given a binary tree, return true if a node
 with the target data is found in the tree. Recurs
 down the tree, chooses the left or right
 branch by comparing the target to each node.
*/
static int lookup(struct node* node, int target) {
    // 1. Base case is an empty tree where it's NULL, return false since target isn't found
    if (node == NULL)
        return false;
    else {
        // 2. Check if we can find the target
        if (node->data == target) {
            return true;
        }
        else { // 3. Recurse depending on if the target is less or >= to the data
            if (target < node->data)
                return(lookup(node->left, target));
            else {
                return(lookup(node->right, target));
            }
        }
    }
}

/*
 Give a binary search tree and a number, inserts a new node
 with the given number in the correct place in the tree.
 Returns the new root pointer which the caller should
 then use (the standard trick to avoid using reference
 parameters).
*/
struct node* insert(struct node* node, int data) {
    // 1. Base case, is an empty tree where it's NULL
    if (node == NULL)
        return(newNode(data));
    // 2. Recurse depending on the size of the data
    else {
        if (data <= node->data) {
            node->left = insert(node->left, data);
        }
        else {
            node->right = insert(node->right, data);
        }
    }
    return(node);
}

// Given a binary tree, count the number of nodes in the tree
int size(struct node* node) {
    // 1. Base case, the root is the only node
    if ((node->left == NULL) && (node->right == NULL)) {
        return(1);
    }
    else {
        
    }

}


int main() {
    /*
     *      1
     *       \
     *        3
     *         \
     *          4
     * 
     */  
    struct node *root = newNode(1);
    root->right = newNode(3);
    root->right->right = newNode(4);
    std::cout << lookup(root, 1) << std::endl;
    std::cout << lookup(root, 2) << std::endl;
    std::cout << lookup(root, 3) << std::endl;
    std::cout << lookup(root, 4) << std::endl;
    std::cout << lookup(root, 5) << std::endl;

    root = insert(root, 2);
    std::cout << lookup(root, 2) << std::endl;
    return(0);
}