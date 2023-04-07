# include <bits/stdc++.h>
# include "Person.h"
using namespace std;

size_t hasher(const Person& p) {
    return  hash<string> () (p.get_name());
}
bool eqOp(const Person& p1, const Person& p2) {
    return p1.get_name() == p2.get_name() && 
    p1.get_address() == p2.get_address();
}


int main() {
    using usp = unordered_set<Person, decltype(hasher)*, decltype(eqOp)*>;
    usp ust(42, hasher, eqOp);
    Person p1("Lucy, Beijing"), p2("Jack, Nanjing"), p3("Mark, Hangzhou");
    ust.insert(p1), ust.insert(p2), ust.insert(p3);

    for (const auto& p: ust) {
        print(cout, p);
    }


    system("pause");
    return 0;
}