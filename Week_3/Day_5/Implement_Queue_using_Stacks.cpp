#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> inStack;
    stack<int> outStack;

    MyQueue() {

    }

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        transferIfNeeded();
        int val = outStack.top();
        outStack.pop();
        return val;
    }

    int peek() {
        transferIfNeeded();
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }

private:
    void transferIfNeeded() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }
};

int main() {
    MyQueue* obj = new MyQueue();

    int q;
    cout << "Enter number of operations: ";
    cin >> q;

    for (int i = 0; i < q; i++) {
        string op;
        cout << "Enter operation (push/pop/peek/empty): ";
        cin >> op;

        if (op == "push") {
            int val;
            cout << "Enter value: ";
            cin >> val;
            obj->push(val);
            cout << "Pushed " << val << endl;
        } else if (op == "pop") {
            cout << "Popped: " << obj->pop() << endl;
        } else if (op == "peek") {
            cout << "Front: " << obj->peek() << endl;
        } else if (op == "empty") {
            cout << "Empty: " << (obj->empty() ? "true" : "false") << endl;
        }
    }

    return 0;
}