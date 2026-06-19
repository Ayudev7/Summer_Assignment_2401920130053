#include <bits/stdc++.h>
using namespace std;

class RecentCounter {
public:
    queue<int> q;

    RecentCounter() {

    }

    int ping(int t) {
        q.push(t);

        while (q.front() < t - 3000) {
            q.pop();
        }

        return q.size();
    }
};

int main() {
    RecentCounter* obj = new RecentCounter();

    int n;
    cout << "Enter number of pings: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int t;
        cout << "Enter time t: ";
        cin >> t;

        int result = obj->ping(t);
        cout << "Output: " << result << endl;
    }

    return 0;
}