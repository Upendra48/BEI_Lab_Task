// Creating A binary tree

#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node *left;
        node *right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* createTree(node* root){
    int data;
    cout << "Enter data: ";
    cin >> data;

    root = new node(data);

    if(data == -1){
        return NULL;
    }
    cout << "Enter left child of : " << data << endl;
    root->left = createTree(root->left);
    cout << "Enter right child of: " << data << endl;
    root->right = createTree(root->right);
    return root;
}

void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node* root){
    if(root== NULL){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root== NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}

int main(){
    node *root = NULL;
    // creating a tree
    root = createTree(root);
    // 1 2 -1 -1 3 -1 -1

    // traversal
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);

    cout<<endl;
    cout<<"Level order traversal: ";
    levelOrderTraversal(root);

    return 0;
}