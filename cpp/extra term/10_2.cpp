# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;};

int main() {
    ll x, y;
    cin >> x >> y;

    if (y % x != 0) {
        cout << "0";
        system("pause");
        return 0;
    }

    y = y / x;
    vector<pair<ll, ll>> ret;
    int cnt = 0;
    for (int i = 1; i <= y * 1.0 / i; ++i) {
        if (y % i == 0 && gcd(i, y / i) == 1) {
            if (i == y / i) ++cnt;
            else cnt += 2;
            ret.push_back(make_pair(i, y / i));
        }
    }

    cout << cnt << endl;
    for (int i = 0; i < cnt; ++i) {
        cout << ret[i].first * x << " " << ret[i].second * x << endl;
        if (ret[i].first != ret[i].second)
            cout << ret[i].second * x << " " << ret[i].first * x << endl;
    }

    system("pause");
    return 0;
}