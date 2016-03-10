#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <map>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
};

class Solution {
public:
    ListNode* AddTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(-1);
        ListNode *pos = head;

        int sum=0;
        while (l1 != NULL || l2 != NULL) {
            int x = (l1) ? l1->val: 0;
            int y = (l2) ? l2->val: 0;
            sum += x+y;
            ListNode *node = new ListNode(sum%10);
            pos->next = node;
            pos = node;
            sum /= 10;
            if (l1) l1=l1->next;
            if (l2) l2=l2->next;
        }

        if (sum > 0) {
            ListNode *last = new ListNode(sum);
            pos->next=last;
        }

        return head;
    }
};

void printList(ListNode *head) {
    ListNode *pos = head->next;
    while (pos != NULL) {
        cout << pos->val << ", ";
        pos=pos->next;
    }
    cout << endl;
}

ListNode *buildList(int *array, int len) {
    ListNode *head = new ListNode(-1);
    ListNode *pos = head;
    int i=0;
    while (i<len) {
        ListNode *node = new ListNode(array[i]);
        pos->next = node;
        pos = node;
        ++i;
    }
    return head;
}

int main() {
    int a1[]={2,4,3};
    int a2[]={5,6,4};
    ListNode *l1 = buildList(a1, sizeof(a1)/sizeof(int));
    ListNode *l2 = buildList(a2, sizeof(a2)/sizeof(int));

    Solution s;
    ListNode *result = s.AddTwoNumbers(l1->next, l2->next);

    printList(result);

	return 0;
}
