# include"标头.h"
# include<assert.h>
# include<malloc.h>
# include<stdio.h>
//节点的初始话
void SListInit(SList* s)
{
	assert(s);
	s->_pHead = NULL;
}
//创建新的节点
PNode BuySListNode(SDataType data)
{
	PNode pNewNode =(PNode) malloc(sizeof(Node));  //malloc创建的空间返回指针为Node*  需要转化为PNode
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->_data = data;
	pNewNode->_pNext = NULL;
	return pNewNode;
}
//头插
void SListPushFront(SList* s,SDataType data)
{
	assert(s);
	if (s->_pHead == NULL) {
		SListPushBack(s, data);
	}
	else
	{
	PNode pNewNode=	BuySListNode(data);
	pNewNode->_pNext = s->_pHead;
	s->_pHead = pNewNode;
	}
}
//头删
void  SListPopFront(SList* s)
{
	assert(s);
	if (NULL==s->_pHead)
	{
		return;
	}
	PNode pDelNode = s->_pHead;
	s->_pHead = s->_pHead->_pNext;
	free(pDelNode);
 }
//尾插
void SListPushBack(SList* s, SDataType data)
{
	assert(s);
	PNode pNewNode = BuySListNode(data); //创建一个新的节点
	if (NULL == s->_pHead)  //如果链表为空，则让头节点直接指向新建立的节点
	{
		s->_pHead = pNewNode;//注意在_phead里面有两个指针pNweNode中也有两个指针 他们会相互匹配
	}
	else
	{
		PNode pCur = s->_pHead;//创建一个变量用于需寻找 将其指针的值设为一个节点
		while (pCur->_pNext)       //搜索最后一个节点为空时停下
		{
			pCur=pCur ->_pNext;	//容易写出pCur->_pNext;  这样以来一直在读取自己的下一个元素 而不是下一个的下一个元素
		}
		pCur->_pNext = pNewNode;
	}
}
//打印函数
void PritfSList(SList* s)
{
	assert(s);
	if (s->_pHead==NULL)
	{
		printf("NULL\n");
		return;
	}
	PNode pCur = s->_pHead;
			while (pCur)  //pCur->_pNext容易写成  这个是下一个元素  pCur表示的是当前元素 
			{             //上面这个写法会少打印一个元素
				printf("%d----->", pCur->_data);
				pCur = pCur->_pNext;
			}
			printf("NULL\n");
}
//尾删
void SListPopBack(SList* s)
{
	assert(s);
	PNode pCur = s->_pHead;
	if (pCur==NULL)
	{
		return;
	}
	if (pCur->_pNext==NULL)
	{
		free(pCur);
		s->_pHead = NULL;
		return;
	}
	while (pCur->_pNext->_pNext)    //利用下一个元素的指针找到下下一个元素
	{
		pCur = pCur->_pNext;
	}
	free(pCur->_pNext );  //删除指针后需要将其滞空
	pCur->_pNext = NULL;   //找到之后将其删除
}
//删除指定位置的节点
void SListEarse(SList* s,PNode pos)
{
	assert(s);
	if (NULL==pos||NULL==s->_pHead)
	{
		return;
	}
	if (pos == s->_pHead)
	{
		s->_pHead = s->_pHead->_pNext;
	}
	else
	{
		PNode pPrePos = s->_pHead;
		while (pPrePos && pPrePos->_pNext!=pos)
		{
			pPrePos = pPrePos->_pNext;
		}
		if(pPrePos)
		pPrePos->_pNext = pPrePos->_pNext->_pNext;
	}
	free(pos);
}
  SListEarse1(SList* s, PNode pos)
{
	assert(s);
	if (NULL == pos || NULL == s->_pHead)
	{
		return;
	}
	if (pos == s->_pHead)
	{
		s->_pHead = s->_pHead->_pNext;
	}
	else
	{
		PNode pPrePos = s->_pHead;
		while (pPrePos && pPrePos->_pNext != pos)
		{
			pPrePos = pPrePos->_pNext;
		}
		if (pPrePos)
			pPrePos->_pNext = pPrePos->_pNext->_pNext;
	}
	free(pos);
	return s;
}
//指定位置插入节点
void  SlistInsert(PNode pos,SDataType data)   //PNode 表示的是一个节点的位置 位置给后节点的地址就有了
{
	if (pos==NULL)                   	{
		return;
	}
	PNode pNewNode = BuySListNode(data);
	pNewNode->_pNext = pos->_pNext;
	pos->_pNext = pNewNode;
}
// 找到该元素的位置并返回指针以方便下面的计算
PNode SListFind(SList* s, SDataType data)
{
	assert(s);
	PNode pCur = s->_pHead;
	while (pCur)
	{
		if (pCur->_data == data)
		{
			return pCur;
		}
		pCur = pCur->_pNext;
	}
	return NULL;
}
//计算节点的个数
size_t SlistSize(SList* s)
{
	assert(s);
	PNode pCur = s->_pHead;
	size_t count = 0;
	while (pCur)
	{
		count++;
		pCur = pCur->_pNext;
	}
	return count;
}
//检验是否为空
int SListEmpty(SList* s)
{
	assert(s);
	return NULL == s->_pHead;
}
//在第pos号元素后面插入值
void SListInsertq(PSList s, int pos, SDataType data)
{
	assert(s);
	if (pos >= 0 && pos <= (SlistSize(s)))
	{
		PNode NewNode = BuySListNode(data);
		if (pos == 0)
		{
			SListPushFront(s, data);
				return;
		}
		else
		{
			PNode pCur = s->_pHead;
			for (int i = 1; i < pos; i++)
			{
				pCur = pCur->_pNext;
			}
			NewNode->_pNext = pCur->_pNext;
			pCur->_pNext = NewNode;
		}
	}
	return;
}
//指定位置删除元素
void SListD(PSList s, int pos)
{
	assert(s);
	if (pos>=1&&pos<=SlistSize(s))
	{
		if (pos==1)
		{
			SListPopFront(s);
			return;
		}
		PNode pCur = s->_pHead;
		for (int i = 1; i < pos-1; i++)
		{
			pCur = pCur->_pNext;
		}
		PNode D = pCur;
		pCur->_pNext = pCur->_pNext->_pNext;    //此程序可以使用但是存在内存泄漏 需要修改 漏了一个节点
		free(D);
	}
	return;

}
//删除值为val的元素
void SlistDval(PSList s,SDataType val) {
	assert(s);
	PNode pCur = s->_pHead;
	
	while (pCur)
	{
		if (pCur->_data == val)
		{
		pCur=SListEarse1(s, pCur);
		}
		else
		{
			pCur = pCur->_pNext;
		}
	}
}
//测试函数
void TestList2()
{
	SList S;
	SListInit(&S);
	SListPushBack(&S, 1);
	SListPushBack(&S, 3);
	SListPushBack(&S, 2);
	PritfSList(&S);
	printf("一共有%d\n",  SlistSize(&S));
	SListEarse(&S, SListFind(&S, 2));
	PritfSList(&S);
	SlistInsert(SListFind(&S,3), 6);
	PritfSList(&S);
	SListInsertq(&S, 1, 5);
	PritfSList(&S);
	SListInsertq(&S, 99, 99);
	PritfSList(&S);
	SListInsertq(&S, 0, 99);
	PritfSList(&S);
	//SListD(&S, 2);
	PritfSList(&S);
	SlistDval(&S, 99);
	PritfSList(&S);
}
void TestList()
{
	printf("\n\n\n");
	TestList2();
}
void Test3()
{

	size_t a;
	SList  a;
	SListInit(&a);
	SListPushBack(&a, 1);
	a=SlistSize(&a);
	printf("%d", a);
	PritfSList(&a);
}
int main(void)
{
//	Test3();
	char *a = "sa";
	print("%c", a);
	system("pause");
	return 0;
}