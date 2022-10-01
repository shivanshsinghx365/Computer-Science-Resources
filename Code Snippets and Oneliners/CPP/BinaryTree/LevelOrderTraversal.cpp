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


//BFS Traversal
//LevelOrder Traversal

vector<vector<int>> levelOrder(TreeNode *root){
    vector<vector<int>> ans;

    if(root == NULL) return ans;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i = 0;i<size;i++){
            TreeNode *node = q.front();
            q.pop();

            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
            level.push_back(node->data);
        }

        ans.push_back(level);
    }

    return ans;
}

int32_t main()
{
    struct TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5); 

    levelOrder(root);
}