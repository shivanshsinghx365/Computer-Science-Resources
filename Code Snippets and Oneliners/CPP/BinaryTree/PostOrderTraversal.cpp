#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;

    //Type of constructor
    TreeNode(int val){
        data = val;
        left = right = NULL;
    }
};

//DFS Tranversal
//Post-Order Traversal - left right root


void postOrder(TreeNode *node){
    if(node == NULL){
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
}

int32_t main()
{
    struct TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5); 

    postOrder(root);
}