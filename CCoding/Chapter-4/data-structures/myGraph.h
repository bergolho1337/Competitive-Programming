#ifndef MYGRAPH_H
#define MYGRAPH_H

// Implementation of a Graph data structure using templates

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>

template<class T>
class GNode;
template<class T>
class GEdge;

template<class T>
class GEdge {
public:
    uint32_t id;
    GEdge<T> *next;
public:
    GEdge (const uint32_t id, GEdge<T> *next = nullptr) {
        this->id = id;
        this->next = next;
    }
    ~GEdge () {
        this->next = nullptr;
    }
};

template<class T>
class GNode {
public:
    uint32_t id;
    T value;
    GEdge<T> *last_edge;
    GEdge<T> *list_edges;
    GNode<T> *next;
public:
    GNode (const uint32_t id, const T &value, GNode<T> *next = nullptr, GEdge<T> *edges = nullptr) {
        this->id = id;
        this->value = value;
        this->next = next;
        this->list_edges = edges;
        this->last_edge = nullptr;
    }
    ~GNode () {
        this->last_edge = nullptr;
        this->list_edges = nullptr;
    } 
    void print () {
        if (typeid(T) == typeid(double))
            printf("|| %u [%g] ||\n", this->id, this->value);
        else if (typeid(T) == typeid(int))
            printf("|| %u [%d] ||\n", this->id, this->value);
    } 
};

template<class T>
class Graph {
public:
    uint32_t total_nodes;
    uint32_t total_edges;
    GNode<T> *list_nodes;
    GNode<T> *last_node;
public:
    Graph () {
        this->total_nodes = 0;
        this->total_edges = 0;
        this->list_nodes = nullptr;
        this->last_node = nullptr;
    }
    ~Graph () {
        if (this->list_nodes != nullptr) {
            free_list_nodes();
        }
    }
    void insert_node (const T &value) {
        // First node
        if (this->list_nodes == nullptr) {
            this->list_nodes = new GNode<T>(this->total_nodes++,value);
            this->last_node = this->list_nodes;
        }
        // Insert after the last node
        else {
            this->last_node->next = new GNode<T>(this->total_nodes++,value);
            this->last_node = this->last_node->next;
        }
    }
    void insert_edge (const uint32_t src_id, const uint32_t dst_id) {
        // Invalid edge
        if (src_id == dst_id) return;

        GNode<T> *src = searchNodeById(src_id);
        GNode<T> *dst = searchNodeById(dst_id);

        // Invalid edge
        if (!src || !dst) return;

        // First edge
        if (src->list_edges == nullptr) {
            src->last_edge = new GEdge<T>(dst_id);
            src->list_edges = src->last_edge;
        }
        // Insert after the last edge
        else {
            src->last_edge->next = new GEdge<T>(dst_id);
            src->last_edge = src->last_edge->next;
        }
    }
    GNode<T>* searchNodeById (const uint32_t id) {
        GNode<T> *tmp = this->list_nodes;
        while (tmp != nullptr) {
            if (tmp->id == id)
                return tmp;
            tmp = tmp->next;
        }
        return nullptr;
    }
    GNode<T>* searchNodeByValue (const T &value) {
        GNode<T> *tmp = this->list_nodes;
        while (tmp != nullptr) {
            if (tmp->value == value)
                return tmp;
            tmp = tmp->next;
        }
        return nullptr;
    }
    void print () {
        GNode<T> *tmp = this->list_nodes;
        while (tmp != nullptr) {
            printf("|| %d || ",tmp->id);
            GEdge<T> *tmp2 = tmp->list_edges;
            while (tmp2 != nullptr) {
                printf(" --> || %u ||",tmp2->id);
                tmp2 = tmp2->next;
            }
            printf("\n");
            tmp = tmp->next;
        }
    }
    private:
        void free_list_edges (GNode<T> *n) {
            GEdge<T> *e1 = n->list_edges;
            GEdge<T> *e2 = n->list_edges->next;

            while (e1 != nullptr) {
                delete e1;
                e1 = e2;
                if (e2 != nullptr)
                    e2 = e2->next;
            }
            n->list_edges = nullptr;
            n->last_edge = nullptr;
        }
        void free_list_nodes () {
            GNode<T> *n1 = this->list_nodes;
            GNode<T> *n2 = this->list_nodes->next;

            while (n1 != nullptr) {
                if (n1->list_edges) {
                    free_list_edges(n1);
                }

                delete n1;
                n1 = n2;
                if (n2 != nullptr)
                    n2 = n2->next;
            }
            this->last_node = nullptr;
        }
};

#endif