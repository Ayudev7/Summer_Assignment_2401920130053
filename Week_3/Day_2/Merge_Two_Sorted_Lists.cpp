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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr  = dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1      = list1->next;
            } else {
                curr->next = list2;
                list2      = list2->next;
            }
            curr = curr->next;
        }

        if (list1 != nullptr) curr->next = list1;
        if (list2 != nullptr) curr->next = list2;

        return dummy->next;
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

    int n, m;
    cout << "Enter size of list1: ";
    cin >> n;
    vector<int> v1(n);
    cout << "Enter " << n << " sorted values: ";
    for (int i = 0; i < n; i++) cin >> v1[i];

    cout << "Enter size of list2: ";
    cin >> m;
    vector<int> v2(m);
    cout << "Enter " << m << " sorted values: ";
    for (int i = 0; i < m; i++) cin >> v2[i];

    ListNode* list1 = buildList(v1);
    ListNode* list2 = buildList(v2);

    cout << "List1:  ";
    printList(list1);
    cout << "List2:  ";
    printList(list2);

    ListNode* result = sol.mergeTwoLists(list1, list2);

    cout << "Merged: ";
    printList(result);

    return 0;
}