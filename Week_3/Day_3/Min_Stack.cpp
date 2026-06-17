#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<int> st;
    stack<int> minSt;

    MinStack() {

    }

    void push(int val) {
        st.push(val);

        if (minSt.empty() || val <= minSt.top())
            minSt.push(val);
        else
            minSt.push(minSt.top());
    }

    void pop() {
        st.pop();
        minSt.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};

int main() {
    MinStack* obj = new MinStack();

    int q;
    cout << "Enter number of operations: ";
    cin >> q;

    for (int i = 0; i < q; i++) {
        string op;
        cout << "Enter operation (push/pop/top/getMin): ";
        cin >> op;

        if (op == "push") {
            int val;
            cout << "Enter value: ";
            cin >> val;
            obj->push(val);
            cout << "Pushed " << val << endl;
        } else if (op == "pop") {
            obj->pop();
            cout << "Popped top element" << endl;
        } else if (op == "top") {
            cout << "Top: " << obj->top() << endl;
        } else if (op == "getMin") {
            cout << "Min: " << obj->getMin() << endl;
        }
    }

    return 0;
}