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
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* forward = curr->next;
            curr->next        = prev;
            prev              = curr;
            curr              = forward;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;

        ListNode* mid        = findMiddle(head);
        ListNode* secondHalf = reverseList(mid->next);
        ListNode* copy       = secondHalf;

        bool result = true;
        while (secondHalf != nullptr) {
            if (head->val != secondHalf->val) {
                result = false;
                break;
            }
            head       = head->next;
            secondHalf = secondHalf->next;
        }

        mid->next = reverseList(copy); // restore list
        return result;
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

    cout << "List: ";
    printList(head);

    bool result = sol.isPalindrome(head);

    if (result)
        cout << "Output: true (Palindrome)" << endl;
    else
        cout << "Output: false (Not a Palindrome)" << endl;

    return 0;
}