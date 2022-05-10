#include <bits/stdc++.h>
#include "../data-structures/myBST.h"

using namespace std;

void insertElementsBST (BST<int> *bst, vector<int> arr, int start, int end) {
    if (start > end) return;

    int mid = (start+end)/2;
    bst->insert(arr[mid]);
    //printf("Insert %d\n",arr[mid]);
    insertElementsBST(bst,arr,start,mid-1);
    insertElementsBST(bst,arr,mid+1,end);
}

// Question function
// Solution: O(N.logN)
BST<int>* minimal_tree (vector<int> arr) {
    BST<int> *bst = new BST<int>();
    insertElementsBST(bst,arr,0,arr.size()-1);
    return bst;
}

int main () {
	vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    BST<int> *bst = minimal_tree(arr);
    bst->printInOrder();
    delete bst;
    return 0;
}
