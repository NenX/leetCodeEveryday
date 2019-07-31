/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int n) : val(n), next(NULL){};
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int a = 0, b = 0, carry = 0, sum = 0;
        ListNode *h = NULL, **t = &h;
        while (l1 != NULL || l2 != NULL)
        {
            a = getValAndMoveNext(l1);
            b = getValAndMoveNext(l2);
            sum = a + b + carry;

            // 这里有什么问题 ？or ListNode node(sum % 10);

            // ListNode node = ListNode(sum & 10);
            // ListNode *lp = &node;
            // *t = lp;
            // t = &(lp->next);

            ListNode *node = new ListNode(sum % 10);
            *t = node;
            t = &(node->next);

            carry = sum / 10;
        };
        if (carry)
        {
            *t = new ListNode(carry % 10);
        }
        return h;
    };

private:
    int getValAndMoveNext(ListNode *&l)
    {
        int val = 0;
        if (l != NULL)
        {
            val = l->val;
            l = l->next;
        }
        return val;
    }
};

int main()
{
    ListNode *l1 = new ListNode(8);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(9);

    ListNode *l2 = new ListNode(8);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode *l = Solution().addTwoNumbers(l1, l2);
    return 0;
}