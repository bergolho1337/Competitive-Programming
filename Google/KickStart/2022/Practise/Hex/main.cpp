// There is a bug in this code for the Input 8 and 9
// Solution is O(N^4)

#include <iostream>
#include <vector>
#include <cstring>

const std::vector<std::pair<int,int>> DIRECTIONS = { {0,1}, {-1,1}, {-1,0}, {-1,-1}, {0,-1}, {1,-1}, {1,0}, {1,1}};

// DEBUG
void print_grid (char *grid, const int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ",grid[i*N+j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Auxiliary function
char* copy_grid (char *original_grid, const int N) {
    char *grid = new char[N*N](); 
    memcpy(grid,original_grid,sizeof(char)*N*N);
    return grid;
}

void flood (char *grid, const int nlin, const int ncol, const int N, const char color) {
    // Mark the cell as visited
    grid[nlin*N+ncol] = tolower(color);

    for (int i = 0; i < DIRECTIONS.size(); i++) {
        // Get the next cell indexes
        int new_nlin = nlin + DIRECTIONS[i].first;
        int new_ncol = ncol + DIRECTIONS[i].second;

        // Next position is within the grid
        if ((new_nlin >= 0 && new_nlin < N) && (new_ncol >= 0 && new_ncol < N)) {
            // Check if the position has the same color
            if (grid[new_nlin*N+new_ncol] == color) {
                flood(grid, new_nlin, new_ncol, N, color);
            }
        }
    }
}

// Check for a winner using Flood-Fill algorithm
char check_winner (char *grid, const int N) {
    // Check for valid pathways
    for (int i = 0; i < N; i++) {
        // DEBUG
        //printf("i = %d\n",i);
        //print_grid(grid,N);
        
        // Check if blue wins
        // For each west cell check for a valid flood fill path (west->east)
        if (grid[i*N] == 'B') {
            flood(grid, i, 0, N, 'B');   
        }
            
        // Check if red wins
        // For each top cell check for a valid flood fill path (top->bottom)
        if (grid[i] == 'R') {
            flood(grid, 0, i, N, 'R');
        }
    }

    for (int i = 0; i < N; i++) {
        // Check if we reach a blue cell in the west side
        if (grid[i*N+(N-1)] == 'b') {
            return 'B';
        }
    }
    for (int i = 0; i < N; i++) {   
        // Check if we reach a red cell in the bottom side
        if (grid[(N-1)*N+i] == 'r') {
            return 'R';
        }
    }

    // Otherwise, return no wins
    return '.';
}

// Count the number of pieces for blue and red
void count_pieces (char *grid, const int N, int &c_blue, int &c_red) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i*N+j] == 'B') {
                c_blue++;
            }
            if (grid[i*N+j] == 'R') {
                c_red++;
            }
        }
    }
}

char solve_flood_fill (char *original_grid, const int N) {

    int count_blue_pieces = 0; int count_red_pieces = 0;
    count_pieces(original_grid,N,count_blue_pieces,count_red_pieces);
    // If the number of pieces differ more than 1, one player must played twice or more
    if (abs(count_blue_pieces - count_red_pieces) > 1) {
        return 'I';
    }
    
    // Copy the grid
    char *grid = copy_grid(original_grid,N);
    
    // Check for a winner
    char winner = check_winner(grid,N);
    if (winner == '.') {
        return 'N';
    }
    delete [] grid;

    // Impossible game condition
    if ((winner == 'B' && count_blue_pieces < count_red_pieces) ||\
       (winner == 'R' && count_red_pieces < count_blue_pieces))
        return 'I';
    
    // Check if the winner pathway is valid
    printf("Winner is: %c\n",winner);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (winner == original_grid[i*N+j]) {
                // Make a copy of the grid
                grid = copy_grid(original_grid,N);
                
                // Unset the current and check if the winner changes
                grid[i*N+j] = '.';
                char c_winner = check_winner(grid,N);
                printf("%d %d = %c\n",i,j,c_winner);
                if (c_winner == '.') {
                    if (winner == 'B')
                        return 'B';
                    else if (winner == 'R')
                        return 'R';
                }
                delete [] grid;
            }
        }
    }
    return 'I';
}

int main () {
    
    int T, N;
    scanf("%d",&T);
    for (int k = 0; k < T; k++) {
        // Read the grid
        scanf("%d",&N);
        char *grid = new char[N*N]();
        int counter_blues = 0;
        int counter_reds = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf(" %c",&grid[i*N+j]);
                if (grid[i*N+j] == 'B') counter_blues++;
                else if (grid[i*N+j] == 'R') counter_reds++;
            }
        }

        // Solve the problem
        char ans = solve_flood_fill(grid,N);

        // Output format
        switch (ans)
        {
            case 'B': printf("Case #%d: Blue wins\n",k+1);
                      break;
            case 'R': printf("Case #%d: Red wins\n",k+1);
                      break;
            case 'N': printf("Case #%d: Nobody wins\n",k+1);
                      break;
            case 'I': printf("Case #%d: Impossible\n",k+1);
                      break;
        }

        // Free memory
        delete [] grid;
    }
    return 0;
}