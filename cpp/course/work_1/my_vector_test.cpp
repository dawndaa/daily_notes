# include "my_vector.h"
# include <iostream>
using namespace std;

int main() {
    my_vector<int> vec;
    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
    }
    vec.print(cout) << endl;

    vec.reverse();
    vec.print(cout) << endl;

    int x = vec.find_least();
    cout << x << endl;

    vec.push_back(x);
    vec.delete_x(x);
    vec.print(cout) << endl;

    system("pause");
    return 0;
}