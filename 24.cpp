#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution { 
public:
    void helper(ListNode*& first, ListNode*& second) {
        ListNode* temp = second->next;
        second->next = first;
        first->next = temp;
    }

    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* newHead = head->next;
        ListNode* prev = nullptr;
        while (head && head->next) {
            ListNode* first = head;
            ListNode* second = head->next;
            helper(first, second);
            if (prev) prev->next = second;
            prev = first;
            head = first->next;
        }
        return newHead;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    ListNode* newHead = sol.swapPairs(head);

    cout << "After Swapping Pairs: ";
    printList(newHead);

    return 0;
}
