#include<assert.h>
#include<malloc.h>
typedef int HeapDataType;
#include <iostream>
using namespace std;

typedef struct Heap
{
	HeapDataType* _array;
	size_t _size;
	size_t _cap;
	~Heap() {
		if (_array)
			free(_array);
	}
}Heap;




void ADjustDown(Heap& hp,int size,int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size&&hp._array[child] > hp._array[child + 1])
			child += 1;
		if ((hp._array[parent] >hp._array[child]))
		{
			swap(hp._array[child], hp._array[parent]);
			parent = child;
			child = child * 2 + 1;
		}
		else
		{
			return;
		}
	}
}
//��ָ�룬ָ��Ҳֻ�ǿ���
void initHeap(Heap& hp,HeapDataType* arr, int size)
{
	cout << arr << endl;
	cout << &hp._size << endl;
	hp._array = (HeapDataType*)malloc(sizeof(HeapDataType)*size);
	if (hp._array == nullptr)
	{
		assert(0);
		return;
	}
	for (int i = 0; i < size; i++)
	{
		hp._array[i] = arr[i];
	}
	hp._cap = size;
	hp._size = size;
	//�ҵ�����һ��Ҷ�ӽڵ�
	int leatLeaf = ((size - 2) >> 1);
	for(;leatLeaf>=0;leatLeaf--)
	{
		ADjustDown(hp,size, leatLeaf);
	}
	
}

//����
void Dilatation(Heap& ph)
{
	HeapDataType* pCur = (HeapDataType*)malloc(sizeof(HeapDataType) * 2*ph._cap);
	if (nullptr == pCur)
	{
		assert(0);
		return;
	}
	for (int i = 0; i < ph._size; i++)
	{
		pCur[i] = ph._array[i];
	}
	free(ph._array);
	ph._array = nullptr;
	ph._array = pCur;
	ph._cap = ph._cap * 2;
}

//�ѵ����ϵ���������ר��

void ADjustUP(HeapDataType* arr, int size,int child )
{
	if (nullptr == arr)
		return;
	
	while (child)
	{
		int parent = (child - 1) / 2;
		if ((arr[child] < arr[parent]))
		{
			swap(arr[child], arr[parent]);
			child = parent;
		}
		else
		{
			return;
		}
	}
}
//�ѵĲ��룬���ڵײ���˳��ṹ����ôͷ���Ƿǳ�������ġ����Բ���β����Ȼ���ڽ������ϵ���
void InsertHeadp(Heap& ph, HeapDataType arr)
{
	//���û�����������ݰ�
	if (ph._size == ph._cap)
		Dilatation(ph);
	ph._array[ph._size] = arr;
	ph._size++;
	ADjustUP(ph._array, ph._size, ph._size - 1);
}

// ɾ���Ѷ�Ԫ��
void ErasureHeadp(Heap& ph)
{
	if (ph._size == 0)
		return;
	swap(ph._array[0], ph._array[ph._size - 1]);
	ph._size -= 1;
	ADjustDown(ph, ph._size, 0);
}

void PrintfHead(const Heap& h)
{
	for (int i = 0; i < h._size; i++)
	{
		cout << h._array[i] << "  ";
	}
	cout << endl;
}

void test()
{
	Heap h;
	h._size = 1;
	cout << &h << endl;
	cout << &h._size << endl;
	int arr[] = { 7,3,4,2,5,8,1,6 };
	cout << arr << endl;
	initHeap(h, arr, sizeof(arr) / sizeof(arr[0]));
	PrintfHead(h);
	cout << "�ѵ�����Ϊ��" << h._cap << "����Ԫ��Ϊ��" << h._size << endl;
	ErasureHeadp(h);
	PrintfHead(h);
	cout << "�ѵ�����Ϊ��" << h._cap << "����Ԫ��Ϊ��" << h._size << endl;
	InsertHeadp(h, 0);
	InsertHeadp(h, -1);
	PrintfHead(h);
	cout << "�ѵ�����Ϊ��" << h._cap << "����Ԫ��Ϊ��"<<  h._size << endl;
}

//������
void ADjustDown2(int* arr ,int parent ,int size) {
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size&&arr[child] > arr[child + 1])
		{
			child += 1;
		}
		if (arr[parent] > arr[child])
		{
			swap(arr[parent], arr[child]);
			parent = child;
			child = child * 2 + 1;
		}
		else
		{
			return;
		}
	}
}

void SorkHeap(int* arr, int size) {
	if (nullptr == arr || size <= 0)
		return;
	int pRoot = ((size - 2) / 2);
	for (; pRoot >= 0; pRoot--)
	{
		ADjustDown2(arr, pRoot, size);
	}
	int end = size - 1;
	while (end)
	{
		swap(arr[0], arr[end]);
		ADjustDown2(arr,0 ,end);
		end--;
	}
}

void test2()
{
	int arr[] = { 12,4,5,2,4,1,5,5,7,3,2,34,1 };
	SorkHeap(arr, 13);
	for (int i = 0; i < 13; i++)
	{
		cout << arr[i] << "  ";
	}
}


int main()
{
	test2();
	system("pause");
	return 0;
}

