# include <bits/stdc++.h>
using namespace std;

int main() {
	int n, s;
	cin >> n >> s;
	if (n == 1) {
		cout << s;
		return 0;
	}

	unordered_map<int, vector<int>> hash;
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		hash[a].emplace_back(b);
		hash[b].emplace_back(a);
	}
	
	unordered_set<int> vis;
	vis.insert(s);
	if (hash[s].size() == 1) {
		s = hash[s][0];
		vis.insert(s);
	}

	while (hash[s].size() > 1) {
		int tmp = n;
		for (int i = 0; i < hash[s].size(); ++i) {
			if (vis.count(hash[s][i])) continue;
			tmp = min(tmp, hash[s][i]);
		}
		s = tmp;
		vis.insert(s);
	}

	cout << s;

	system("pause");
	return 0;
}
