#include <iostream>

struct ListNode
{
	int val;
	ListNode* next;

	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next):val(x), next(next){}
};

class Solution
{
public:
	ListNode* rotateRight(ListNode* head, int k)
	{
		if (head == nullptr)	return head;
		ListNode* result, *count = head; 

		int listLength = 1;
		while (count->next != nullptr)
		{
			count = count->next;
			++listLength;
		}
		std::cout << "List length is: " << listLength << std::endl;
		k %= listLength;
		if (k == 0)	return head;

		auto [newTail, tail] = findNewTail(head, k);
		result = getNewList(head, newTail, tail);

		return result;
	}

	std::pair<ListNode*, ListNode*> findNewTail(ListNode* head, int k)
	{
		ListNode* tail = head, *newTail = head;	
		while(tail->next != nullptr)
		{
			tail = tail->next;
		}
		while (k--)
		{
			newTail = newTail->next;
		}
		std::cout << "NewTail is:" << newTail->val << std::endl;
		return std::make_pair(newTail, tail);
	}

	ListNode* getNewList(ListNode* head, ListNode* newTail, ListNode* oldTail)
	{
		ListNode* newHead;

		newHead = newTail->next;
		newTail->next = nullptr;
		oldTail->next = head;

		return newHead;
	}
};