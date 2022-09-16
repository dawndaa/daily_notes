# include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    set<int> st;
    vector<int> to_erase;
    st.insert(0), st.insert(n);
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;

        --l;
        for (auto it = st.upper_bound(l); it != st.end() && *it < r; ++it) {
            to_erase.emplace_back(*it);
        }
        for (const auto& t: to_erase) {
            st.erase(t);
        }
        st.insert(l), st.insert(r);
        to_erase.clear();

        cout << st.size() - 1 << endl;
    }

    

    system("pause");
    return 0;
}
