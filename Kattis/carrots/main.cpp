#include <iostream>
#include <string>

int main () {
	int N, P;
	std::string description;
	scanf("%d %d",&N,&P);
	for (int i = 0; i < N; i++) {
		std::getline(std::cin,description);
	}
	printf("%d\n",P);
	return 0;
}
