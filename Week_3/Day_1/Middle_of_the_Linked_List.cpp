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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
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

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> vals(n);
    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++)
        cin >> vals[i];

    ListNode* head = buildList(vals);

    cout << "List:   ";
    printList(head);

    ListNode* mid = sol.middleNode(head);

    cout << "Middle: ";
    printList(mid);

    return 0;
}