#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        for (int i = 0; i < n; i++)
            fast = fast->next;

        if (fast == nullptr)
            return head->next;

        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* deleteNode = slow->next;
        slow->next           = slow->next->next;
        delete deleteNode;

        return head;
    }
};

ListNode* buildList(vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (int i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

void printList(ListNode* head) {
    cout << "[";
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    int size;
    cout << "Enter number of nodes: ";
    cin >> size;

    vector<int> vals(size);
    cout << "Enter " << size << " values: ";
    for (int i = 0; i < size; i++)
        cin >> vals[i];

    int n;
    cout << "Enter n (remove nth from end): ";
    cin >> n;

    ListNode* head = buildList(vals);

    cout << "Before: ";
    printList(head);

    head = sol.removeNthFromEnd(head, n);

    cout << "After:  ";
    printList(head);

    return 0;
}