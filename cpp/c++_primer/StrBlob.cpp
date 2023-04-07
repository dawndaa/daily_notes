# include <iostream>
# include "StrBlob.h"
using namespace std;

int main() {
    StrBlob s1 = StrBlob({"Lucy", "Jack", "Semon", "John"});
    s1.push_back("Kitty"), s1.push_back(" ");
    s1.pop_back();

    cout << s1.front() << endl;
    cout << s1.back() << endl;

    auto str_ptr = s1.begin();
    while (true) {
        cout << str_ptr.deref() << endl;
        str_ptr.incr();
    }

    // for (int i = 0; i <= 5; ++i) 
    //     s1.pop_back();

    // cout << s1.front() << endl;
    // cout << s1.back() <<endl;

    system("pause");
    return 0;
}