#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
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

void addCycle(ListNode* head, int pos) {
    if (pos == -1) return;
    ListNode* tail = head;
    ListNode* cycleNode = head;

    int i = 0;
    while (tail->next != nullptr) {
        if (i == pos) cycleNode = tail;
        tail = tail->next;
        i++;
    }
    tail->next = cycleNode;
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

    int pos;
    cout << "Enter cycle position (-1 for no cycle): ";
    cin >> pos;

    ListNode* head = buildList(vals);
    addCycle(head, pos);

    bool result = sol.hasCycle(head);

    if (result)
        cout << "Output: true (cycle detected)" << endl;
    else
        cout << "Output: false (no cycle)" << endl;

    return 0;
}