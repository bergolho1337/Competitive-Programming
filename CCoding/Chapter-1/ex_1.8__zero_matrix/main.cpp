/*
 * Chapter 1: Arrays and Strings
 *	Write an algorithm such that if an element in a MxN matrix is 0,
 * its entire row and column are set to 0.
*/

#include <bits/stdc++.h>

using namespace std;

// Generate a random number between [min,max]
static inline int rand_range (int min_value, int max_value) {
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> distribution(min_value,max_value);
	return distribution(mt);
}

void print_matrix (int m[], const int nlin, const int ncol) {
	for (int i = 0; i < nlin; i++) {
		for (int j = 0; j < ncol; j++) {
			printf("%d ",m[i*ncol+j]);
		}
		printf("\n");
	}
	printf("\n");
}

void generate_matrix (int m[], const int nlin, const int ncol) {
	for (int i = 0; i < nlin; i++) {
		for (int j = 0; j < ncol; j++) {
			m[i*ncol+j] = rand_range(0,9);
		}
	}
}

// Solution: O(n^2)
void zero_matrix (int m[], const int nlin, const int ncol, int zm[]) {
	bool zlin[nlin];
	bool zcol[ncol];
	memset(zlin,false,sizeof(bool)*nlin);
	memset(zcol,false,sizeof(bool)*ncol);
	memcpy(zm,m,sizeof(int)*nlin*ncol);
	
	// Tag the lines and coluns that will be zero
	for (int i = 0; i < nlin; i++) {
		for (int j = 0; j < ncol; j++) {
			if (m[i*ncol+j] == 0) {
				zlin[i] = true;
				zcol[j] = true;
			}
		}
	}
	// Lines
	for (int i = 0; i < nlin; i++) {
		if (zlin[i]) {
			for (int k = 0; k < ncol; k++)
				zm[i*ncol+k] = 0;
		}
	}
	// Columns
	for (int j = 0; j < ncol; j++) {
		if (zcol[j]) {
			for (int k = 0; k < nlin; k++)
				zm[k*ncol+j] = 0;
		}
	}
}

int main () {
	int nlin = 3;
	int ncol = 3;
	int m[9] = {1,2,3,4,5,6,7,8,9};
	print_matrix(m,nlin,ncol);
	
	int zm[9];
	zero_matrix(m,nlin,ncol,zm);
	print_matrix(zm,nlin,ncol);
	
	nlin = 10;
	ncol = 10;
	int m2[100];
	generate_matrix(m2,nlin,ncol);
	print_matrix(m2,nlin,ncol);
	
	int zm2[100];
	zero_matrix(m2,nlin,ncol,zm2);
	print_matrix(zm2,nlin,ncol);
	
	return 0;
}
