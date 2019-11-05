#include<iostream>
#include<vector>
using namespace std;
#include<queue>
#include<stack>
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

// 二叉树的层序遍历
class Solution1 {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		if (root == nullptr)
			;
		vector<int> retur;
		queue<TreeNode*> re;
		re.push(root);
		while (re.size())
		{
			TreeNode* temp;
			temp = re.front();
			re.pop();
			retur.push_back(temp->val);
			if (temp->left)
			{
				re.push(temp->left);
			}
			if (temp->right)
			{
				re.push(temp->right);
			}
		}
		return retur;
	}
};

// 按行打印二叉树
class Solution2 {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int> > re;
		if (pRoot == nullptr)
			return re;
		queue<TreeNode*> nodes;
		nodes.push(pRoot);
		int layer = 0;
		int substrate = 1;
		vector<int> transit;
		while (nodes.size())
		{
			TreeNode* temp = nodes.front();
			nodes.pop();
			transit.push_back(temp->val);
			if (temp->left)
			{
				nodes.push(temp->left);
				layer++;
			}
			if (temp->right)
			{
				nodes.push(temp->right);
				layer++;
			}
			substrate--;
			if (substrate == 0)
			{
				re.push_back(transit);
				transit.erase(transit.begin(), transit.end());
				substrate = layer;
				layer = 0;
			}
		}
		return re;
	}

};


// 之字型打印二叉树
class Solution3 {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int> > re;
		if (pRoot == nullptr)
			return re;
		int current = 0;
		int next = 1;
		stack<TreeNode*> temp[2];
		temp[current].push(pRoot);
		vector<int> transit;
		while (temp[1].size() || temp[0].size())
		{
			TreeNode* pCur = temp[current].top();
			temp[current].pop();
			transit.push_back(pCur->val);
			if (current == 0)
			{
				if (pCur->left)
					temp[next].push(pCur->left);
				if (pCur->right)
					temp[next].push(pCur->right);
			}
			else
			{
				if (pCur->right)
					temp[next].push(pCur->right);
				if (pCur->left)
					temp[next].push(pCur->left);
			}
			if (!temp[current].size())
			{
				re.push_back(transit);
				transit.erase(transit.begin(), transit.end());
				current = 1 - current;
				next = 1 - next;
			}
		}
		return re;
	}

};

// 连续数组中最大连续数字之和
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int max = 0;
		if (!array.size())
		{
			return max;
		}
		int temp = max = array[0];
		for (int i = 1; i < array.size(); i++)
		{
			if (temp < 0)
			{
				temp = array[i];
			}
			else
			{
				temp += array[i];
			}
			if (temp > max)
			{
				max = temp;
			}
		}
		return max;
	}
};


// 离目标近了