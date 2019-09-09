#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include<queue>
struct BTNode {
	BTNode(int data)
		:_pleft(nullptr)
		,_pRight(nullptr)
		,_data(data)
	{}
	BTNode* _pleft;
	BTNode* _pRight;
	int _data;
};
//����ǰ��ķ������еĶ���������
BTNode* CreateBinTree(const vector<int>& v,int& index ,const int vain)
{
	BTNode* pRoot = nullptr;
	while (index < v.size() && v[index] != vain)
	{
		pRoot = new BTNode(v[index]);
		pRoot->_pleft = CreateBinTree(v,++index,vain);
		pRoot->_pRight = CreateBinTree(v, ++index, vain);
	}
	return pRoot;
}

//ǰ����� д������ 
void Preorder(BTNode* pRoot)
{
	if (pRoot)
	{
		cout << pRoot->_data << "  "; //����ͺ���ֻ������_data��λ�ò�ͬ
		Preorder(pRoot->_pleft);
		Preorder(pRoot->_pRight);
	} 
}

//ǰ��ǵݹ� 
void PreOrderNor(BTNode* pRoot)
{
	if (nullptr == pRoot)
	{
		return;
	}
	stack<BTNode*> S;
	BTNode* pCur;
	S.push(pRoot);
	while (!S.empty())
	{
		pCur = S.top();
		cout << pCur->_data << "  ";
		S.pop();

		if (pCur->_pRight)
			S.push(pCur->_pRight);
	
		if (pCur->_pleft)
			S.push(pCur->_pleft);
	}
}

//����ǵݹ�
void InOrderNor(BTNode* pRoot)
{
	if (nullptr == pRoot)
		return;
	stack<BTNode*> S;
	BTNode* pCur=pRoot;
	while (pCur != nullptr || !S.empty())
	{
		while (pCur)
		{
			S.push(pCur);
			pCur=pCur->_pleft;
		}
		pCur = S.top();
		S.pop();
		cout << pCur->_data << "  ";
		pCur = pCur->_pRight;
	}
}

//�������������
void LevelOrder(BTNode* pRoot)
{
	if (nullptr == pRoot)
		return;
	queue<BTNode*> Q;
	BTNode* pCur;
	Q.push(pRoot);
	while (!Q.empty())
	{
		pCur = Q.front();
		Q.pop();
		cout << pCur->_data << "  ";
		if (pCur->_pleft)
			Q.push(pCur->_pleft);

		if (pCur->_pRight)
		Q.push(pCur->_pRight);
	}
}

//��ȡ�������߶�

size_t GetMaxHeight(BTNode* pRoot)
{
	if (nullptr == pRoot)
		return 0;
	size_t leftHeight=GetMaxHeight(pRoot->_pleft);
	size_t rigthHeight=GetMaxHeight(pRoot->_pRight);
	return leftHeight > rigthHeight ? leftHeight + 1 : rigthHeight + 1;
}

//��ȡ���Ľڵ����

size_t GetTreeNodeSize(BTNode* pRoot)
{
	if (nullptr == pRoot)
		return 0;
	return GetTreeNodeSize(pRoot->_pleft) + GetTreeNodeSize(pRoot->_pRight) + 1;
}

//��ȡ��K��ڵ����

size_t GetKLeveNodeCount(BTNode* pRoot, size_t K)
{
	if (nullptr == pRoot || 0 == K)
		return 0;
	if (1 == K)
		return 1;
	return GetKLeveNodeCount(pRoot->_pleft,K-1) + GetKLeveNodeCount(pRoot->_pRight,K-1);
}

//��ȡһ���ӽڵ�ĸ��ڵ�
BTNode* GetParent(BTNode* pRoot, BTNode* RNode)
{
	if (nullptr == pRoot || nullptr == RNode)
		return nullptr;
	
	if (pRoot->_pleft == RNode || pRoot->_pRight == RNode)
		return pRoot;
	
	BTNode* Parent = GetParent(pRoot->_pleft,RNode);
	
	if (Parent)
		return Parent;
	Parent = GetParent(pRoot->_pRight, RNode);
}

//�˴�Ҫ������ ����������ã���Ϊ�β�ֻ��ʵ�εĿ���
//��ôֻ���βε�ָ������Ϊ�գ������Ⲣû�б��ÿջᵼ�´��������
void Destoy(BTNode*& pRoot)
{
	if (pRoot)
	{
		Destoy(pRoot->_pleft);
		Destoy(pRoot->_pRight);
		delete pRoot;
		pRoot = nullptr;
	}
}


int main()
{
	vector<int> v = {5,3,2,1,-1,-1,-1,4,-1,-1,6,-1,10,9,-1,-1,11,-1,-1};
	int index = 0;
	BTNode* s = CreateBinTree(v, index, -1);
	Preorder(s);
	cout << endl;
//	Destoy(s);
//	Preorder(s);
    PreOrderNor(s);
	cout << endl;
	LevelOrder(s);
	cout << endl;
	cout << GetMaxHeight(s)<< endl;
	cout << endl;
	cout << GetTreeNodeSize(s) << endl;
	cout << endl;
	cout << GetKLeveNodeCount(s, 9)<< endl;
	cout << GetKLeveNodeCount(s, 3) << endl;
	BTNode* temp = GetParent(s, s->_pleft->_pleft);
	cout << endl;
	cout << temp->_data << endl;
    Preorder(s);
	cout << endl;
	InOrderNor(s);
	system("pause");
	return 0;
}