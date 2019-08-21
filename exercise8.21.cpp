#include<iostream>
using namespace std;
#include<string>

int main() {
	string A;
	getline(cin , A);
	cout << A;
	system("pause");
	return 0;

 struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		// if(head==nullptr) return nullptr;
		ListNode* pcur = new ListNode(-1);
		pcur->next = nullptr;
		ListNode* re = head;
		ListNode* temp;
		while (re)
		{
			temp = re;
			re = re->next;
			temp->next = pcur->next;
			pcur->next = temp;
		}
		return pcur->next;
	}
};

class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		if (head == nullptr) return nullptr;
		vector<ListNode*> temp = { head };
		ListNode* p = head;
		while (p->next != nullptr)
		{
			temp.push_back(p->next);
			p = p->next;
		}
		return temp[temp.size() / 2];
	}
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* pcur = new ListNode(-1);
		pcur->next = head;
		ListNode* p1 = pcur;
		ListNode* p2 = NULL;
		while (p1->next != nullptr)
		{
			if (p1->next->val == val)
			{
				p2 = p1->next;
				p1->next = p1->next->next;
				delete p2;
			}
			else
				p1 = p1->next;
		}
		return pcur->next;
	}
};