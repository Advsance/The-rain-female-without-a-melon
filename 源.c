# include"��ͷ.h"
# include<assert.h>
# include<malloc.h>
# include<stdio.h>
//�ڵ�ĳ�ʼ��
void SListInit(SList* s)
{
	assert(s);
	s->_pHead = NULL;
}
//�����µĽڵ�
PNode BuySListNode(SDataType data)
{
	PNode pNewNode =(PNode) malloc(sizeof(Node));  //malloc�����Ŀռ䷵��ָ��ΪNode*  ��Ҫת��ΪPNode
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->_data = data;
	pNewNode->_pNext = NULL;
	return pNewNode;
}
//ͷ��
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
//ͷɾ
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
//β��
void SListPushBack(SList* s, SDataType data)
{
	assert(s);
	PNode pNewNode = BuySListNode(data); //����һ���µĽڵ�
	if (NULL == s->_pHead)  //�������Ϊ�գ�����ͷ�ڵ�ֱ��ָ���½����Ľڵ�
	{
		s->_pHead = pNewNode;//ע����_phead����������ָ��pNweNode��Ҳ������ָ�� ���ǻ��໥ƥ��
	}
	else
	{
		PNode pCur = s->_pHead;//����һ������������Ѱ�� ����ָ���ֵ��Ϊһ���ڵ�
		while (pCur->_pNext)       //�������һ���ڵ�Ϊ��ʱͣ��
		{
			pCur=pCur ->_pNext;	//����д��pCur->_pNext;  ��������һֱ�ڶ�ȡ�Լ�����һ��Ԫ�� ��������һ������һ��Ԫ��
		}
		pCur->_pNext = pNewNode;
	}
}
//��ӡ����
void PritfSList(SList* s)
{
	assert(s);
	if (s->_pHead==NULL)
	{
		printf("NULL\n");
		return;
	}
	PNode pCur = s->_pHead;
			while (pCur)  //pCur->_pNext����д��  �������һ��Ԫ��  pCur��ʾ���ǵ�ǰԪ�� 
			{             //�������д�����ٴ�ӡһ��Ԫ��
				printf("%d----->", pCur->_data);
				pCur = pCur->_pNext;
			}
			printf("NULL\n");
}
//βɾ
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
	while (pCur->_pNext->_pNext)    //������һ��Ԫ�ص�ָ���ҵ�����һ��Ԫ��
	{
		pCur = pCur->_pNext;
	}
	free(pCur->_pNext );  //ɾ��ָ�����Ҫ�����Ϳ�
	pCur->_pNext = NULL;   //�ҵ�֮����ɾ��
}
//ɾ��ָ��λ�õĽڵ�
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
//ָ��λ�ò���ڵ�
void  SlistInsert(PNode pos,SDataType data)   //PNode ��ʾ����һ���ڵ��λ�� λ�ø���ڵ�ĵ�ַ������
{
	if (pos==NULL)                   	{
		return;
	}
	PNode pNewNode = BuySListNode(data);
	pNewNode->_pNext = pos->_pNext;
	pos->_pNext = pNewNode;
}
// �ҵ���Ԫ�ص�λ�ò�����ָ���Է�������ļ���
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
//����ڵ�ĸ���
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
//�����Ƿ�Ϊ��
int SListEmpty(SList* s)
{
	assert(s);
	return NULL == s->_pHead;
}
//�ڵ�pos��Ԫ�غ������ֵ
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
//ָ��λ��ɾ��Ԫ��
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
		pCur->_pNext = pCur->_pNext->_pNext;    //�˳������ʹ�õ��Ǵ����ڴ�й© ��Ҫ�޸� ©��һ���ڵ�
		free(D);
	}
	return;

}
//ɾ��ֵΪval��Ԫ��
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
//���Ժ���
void TestList2()
{
	SList S;
	SListInit(&S);
	SListPushBack(&S, 1);
	SListPushBack(&S, 3);
	SListPushBack(&S, 2);
	PritfSList(&S);
	printf("һ����%d\n",  SlistSize(&S));
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