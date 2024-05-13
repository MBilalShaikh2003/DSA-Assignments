#include <iostream>
using namespace std;

struct bstnode {
    int data;
    int heightleft;
    int heightright;
    bstnode *left;
    bstnode *right;
};

int maxheight(int a, int b) {
    if(a>b){
    	return a;
	}
	else{
		return b;
	}
}

bstnode* shiftleft(bstnode* unbalancenode) {
    bstnode* retnode = unbalancenode->right;
    bstnode* temp = retnode->left;
    retnode->left = unbalancenode;
    unbalancenode->right = temp;
    if (temp == NULL) {
        unbalancenode->heightright = 0;
    }
    else {
        unbalancenode->heightright = maxheight(temp->heightleft, temp->heightright) + 1;
    }
    return retnode;
}

bstnode* shiftright(bstnode* unbalancenode) {
    bstnode* retnode = unbalancenode->left;
    bstnode* temp = retnode->right;
    retnode->right = unbalancenode;
    unbalancenode->left = temp;
    if (temp == NULL) {
        unbalancenode->heightleft = 0;
    }
    else {
        unbalancenode->heightleft = maxheight(temp->heightleft, temp->heightright) + 1;
    }
    return retnode;
}

bstnode* insert(bstnode* root, int data) {
    if (root == NULL) {
        bstnode* node = new bstnode;
        node->data = data;
        node->heightleft = node->heightright = 0;
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
        root->heightleft = maxheight(root->left->heightleft, root->left->heightright) + 1;
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
        root->heightright = maxheight(root->right->heightleft, root->right->heightright) + 1;
    }
    int balancefactor = root->heightleft - root->heightright;
    if (balancefactor > 1) {
        if (data < root->left->data) {
            root = shiftright(root);
        }
        else {
            root->left = shiftleft(root->left);
            root = shiftright(root);
        }
    }
    else if (balancefactor < -1) {
        if (data > root->right->data) {
            root = shiftleft(root);
        }
        else {
            root->right = shiftright(root->right);
            root = shiftleft(root);
        }
    }
    return root;
}

void inorder(bstnode* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    bstnode* root = NULL;
    int choice;
    do {
        cout << "Enter 1 to insert, 2 to display inorder, 0 to exit: ";
        cin >> choice;
        if (choice == 1) {
            int data;
            cout << "Enter value to insert: ";
            cin >> data;
            root = insert(root, data);
        }
        else if (choice == 2) {
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
        }
    } while (choice != 0);
    return 0;
}

