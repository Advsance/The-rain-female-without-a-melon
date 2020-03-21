


#include <map>
#include <iostream>
#include"HashTable.h"
using namespace std; 

#include<string>

struct ss
{
	int a = 11;
};

int main()
{
	

	hashTable<int, int> dd;
	pair<int, int> d(12, 3);
	dd.insert(pair<int, int>(1, 3));
	dd.insert(pair<int, int>(12, 8));
	dd.insert(pair<int, int>(10, 3));
	dd.insert(pair<int, int>(22, 18));
	int key = dd.Find(22);
	dd.erase(22);
}
