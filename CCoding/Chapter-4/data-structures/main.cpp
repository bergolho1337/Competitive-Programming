#include <bits/stdc++.h>
#include "myBST.h"
#include "myGraph.h"

using namespace std;

void test_BST () {
    BST<int> *bst_1 = new BST<int>();
    bst_1->insert(8);
    bst_1->insert(4);
    bst_1->insert(10);
    bst_1->insert(2);
    bst_1->insert(6);
    bst_1->insert(20);
    
    printf("-------------------------------------\n");
    printf("IN ORDER\n");
    bst_1->printInOrder();
    printf("PRE ORDER\n");
    bst_1->printPreOrder();
    printf("POS ORDER\n");
    bst_1->printPosOrder();
    printf("-------------------------------------\n");

    BSTNode<int> *node_1 = bst_1->search(6);    // Found
    node_1->print();
    BSTNode<int> *node_2 = bst_1->search(999);  // Not found
    
    //bst_1->remove(20);  // Ok
    //bst_1->remove(10);    // Ok
    bst_1->remove(8);       // Ok

    printf("\n\n-------------------------------------\n");
    printf("IN ORDER\n");
    bst_1->printInOrder();
    printf("PRE ORDER\n");
    bst_1->printPreOrder();
    printf("POS ORDER\n");
    bst_1->printPosOrder();
    printf("-------------------------------------\n");

    delete bst_1;
}

void test_Graph () {
    Graph<int> *g1 = new Graph<int>();
    g1->insert_node(10);
    g1->insert_node(11);
    g1->insert_node(12);
    g1->insert_node(13);
    g1->insert_node(14);
    g1->insert_node(15);
    g1->insert_edge(0,1);
    g1->insert_edge(0,4);
    g1->insert_edge(0,5);
    g1->insert_edge(1,3);
    g1->insert_edge(1,4);
    g1->insert_edge(2,1);
    g1->insert_edge(3,2);
    g1->insert_edge(3,4);
    g1->print();

    GNode<int> *node_1 = g1->searchNodeByValue(13);
    if (node_1)
        printf("Found node %d!\n",node_1->value);
    else
        fprintf(stderr,"[-] Node not found!\n");
    GNode<int> *node_2 = g1->searchNodeByValue(99);
    if (node_2)
        printf("Found node %d!\n",node_2->value);
    else
        fprintf(stderr,"[-] Node not found!\n");

    delete g1;
}

int main () {
    //test_BST();
    test_Graph();

    return 0;
}