#include<iostream>
#include<vector>
using namespace std;

void Print(vector<int>& arr)
{
	static int temp = 0;
	for (auto i : arr)
		cout << i << " " ;
	temp++;
	cout << endl << "第" << temp << "次打印" << endl;
	return;
}


// 时间复杂度 N平方  空间复杂度 O(n)
void ReorderOddEven(vector<int>& arr)
{
	vector<int> temp1;
	for (int i = 0; i < arr.size(); )
	{
		if (arr[i] % 2)
		{
			i++;
			continue; 
		}
		else
		{
			temp1.push_back(arr[i]);
			int temp = i;
			while (temp < arr.size()-1)
			{
				arr[temp] = arr[temp + 1];
				temp++;
			}
			arr.resize(arr.size() - 1);
		}
		
	}
	for (int i = 0; i < temp1.size(); i++)
	{
		arr.push_back(temp1[i]);
	}
}

//指针交换

void ONReorderOddEven(vector<int>& arr)
{
	auto pBegin = arr.begin();
	auto pEnd = arr.end() - 1;
	while (pBegin < pEnd)
	{
		while (pBegin<pEnd&&(*pBegin & 0x1)!=0)
		{
			pBegin++;
		}
		while (pBegin < pEnd&&(*pEnd & 0x1)==0)
		{
			pEnd--;
		}
		if (pBegin < pEnd)
		{
			swap(*pBegin, *pEnd);
		}
	}
}

int main()
{
	vector<int> arr = { 2,4,6,1,3,5,7 };
	ReorderOddEven(arr);
	Print(arr);
//	ONReorderOddEven(arr);
	Print(arr);
	system("pause");
	return 0;
}



struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
}; 
class Solution {
public:

	// 子树的结构 看B是不是A的一个子树
	bool DoesTree1HaveTree2(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot1 == nullptr)
			return false;
		if (pRoot2 == nullptr)
			return true;
		if (!Equal(pRoot1->val, pRoot2->val))
		{
			return false;
		}
		return DoesTree1HaveTree2(pRoot1->left, pRoot2->left) &&
			DoesTree1HaveTree2(pRoot1->right, pRoot2->right);

	}

	bool Equal(double num1, double num2)
	{
		if ((num1 - num2) < 0.0000001)
		{
			return true;
		}
		else
			return false;
	}

	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool result = false;
		if (pRoot1 != nullptr&&pRoot2 != nullptr)
		{
			if (Equal(pRoot1->val, pRoot2->val))
			{
				result = DoesTree1HaveTree2(pRoot1, pRoot2);
			}
			if (!result)
			{
				result = HasSubtree(pRoot1->left, pRoot2);
			}
			if (!result)
			{
				result = HasSubtree(pRoot1->right, pRoot2);
			}
		}
		return result;
	}

	//给一棵树 求这棵二叉树的镜像
	void Mirror(TreeNode *pRoot) {
		if (pRoot == nullptr)
			return;
		if (pRoot->left == nullptr&&pRoot->right == nullptr)
			return;
		TreeNode* temp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = temp;
		Mirror(pRoot->left);
		Mirror(pRoot->right);
	}
	

	// 判断一颗二叉树的镜像登不等于自己的镜像
	bool isSymmetrical(TreeNode* pRoot)
	{
		return isSymmetrical(pRoot, pRoot);
	}
private:
	bool isSymmetrical(TreeNode* pRoot1,TreeNode* pRoot2)
	{
		if (pRoot1 == nullptr&&pRoot2 == nullptr)
			return true;
		if (pRoot1 == nullptr || pRoot2 == nullptr)
			return false;
		if (pRoot1->val != pRoot2->val)
		{
			return false;
		}
		return isSymmetrical(pRoot1->left, pRoot2->right) &&
			isSymmetrical(pRoot1->right, pRoot2->left);
	}
};

