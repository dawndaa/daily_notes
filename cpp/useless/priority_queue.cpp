# include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> pri;
    for (int i = 0; i < 100; ++i) {
        pri.push(100 - i);
    }

    while (!pri.empty()) {
        cout << pri.top() << " ";
        pri.pop();
    }

    system("pause");
    return 0;
}