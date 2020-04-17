
#include <iostream>
#include <stdlib.h>

class test {
public:
	int a;
	static int geta()
	{
		return 0;
	}

	int grt()
	{
		return 2;
	}



};


int main()
{
	test* i = (test*)malloc(sizeof(test));
    std::cout << "Hello World!\n"; 
}
