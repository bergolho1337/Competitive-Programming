#include <bits/stdc++.h>

using namespace std;

void dfs (vector< vector<int> > g, vector<bool> &visit, const int u) {
    visit[u] = true;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (visit[v] == false) {
            dfs(g,visit,v);
        }
    }
}

vector<bool> depth_first_search (vector< vector<int> > g, const int src_id) {
    vector<bool> visit(g.size());
    dfs(g,visit,src_id);
    return visit;
}

// Question function
// Solution: O(|V|)
bool route_between_nodes (vector< vector<int> > g, const int src_id, const int dst_id) {
    vector<bool> visit = depth_first_search(g,src_id);
    return visit[dst_id];
}

int main () {
	uint32_t num_nodes = 8;
    vector< vector<int> > graph;
    graph.assign(num_nodes,vector<int>());
    graph[0].push_back(1);
    graph[0].push_back(4);
    graph[0].push_back(5);
    graph[1].push_back(3);
    graph[1].push_back(4);
    graph[2].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(2);
    graph[6].push_back(7);

    int src_id = 0;
    int dst_id = 3;
    bool ans = route_between_nodes(graph,src_id,dst_id);    // There is a route
    if (ans) {
        printf("There is a route between nodes '%d' and '%d'\n",src_id,dst_id);
    }
    else {
        printf("No route found between nodes '%d' and '%d'\n",src_id,dst_id);
    }

    dst_id = 7;
    ans = route_between_nodes(graph,src_id,dst_id);    // No route
    if (ans) {
        printf("There is a route between nodes '%d' and '%d'\n",src_id,dst_id);
    }
    else {
        printf("No route found between nodes '%d' and '%d'\n",src_id,dst_id);
    }

    return 0;
}
