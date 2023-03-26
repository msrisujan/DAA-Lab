#include <bits/stdc++.h>
using namespace std;
struct Node{
    int index;
    Node *left, *right;
};
Node *newnode(int index){
    Node *t = new Node;
    t->left = t->right = NULL;
    t->index = index;
    return t;
}
void traverse(Node *root, int arr[], int &res){
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;
    if (res > arr[root->left->index] && root->left->index != root->index){
        res = arr[root->left->index];
        traverse(root->right, arr, res);
    }
    else if (res > arr[root->right->index] && root->right->index != root->index){
        res = arr[root->right->index];
        traverse(root->left, arr, res);
    }
}
void Second_min(int arr[], int n){
    list<Node *> li;

    Node *root = NULL;
    for (int i = 0; i < n; i += 2){
        Node *t1 = newnode(i);
        Node *t2 = NULL;
        if (i + 1 < n){
            t2 = newnode(i + 1);
            root = (arr[i] < arr[i + 1])? newnode(i) :
                   newnode(i + 1);
            root->left = t1;
            root->right = t2;
            li.push_back(root);
        }
        else
            li.push_back(t1);
    }
    int lsize = li.size();
    while (lsize != 1){
        int last = (lsize & 1)? (lsize - 2) : (lsize - 1);
        for (int i = 0; i < last; i += 2){
            Node *f1 = li.front();
            li.pop_front();
            Node *f2 = li.front();
            li.pop_front();
            root = (arr[f1->index] < arr[f2->index])?
                   newnode(f1->index) : newnode(f2->index);
            root->left = f1;
            root->right = f2;
            li.push_back(root);
        }
        if (lsize & 1){
            li.push_back(li.front());
            li.pop_front();
        }
        lsize = li.size();
    }
    int res = INT_MAX;
    traverse(root, arr, res);
    cout <<arr[root->index]<<endl<< res;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    Second_min(arr, n);
    return 0;
}