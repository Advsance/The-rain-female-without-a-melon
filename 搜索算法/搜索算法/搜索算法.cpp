#include <iostream>
#include <vector>
using namespace std;

//DFS 深度优先算法


void DFS_1(vector<int>& box, vector<int>& book, int n, int index);

void DFS(int index, vector<int>& book, vector<int>boxs, int n)
{
	if (index == n + 1)
	{
		for (int i = 1; i <= n; i++)
		{
			cout << boxs[i] << " ";
		}
		cout << endl;

		return ;
	}

	for (int i = 1; i <= n; i++)
	{
		if (book[i] == 0)
		{
			book[i] = 1;
			boxs[index] = i;
			DFS(index+1, book, boxs, n);
			book[i] = 0;
		}
	}
}

void test_DFS()
{
	vector<int> book;
	vector<int> boxs;

	int n;
	cin >> n;
	book.resize(n + 1, 0);
	boxs.resize(n + 1, 0);
	DFS_1(book, boxs, n, 1);
}

int a = 0;





void DFS_1(vector<int>& box, vector<int>& book, int n, int index)
{
	if (index == n + 1)
	{
		for (int i = 1; i <= n; i++)
		{
			cout << box[i] << " ";
		}

		cout << endl;
		a++;
		return;
	}


	for (int i = 1; i <= n; i++)
	{
		if (book[i] == 0)
		{
			box[index] = i;
			book[i] = 1;
			DFS_1(box, book, n, index + 1);
			book[i] = 0;
		}
	}
}

/*
给定一个保存员工信息的数据结构，它包含了员工唯一的id，重要度 和 直系下属的id。

比如，员工1是员工2的领导，员工2是员工3的领导。他们相应的重要度为15, 10, 5。那么员工1的数据结构是[1, 15, [2]]，
员工2的数据结构是[2, 10, [3]]，员工3的数据结构是[3, 5, []]。注意虽然员工3也是员工1的一个下属，但是由于并不是直系下属，
因此没有体现在员工1的数据结构中。

现在输入一个公司的所有员工信息，以及单个员工id，返回这个员工和他所有下属的重要度之和。

示例 1:

输入: [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
输出: 11
解释:
员工1自身的重要度是5，他有两个直系下属2和3，而且2和3的重要度均为3。因此员工1的总重要度是 5 + 3 + 3 = 11。


注意:


	一个员工最多有一个直系领导，但是可以有多个直系下属
	员工数量不超过2000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/employee-importance
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include<map>
#include<unordered_map>
// Employee info
class Employee {
public:
	// It's the unique ID of each node.
	// unique id of this employee
	int id;
	// the importance value of this employee
	int importance;
	// the id of direct subordinates
	vector<int> subordinates;
};

class Solution {
public:
	void DFS(unordered_map<int, Employee*> info, int& sum, int id)
	{
		sum += info[id]->importance;
		for (auto& subid : info[id]->subordinates)
		{
			DFS(info, sum, subid);
		}
	}

	int getImportance(vector<Employee*> employees, int id) {
		if (employees.empty())
			return 0;
		
		unordered_map<int, Employee*> info;
		for (auto& a : employees)
		{
			info[a->id] = a;
		}
		int sum = 0;
		DFS(info, sum, id);
		return sum;
	}
};



/*
有一幅以二维整数数组表示的图画，每一个整数表示该图画的像素值大小，数值在 0 到 65535 之间。
给你一个坐标 (sr, sc) 表示图像渲染开始的像素值（行 ，列）和一个新的颜色值 newColor，让你重新上色这幅图像。
为了完成上色工作，从初始坐标开始，记录初始坐标的上下左右四个方向上像素值与初始坐标相同的相连像素点，接着再记录这四个方向上符合条件的像素点与他们对应四个方向上像素值与初始坐标相同的相连像素点，……，重复该过程。将所有有记录的像素点的颜色值改为新的颜色值。
最后返回经过上色渲染后的图像。
示例 1:
输入:
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
输出: [[2,2,2],[2,2,0],[2,0,1]]
解析:
在图像的正中间，(坐标(sr,sc)=(1,1)),
在路径上所有符合条件的像素点的颜色都被更改成2。
注意，右下角的像素没有更改为2，
因为它不是在上下左右四个方向上与初始点相连的像素点。
注意:
image 和 image[0] 的长度在范围 [1, 50] 内。
给出的初始点将满足 0 <= sr < image.length 和 0 <= sc < image[0].length。
image[i][j] 和 newColor 表示的颜色值在范围 [0, 65535]内。
https://leetcode-cn.com/problems/flood-fill/

*/
class Solution_9 {
public:
	void DFS(vector<vector<int>>& image, int sr, int sc, int newColor, int n)
	{
		image[sr][sc] = newColor;
		int direction[4][2] = { {1,0},{0,-1},{-1,0},{0,1} };

		for (int i = 0; i < 4; i++)
		{
			int srr = sr + direction[i][0];
			int scc = sc + direction[i][1];

			if (srr >= 0 && srr < image.size() && scc >= 0 && scc < image[0].size())
			{
				if (image[srr][scc] == n)
				{
					DFS(image, srr, scc, newColor, n);
				}
			}
		}
	}

	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		if (image.empty())
			return image;
		
		if (image[sr][sc] == newColor)  // 防止颜色相同 进行导致死循环
			return image;
		DFS(image, sr, sc, newColor, image[sr][sc]);
		return image;
	}
};

/*
给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
示例:
X X X X
X O O X
X X O X
X O X X
运行你的函数后，矩阵变为：
X X X X
X X X X
X X X X
X O X X
解释:
被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。
任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。
如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。

*/

class Solution_1 {
public:
	int direction[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
	void DFS_o(vector<vector<char>>& board, int sr, int cr)
	{ 
		board[sr][cr] = 'p';

		for (int i = 0; i < 4; i++)
		{
			int srr = sr + direction[i][0];
			int crr = cr + direction[i][1];

			if (srr >= 0 && srr < board.size() && crr >= 0 && board[srr].size())
			{
				if(board[srr][crr]=='O')
				DFS_o(board, srr, crr);
			}
		}
	}

	void solve(vector<vector<char>>& board) {
		for (int i = 0; i < board.size(); i++)
		{
			if (board[i][0] == 'O')
				DFS_o(board, i,0);
			if (board[i][board[i].size() - 1] == 'O')
				DFS_o(board, i, board[i].size() - 1);
		}

		for (int i = 0; i < board[0].size(); i++)
		{
			if (board[0][i] == 'O')
				DFS_o(board, 0, i);
			if (board[board.size() - 1][i] == 'O')
				DFS_o(board, board.size() - 1, i);
		}

		for (int i = 0; i < board.size(); i++)
		{
			for (int y = 0; y < board[i].size(); y++)
			{
				if (board[i][y] == 'p')
					board[i][y] == 'O';
				else
				{
					board[i][y] == 'X';
				}
			}
		}
	}
};

int main()
{
	test_DFS();
	cout << a;
	return 0;
}


