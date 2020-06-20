#include<bits/stdc++.h>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	vector<string> fizzBuzz(int n) {
		vector<string> str;
		string str1;
		for (int i = 1; i < n + 1; i++)
		{
			if (n % 3 == 0 && n % 5 == 0)
				str.push_back("FizzBuzz");
			else if (n % 3 == 0)
				str.push_back("Fizz");
			else if (n % 5 == 0)
				str.push_back("Buzz");
			else
			{
				str1 = to_string(n);
				str.push_back(str1);
			}

		}

		return str;
	}
};
class Solution1 {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* l = new ListNode(0);
		ListNode* ll = l;
		int carry = 0;//true，需要进位
		while (l1 != NULL && l2 != NULL)
		{
			ListNode* p = new ListNode((l1->val + l2->val + carry) % 10);
			if ((l1->val + l2->val + carry) > 9)
				carry = 1;
			else
				carry = 0;
			ll->next = p;
			ll = p;
			l1 = l1->next;
			l2 = l2->next;
		}


		if (l1 == NULL)
		{
			while (l2 != NULL)
			{
				ListNode* p = new ListNode(carry);
				if ((p->val + l2->val) > 9)
					carry = 1;
				else carry = 0;
				p->val = (p->val + l2->val) % 10;
				ll->next = p;
				l2 = l2->next;
			}
		}
		if (l2 == NULL)
		{
			while (l1 != NULL)
			{
				ListNode* p = new ListNode(carry);
				if ((p->val + l1->val) > 9)
					carry = 1;
				else carry = 0;
				p->val = (p->val + l1->val) % 10;
				ll->next = p;
				l1 = l1->next;
			}
		}
		if (l1 == NULL && l2 == NULL && carry == 1)
		{
			ListNode* p = new ListNode(1);
			ll->next = p;
		}

		return l->next;
	}

};
struct MyStruct
{
	char c;
	int i;
	float f;
};
class Demo
{
public:
	Demo():count(0){}
	~Demo() {};
	void say(const std::string& msg)
	{
		fprintf(stderr, "%s\n", msg.c_str());
		std::cout << count;
	}
private:
	int count;
};
char buffer[6] = { 0 };
char* mystring()
{
	
	const char* p = "nihao";
	MyStruct m;
	m.c = 'a';
	m.i = 257;
	m.f = 1.1;
	//cout << &m;
	const char * s = "hello world";
	for (int i = 0; i < sizeof(p) - 1; i++)
		buffer[i] = *(s + i);
	return buffer;
}
int main()
{
	Solution1 so;
	ListNode* L1 = new ListNode(9);
	ListNode* p1 = new ListNode(9);
	//ListNode* p2 = new ListNode(3);
	L1->next = p1;
	//p1->next = p2;

	ListNode *L2 = new ListNode(1);
	//ListNode* p11 = new ListNode(6);
	//ListNode* p22 = new ListNode(4);
	//L2->next = p11;
	//p11->next = p22;
	so.addTwoNumbers(L1, L2);
	return 0;
}