#include <bits/stdc++.h>
#include "../data-structures/myBST.h"

using namespace std;

int calcHeight (BSTNode<int> *root) {
    if (root == nullptr) 
        return -1;
    else
        return max(calcHeight(root->left),calcHeight(root->right))+1;
}

// Question function
// Solution: O(N.logN)
bool isBalanced (BSTNode<int> *root) {
    if (root == nullptr) return true;

    int heightDiff = abs(calcHeight(root->left) - calcHeight(root->right));
    if (heightDiff > 1) {
        return false;
    }
    else {
        // Check the offsprings
        return isBalanced(root->left) && isBalanced(root->right);
    }
}

int main () {
	BST<int> *bst = new BST<int>();
    bst->insert(8);
    bst->insert(4);
    bst->insert(2);
    bst->insert(1);
    bst->insert(3);
    bst->insert(6);
    bst->insert(5);
    bst->insert(7);
    bst->insert(12);
    bst->insert(10);
    bst->insert(9);
    bst->insert(11);
    bst->insert(14);
    bst->insert(13);
    bst->insert(15);

    BST<int> *bst_2 = new BST<int>();
    bst_2->insert(1);
    bst_2->insert(2);
    bst_2->insert(3);
    bst_2->insert(4);
    bst_2->insert(5);

    bool ans = isBalanced(bst->root);
    if (ans) {
        printf("The tree is balanced!\n");
    }
    else {
        printf("The tree is NOT balanced!\n");
    }

    ans = isBalanced(bst_2->root);
    if (ans) {
        printf("The tree is balanced!\n");
    }
    else {
        printf("The tree is NOT balanced!\n");
    }

    delete bst;
    delete bst_2;

    return 0;
}
