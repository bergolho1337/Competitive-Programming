// Wrong Answer, but why ???
#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int id;
        uint32_t fun;
        bool is_initiator;
        Node *parent;
    public:
        Node () {
            this->id = -1;
            this->is_initiator = true;
            this->parent = nullptr;
        } 
        void print () {
            printf("|| %d [%u] {%d} || --> ",\
                this->id,this->fun,this->is_initiator);
            if (this->parent) {
                printf("|| %d ||\n",this->parent->id);
            }
            else {
                printf("\n");
            }
        }
};

// DEBUG
void print_machine (vector<Node> mac) {
    for (int i = 0; i < mac.size(); i++) {
        mac[i].print();
    }
}

// DEBUG
void print_permutation (vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

uint32_t trigger (Node node, vector<bool> &taken) {
    uint32_t max_value = 0;
    Node *ptr = &node;
    while (ptr && !taken[ptr->id-1]) {
        if (ptr->fun > max_value) {
            max_value = ptr->fun;
        }
        taken[ptr->id-1] = true;
        ptr = ptr->parent;
    }
    return max_value;
}

vector<int> get_initiators (vector<Node> mac) {
    vector<int> out;
    for (int i = 0; i < mac.size(); i++) {
        if (mac[i].is_initiator)
            out.push_back(i);
    }
    return out;
}

int main () {
    int T;
    scanf("%d",&T);
    for (int k = 0; k < T; k++) {
        int N, F, P;
        scanf("%d",&N);
        vector<Node> mac;
        mac.assign(N,Node());
        for (int i = 0; i < N; i++) {
            scanf("%u",&F);
            mac[i].id = i+1;
            mac[i].fun = F;
        }
        for (int i = 0; i < N; i++) {
            scanf("%d",&P);
            if (P != 0) {
                mac[i].parent = &mac[P-1];
                mac[P-1].is_initiator = false;
            }
        }

        uint32_t ans = 0;
        vector<int> initiators = get_initiators(mac);
        do {
            vector<bool> taken(N);
            //print_permutation(initiators);
            uint32_t sum = 0;
            for (int i = 0; i < initiators.size(); i++) {
                uint32_t fun = trigger(mac[initiators[i]],taken);
                sum += fun;
            }
            //printf(" --> %u\n",sum);

            if (sum > ans) {
                ans = sum;
            }
            
        } while ( std::next_permutation(initiators.begin(),initiators.end()) );
        
        //print_machine(mac);
        //printf("\n");

        printf("Case #%d: %u\n",k+1,ans);
    }
    return 0;
}
