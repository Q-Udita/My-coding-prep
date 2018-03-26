#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
};

struct Node* newNode(int d) {
    Node* n=new Node;
    n->val=d;
    n->left=n->right=NULL;
    return n;
}

int isMirror(struct Node* a,struct Node* b) {
    if(a==NULL && b==NULL)
        return 1;
    if((a==NULL && b!=NULL) || (a!=NULL && b==NULL)) 
        return 0;
    if((a->val == b->val) && (isMirror(a->left,b->right)) && (isMirror(a->right,b->left)))
        return 1;
    else return 0;
}

int main()
{
    Node *a = newNode(1);
    Node *b = newNode(1);
    a->left = newNode(2);
    a->right = newNode(3);
    a->left->left  = newNode(4);
    a->left->right = newNode(5);
 
    b->left = newNode(3);
    b->right = newNode(2);
    b->right->left = newNode(5);
    b->right->right = newNode(4); 
    
    cout<<isMirror(a,b);
    return 0;
}
