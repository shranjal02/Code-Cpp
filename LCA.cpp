// lowest common ancestor

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }

};
    node* lca(node* root, int n1, int n2){
    // base

    if(root == NULL){
        return NULL;
    }

    if(root->data == n1 || root -> data == n2){
        return root;
    }
    node* leftAns = lca(root -> left , n1, n2);
    node* rightAns = lca(root -> right , n1, n2);

    if( leftAns != NULL && rightAns != NULL){
        return root;
    }
    else if(leftAns!= NULL && rightAns == NULL){
        return leftAns;
    }
    else if(leftAns == NULL && rightAns != NULL){
        return rightAns;
    }
    else{
        return NULL;
    }


}
