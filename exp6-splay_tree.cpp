#include<iostream>
#include<stdlib.h>
using namespace std;
// An AVL tree node
class Node
{
  public:
    int key;
    Node *left, *right;
};

/* Helper function that allocates a new node with the given key and
    NULL left and right pointers. */
 Node* newNode(int key)
{
    Node* node = new Node();
    node->key   = key;
    node->left  = node->right  = NULL;
    return (node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
 Node *rightRotate( Node *x)
{
    Node *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
 Node *leftRotate( Node *x)
{
     Node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}


// This function brings the key at root if key is present in tree.
// If key is not present, then it brings the last accessed item at
// root.  This function modifies the tree and returns the new root
 Node *splay( Node *root, int key)
{
    // Base cases: root is NULL or key is present at root
    if (root == NULL || root->key == key)
        return root;

    // Key lies in left subtree
    if (root->key > key)
    {
        // Key is not in tree, we are done
        if (root->left == NULL) return root;

        // Zig-Zig (Left Left)
        if (root->left->key > key)
        {
            // First recursively bring the key as root of left-left
            root->left->left = splay(root->left->left, key);

            // Do first rotation for root, second rotation is
            // done after else
            root = rightRotate(root);
        }
        else if (root->left->key < key) // Zig-Zag (Left Right)
        {
            // First recursively bring the key as root of left-right
            root->left->right = splay(root->left->right, key);

            // Do first rotation for root->left
            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }

        // Do second rotation for root
        return (root->left == NULL)? root: rightRotate(root);
    }
    else // Key lies in right subtree
    {
        // Key is not in tree, we are done
        if (root->right == NULL) return root;

        // Zag-Zig (Right Left)
        if (root->right->key > key)
        {
            // Bring the key as root of right-left
            root->right->left = splay(root->right->left, key);

            // Do first rotation for root->right
            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }
        else if (root->right->key < key)// Zag-Zag (Right Right)
        {
            // Bring the key as root of right-right and do
            // first rotation
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }

        // Do second rotation for root
        return (root->right == NULL)? root: leftRotate(root);
    }
}
Node* insert(Node* node, int key)
{
    /* 1. Perform the normal BST rotation */
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
    {
         node->left = insert(node->left, key);

    }

    else if (key > node->key)
    {
         node->right = insert(node->right, key);

    }

    else // Equal keys not allowed
        return node;
}

// The delete function for Splay tree. Note that this function
// returns the new root of Splay Tree after removing the ke
 Node* delete_key( Node *root, int key)
{
     Node *temp;
    if (!root)
        return NULL;

    // Splay the given key
    root = splay(root, key);

    // If key is not present, then
    // return root
    if (key != root->key)
        return root;

    // If key is present
    // If left child of root does not exist
    // make root->right as root
    if (!root->left)
    {
        temp = root;
        root = root->right;
    }

    // Else if left child exits
    else
    {
        temp = root;

        /*Note: Since key == root->key,
        so after Splay(key, root->lchild),
        the tree we get will have no right child tree
        and maximum node in left subtree will get splayed*/
        // New root
        root = splay(root->left, key);

        // Make right child of previous root  as
        // new root's right child
        root->right = temp->right;
    }

    // free the previous root node, that is,
    // the node containing the key
    free(temp);

    // return root of the new Splay Tree
    return root;

}

// A utility function to print preorder traversal of the tree.
// The function also prints height of every node
void preOrder( Node *root)
{
    if (root != NULL)
    {
        cout<< root->key<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

/* Driver program to test above function*/
int main()
{
    // Splay Tree Formation
    Node *root = NULL;

    /* Constructing tree given in
    the above figure */
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 9);
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 7);
     int key = 4;

    root = delete_key(root, key);
    cout<<"Preorder traversal of the modified Splay tree is "<<endl;
    preOrder(root);
    cout<<endl;
    cout<<"time complexity in best and average case: O(logn)\n worst case: Theta(n)";
    return 0;
}
