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

TreeNode* initializeBST(vector<int> &v){
    TreeNode* root = new TreeNode(v[0]);
    
    for(int i=1;i<v.size();i++){
        TreeNode* tmp = root;
        while(v[i] < tmp -> val){
            if(tmp -> left == NULL){
                tmp -> left = new TreeNode(v[i]);
                break;
            }
            tmp = tmp -> left;
        }

        while(v[i] > tmp -> val){
            if(tmp -> right == NULL){
                tmp -> right = new TreeNode(v[i]);
                break;
            }
            tmp = tmp -> right;
        }
    }
    return root;
}

// inorder/postorder/preorder/DFS
void inorderTraversal(TreeNode* root){
    if(root == nullptr){
        return;
    }
    inorderTraversal(root -> left);
    cout << root -> val << " ";
    inorderTraversal(root -> right);
}   

// BFS
void BFS(TreeNode* root){
    queue<TreeNode*>queue;
    queue.push(root);
    while(!queue.empty()){
        TreeNode* node = queue.front();
        cout << node -> val << " ";
        if(node -> left != NULL){
            queue.push(node -> left);
        }
        if(node -> right != NULL){
            queue.push(node -> right);
        }
        queue.pop();
    }
}
