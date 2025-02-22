#include <iostream>
#include <stack>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int data){
            val = data;
            left = nullptr;
            right = nullptr;
        }   
};

TreeNode* initializeTree(){
    TreeNode* root = new TreeNode(1);
    TreeNode* node1 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(3);
    TreeNode* node3 = new TreeNode(4);
    TreeNode* node4 = new TreeNode(5);
    TreeNode* node5 = new TreeNode(7);
    root -> left = node1;
    root -> right = node2;
    root -> left -> left = node3;
    root -> left -> right = node4;
    root -> right -> right = node5;
    return root;
}

void inorderTraversal(TreeNode* root){
    if(root == nullptr){
        return;
    }
    inorderTraversal(root -> left);
    cout << root -> val;
    inorderTraversal(root -> right);
}   

void BFS(TreeNode* root){
    queue<TreeNode*>queue;
    queue.push(root);
    while(!queue.empty()){
        TreeNode* node = queue.front();
        cout << node -> val;
        if(node -> left != NULL){
            queue.push(node -> left);
        }
        if(node -> right != NULL){
            queue.push(node -> right);
        }
        queue.pop();
    }
}

int main(){
    TreeNode* root = initializeTree();
    inorderTraversal(root);
    cout << "\n";
    // BFS(root);
}
