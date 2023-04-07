# include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> ori;

    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        ori.emplace_back(tmp);
    }

    unordered_set<int> cnt;
    unordered_map<int, priority_queue<P, vector<P>, greater<P>>> hash;
    for (int i = 0; i < m; ++i) {
        int a, b, d;
        cin >> a >> b >> d;
        --a, --b;
        cnt.insert(a), cnt.insert(b);
        d += min(ori[a], ori[b]);
        hash[a].emplace(make_pair(d, b)), hash[b].emplace(make_pair(d, a));
    }

    int ret = 0;
    unordered_set<int> used;
    int size = cnt.size();
    auto it = cnt.begin();
    used.insert(*it);
    while (used.size() < size) {
        int id, dis = INT_MAX;
        for (const auto& p: used) {
            auto cur = hash[p].top();
            while (used.count(cur.second)) {
                hash[p].pop();
                if (hash[p].empty()) break;
                cur = hash[p].top();
            }

            if (cur.first < dis) {
                dis = cur.first;
                id = p;
            }
        }

        auto fin = hash[id].top();
        hash[id].pop();
        used.insert(fin.second);
        ret += fin.first;
    }

    cout << ret;

    system("pause");
    return 0;
}