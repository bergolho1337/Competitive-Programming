#include <iostream>
#include <string>

int main () {
	std::string str;
	std::getline(std::cin,str);
	printf("Thank you, %s, and farewell!\n",str.c_str());
	return 0;
}
