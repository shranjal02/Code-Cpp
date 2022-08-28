#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        int data = d;
        node* left = NULL;
        node* right = NULL;
    }
};

vector<int> inOrder(node* root){
vector<int> ans;
while(root != NULL){
    if(root->left==NULL){
        ans.push_back(root->data);
        root = root->right;
    }
    else{
        while(root->left->right!=NULL && root->left->right != root){
             root -> left = root -> left -> right;
        }

        if(root -> left -> right == NULL){
            root -> left -> right = root;
            root = root->left;
        }
        else{
            root -> left -> right = NULL;
            ans.push_back(root -> data);
            root = root -> right;
        }
    }
}
}

int main(){
    node* root = new node(1);
    root -> left = new node(2);
    root -> left -> left = new node(3);
    root -> left -> left = new node(4);
    root -> right = new node(5);

    vector<int> ans = inOrder(root);
    for(int i=0; i<ans.size(); i++){
    cout << ans[i] << " ";
    }cout<< endl;

    return 0;
}