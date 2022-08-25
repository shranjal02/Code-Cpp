#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *traverseLink(Node *root)
{

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }
    // enter left
    cout << " Enter for left " << data << endl;
    root->left = traverseLink(root->left);
    // enter right
    cout << "Enter for right " << data << endl;
    root->right = traverseLink(root->right);
    return root;
}
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void postOrder(Node* root){

// base case
if(root == NULL){
    return;
}
postOrder(root -> left);
postOrder(root -> right);
cout << root -> data << endl;

}

int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    Node *root = NULL;
    root = traverseLink(root);
    levelOrderTraversal(root);
    cout << "post order "<< endl;
    postOrder(root);

    return 0;
}