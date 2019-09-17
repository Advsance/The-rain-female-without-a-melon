#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<malloc.h>
void test()
{
	string s1;
	cin >> s1;
	cout << s1.size() <<"  " <<s1.capacity()<<endl;
	string s2(s1);
	cout << s2 << endl;
	cout << s2.size() << endl;
	s2.resize(3213, 'a');
	cout << s2 << endl;
	s2.resize(1);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;
}

//��ȡ�ַ��������һ�����ʵĳ���

void GetlastWordSize()
{
	string s1 , s2;
	getline(cin, s1);
//	cin >> s2;    //ֻ�ܻ�ȡ���ո��β���ַ���
//	cout << s1 << endl;
	size_t pos = 0;
	pos= s1.rfind(' ');
	cout << pos << endl;
	cout << s1.size() -1-pos << endl;  //�൱���˸�0 size_t�����ֵ��1Ϊ0��
	cout << s1.size()<<endl;
	if (s1.empty())
		return;
	for (int i = pos+1; i < s1.size(); i++)
	{
		cout << s1[i];
	}
	cin >> s2;
	s1 = s1 + s2;
	cout << s1 << endl;
}

//duplication�ظ� 

//�����������ظ������֣������СΪN ���ַ�ΧΪ0��N-1
//1.�ҵ���i��Ԫ�أ���ô����ֵӦ�þ�Ϊi�������Ϊ��ô�ͺ�����ǰԪ�ص�x��xλ�õ�Ԫ�ؽ���
//����������ô�ͼ��������ߣ����
bool Duplicate(int* arr, int size, int* duplication)
{
	if (nullptr == arr || size < 0)
		return false;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < 0||arr[i]>size-1)
			return false;	
	}
	for (int i = 0; i < size; i++)
	{
		while (arr[i] != i)
		{
			if (arr[i] == arr[arr[i]])
			{
				*duplication = arr[i];
				return true;
			}
			swap(arr[i], arr[arr[i]]);
		}
	}
	return false;

}

void Qsort(vector<int>& arr, int left, int right)
{
	if (left > right)
		return;
	int i, j;
	i = left;
	j = right;
	while (i<j)
	{
		while (arr[left]<=arr[j] && i<j)
		{
			j--;
		}
		while (arr[left]>=arr[i] && i<j)
		{
			i++;
		}
		if(i<j)
		swap(arr[i], arr[j]);
	}
	swap(arr[left], arr[j]);
	Qsort(arr,left,i-1);
	Qsort(arr, i + 1, right);

}

//�쳣��� 1.����Ϊ�գ������е�Ԫ�ز���0��size-1��������
//ֱ������Ȼ�������ڵ�
bool Duplicate(vector<int>arr, int*Duplication)
{
	if (arr.empty())
		return false;
	Qsort(arr, 0, arr.size() - 1);
	 *Duplication =arr[0];
	for (int i=1; i < arr.size(); i++)
	{
		if (arr[i] == *Duplication)
			return true;
		else
		{
			*Duplication = arr[i];
		}
	}
	return false;
}

//����Ͱ�ŵ�˼��

bool DuplicateBucket(const vector<int>& arr,int* ret)
{
	if (arr.empty())
		return false;
	int* ar = (int*) calloc(arr.size(),4);
	for (int i = 0; i < arr.size() - 1; i++)
	{
		ar[arr[i]]++;
		if (ar[arr[i]] == 2)
		{
			*ret = arr[i];
			return true;
		}
	}
	return false;
}

int Coutrange(const int* number, int length, int start, int end)
{
	if (number == nullptr)
		return 0;
	
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (number[i] >= start && number[i] <= end)
			++count;
	}
	return count;
}

//����1��n���ռ��Сn+1��
int GetDuplication(const int* arr, int size)
{
	if (arr == nullptr || size <= 0)
		return -1;
	int start = 1;
	int end = size - 1;
	while (end >= start)
	{
		int middle = ((end - start) >> 1) + start;
		int count = Coutrange(arr, size, start, end);
		if (end == start)
		{
			if (count > 1)
				return start;
			else
			{
				break ;
			}
		}
		if (count > (end - start + 1))
		{
			end = middle;
		}
		else
		{
			start = middle + 1;
		}
	}
	return -1;
}


int main()
{
//	test();
//	GetlastWordSize();
	int arr[10] = { 0,9,8,7,6,5,4,3,1,1 };
	vector<int> ar = { 2,3,1,0,2,5,3 };
	int a=1;
	bool as = false;
	a=GetDuplication(arr, 11);
	cout <<"a" <<a << endl;
	as = Duplicate(arr, 10, &a);
	if (as)
		cout << a << endl;
	a = -1;
	as = Duplicate(ar, &a);
	if (as)
		cout << a << endl;
	a = -1;
	as = DuplicateBucket(ar, &a);
	cout << a << endl;

	system("pause");
	return 0;
}
