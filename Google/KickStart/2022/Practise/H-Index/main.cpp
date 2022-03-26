#include <iostream>
#include <vector>
#include <queue>

int main () {
    int T, N, C;
    scanf("%d",&T);
    for (int k = 0; k < T; k++) {
        // Read input
        std::vector<int> papers;
        scanf("%d",&N);
        for (int i = 0; i < N; i++) {
            scanf("%d",&C);
            papers.push_back(C);    
        }
        
        // Solve problem :> O(n*logn)
        // Solution uses a minHeap
        int h_index = 0;
        std::vector<int> ans;
        std::priority_queue<int,std::vector<int>,std::greater<int>> pq;
        for (int i = 0; i < N; i++) {
            if (papers[i] > h_index) {
                pq.push(papers[i]);
            }
            
            // Remove the elements lesser than the current 'h_index'
            while (!pq.empty() && pq.top() <= h_index) {
                pq.pop();
            }
            // Is the number of papers with citations greater or
            // equal than the current 'h_index' 
            if (pq.size() >= h_index+1) {
                h_index++;
            }
            
            // Store in the solution array
            ans.push_back(h_index);
        }
        
        // Print output
        printf("Case #%d: ",k+1);
        for (int i = 0; i < N-1; i++) {
            printf("%d ",ans[i]);
        }
        printf("%d\n",ans.back());
    }
    return 0;
}
