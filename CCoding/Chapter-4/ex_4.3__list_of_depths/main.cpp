#include <bits/stdc++.h>
#include "../data-structures/myBST.h"

using namespace std;

void levelTransversal (BSTNode<int> *root, vector< vector<int> > &ld, int level) {
    if (root != nullptr) {
        levelTransversal(root->left,ld,level+1);
        ld[level].push_back(root->value);
        levelTransversal(root->right,ld,level+1);
    }
}

vector< vector<int> > list_of_depths (BST<int> *bst) {
    vector< vector<int> > ld;
    ld.assign(bst->num_nodes,vector<int>());
    levelTransversal(bst->root,ld,0);
    return ld;
}

int main () {
	BST<int> *bst_1 = new BST<int>();
    bst_1->insert(8);
    bst_1->insert(4);
    bst_1->insert(10);
    bst_1->insert(2);
    bst_1->insert(6);
    bst_1->insert(20);

    BST<int> *bst_2 = new BST<int>();
    bst_2->insert(8);
    bst_2->insert(4);
    bst_2->insert(2);
    bst_2->insert(1);
    bst_2->insert(3);
    bst_2->insert(6);
    bst_2->insert(5);
    bst_2->insert(7);
    bst_2->insert(12);
    bst_2->insert(10);
    bst_2->insert(9);
    bst_2->insert(11);
    bst_2->insert(14);
    bst_2->insert(13);
    bst_2->insert(15);

    vector< vector<int> > ld_1 = list_of_depths(bst_1); 
    for (int i = 0; i < ld_1.size(); i++) {
        printf("[Level=%d] ",i);
        for (int j = 0; j < ld_1[i].size(); j++) {
            printf("%d ",ld_1[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    vector< vector<int> > ld_2 = list_of_depths(bst_2); 
    for (int i = 0; i < ld_2.size(); i++) {
        printf("[Level=%d] ",i);
        for (int j = 0; j < ld_2[i].size(); j++) {
            printf("%d ",ld_2[i][j]);
        }
        printf("\n");
    }

    delete bst_1;
    delete bst_2;
    return 0;
}



