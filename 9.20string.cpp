#include<string>
#include<iostream>
using namespace std;
#define max( a, b) ((a)>(b)?(a):(b))
#include<vector>
#if 0

typedef struct
{
	int a;
	int p[0];
};

int fun(int x, int y)
{
	return x + y;
}


int main()
{
	int arr[10] = { 1,2,2,4,6,3,2,4,6,7 };
	int i = 1;
	int big = arr[0];
	while (i < 10)
	{
		big = max(big, arr[i++]);
	}
	
	cout << big;
	int* x(int x, int y);
	system("pause");
	return 0;
}
#endif


//vector 
//ԭ������ ++i��i++ ûɶ̫����죬������շ���ֵ�Ļ���ô�ͻ��С����������Ż�
//�����ԭ������û��̫����
void ittset() {
	
	vector<int> v = { 1,2,3,4,5,6,7,8,9 };
	vector<int> v1 = {99,99,99};
	auto vi = v.begin() + 1;
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	v.erase(pos);
	cout << v.capacity() << endl;
	cout << *pos << endl;
	cout << *vi<<endl;
	vi = v.erase(vi);
	cout << *vi << endl;
	vi=v.insert(v.begin() + 1, v1.begin(), v1.end());
	cout << *vi++ << endl;
	cout << *vi++ << endl;
	cout << ++*vi << endl;
	//insdert �� erase ���ᵼ�µ�����ʧЧ ��ô���Ի�ȡ��ķ���ֵ,��ȡ�ķ���ֵΪ����֮���λ�á�
}
//


//�������
int _main() {

# if 0
	vector<int> arr = {1,2,4,3,5,3,4};
	for (auto& i : arr)
	{
		cout << i << " ";
	}
	cout << endl;
	auto temp = arr.end();
	vector<int> ae= { 1,2,3 };
// insert �ķ���3�ַ��� 
	//arr.insert(temp,ae);
  //   arr.insert(arr.begin()+1,100);
//	 arr.insert(arr.begin()+5,3,20);//��3��20
	 arr.insert(arr.begin() + 1, arr.rbegin(),arr.rend());
	 for (auto& i : arr)
	 {
		 cout << i << " ";
	 }
#endif
//������ʧЧ
//insert��eraseҲ�ᵼ�µ�����ʧЧ
	 ittset();
	 system("pause");
	 return 0;
}
void Printf(vector<int> a)
{
	for (auto& i : a)
	{
		cout << i << " ";
	}
}

void constructor()
{
	//���������ֹ��췽ʽ
	vector<int> ar1{ 1,2,3,4,5,6,7,8,9 };
	vector<int> ar2(ar1.begin(), ar1.end());
	vector<int> ar3(10, 1);
	Printf(ar2);
	Printf(ar3);
}

void iterator1()
{
	vector<int> ar1{ 1,2,3,4,5,6,7,8,9 };
	auto vi1 = ar1.begin();
	auto vi2 = ar1.end();
	auto vi3 = ar1.rbegin();
	auto vi4 = ar1.rend();
	cout << *vi1 << endl;
	cout << *vi2 << endl;
	cout << *vi3 << endl;
	cout << *vi4 << endl;
}

void Testalter()
{
	vector<int> ar1{ 1,2,3,4,5,6,7,8,9 };
	cout << ar1.capacity() << endl;
	ar1.reserve(40);
	cout << ar1.capacity()<<endl;
	cout << ar1.size() << endl;
	ar1.resize(20);
	cout << ar1.size() << endl;
	Printf(ar1);
	cout << endl;
	ar1.resize(50, 99);
	Printf(ar1);
}


int MoreThanHalfNum_Solutison(vector<int> numbers) {
	int val = numbers[0];
	int count = 1;
	int i = 1;
	for (i = 1; i < numbers.size(); i++)
	{
		if (numbers[i] == val)
		{
			count++;
		}
		else
		{
			if (count <= 1)
			{
				val = numbers[i];
			}
			else
			{
				count--;
			}
		}
	}
	count = 0;
	for (i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == val)
			count++;
	}
	if (count > numbers.size() / 2)
		return val;
	else
		return 0;
}

int main()
{
	//constructor();
	//iterator1();
	//Testalter();
	ittset();
	system("pause");
}