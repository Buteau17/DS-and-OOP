#include "BST.h"
#include<iostream>
#include<queue>
using namespace std;

void BST::insert(Node* insertNode) {
    //TODO: insert a node to BST
    if (!insertNode)return;
    if (root == NULL) {
        root = insertNode;
        return;
    }
    Node* cur = root;
    int val = insertNode->getValue();
    while (1) {
        if (cur->getValue() > val) {
            if (cur->getLchild() == NULL) {
                cur->setLchild(insertNode);
                break;
            }
            else
                cur = cur->getLchild();
        }
        else {
            if (cur->getRchild() == NULL) {
                cur->setRchild(insertNode);
                break;
            }
            else
                cur = cur->getRchild();
        }
    }

}

void BST::InOrder_traversal(Node* node){
    //TODO: Inorder traversal
    if (node == NULL) return;
    InOrder_traversal(node->getLchild());
    cout << node->getValue() << " ";
    InOrder_traversal(node->getRchild());
}

void BST::PreOrder_traversal(Node* node){
    //TODO: PreOrder traversal
    if (node == NULL) return;
    cout << node->getValue() << " ";
    PreOrder_traversal(node->getLchild());
    PreOrder_traversal(node->getRchild());
}

void BST::PostOrder_traversal(Node* node){
    //TODO: PostOrder traversal

    if (node == NULL) return;
    PostOrder_traversal(node->getLchild());
    PostOrder_traversal(node->getRchild());
    cout << node->getValue() << " ";
}

void BST::LevelOrder_traversal(Node* node){
    //TODO: Level order traversal
    if (node == NULL) return;
    //Initialise queue to hold the current level nodes
    queue<Node*> q;
    Node* curr;
    //push current root
    q.push(node);
    //NULL is used to distinguish each level as current level and next level both occur at the same time in the queue
    q.push(NULL);
    //loop until queue is not empty
    while (q.size() > 1) {
        //pop one element from the queue front
        curr = q.front();
        q.pop();
        //if it is NULL it means one level is finished
        if (curr == NULL) {
            q.push(NULL);
        }
        else {
            //Push left and right child to the queue
            if (curr->getLchild())
                q.push(curr->getLchild());
            if (curr->getRchild())
                q.push(curr->getRchild());
            //Print current data
            if (curr != NULL) {
                cout << curr->getValue() << " ";
            }
        }
    }
}

int BST::ComputeHeight(Node* node){
    // Compute the height of the binary search tree.
    // Notice that the root level is 1
    if (node == NULL)
        return 0;
    int hl = ComputeHeight(node->getLchild());
    int hr = ComputeHeight(node->getRchild());
    return max(hl, hr) + 1;
}


Node* BST::getRoot() {
    //TODO: return root of BST
    return this->root;
}