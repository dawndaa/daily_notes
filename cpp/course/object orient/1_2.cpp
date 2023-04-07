# include <iostream>
using namespace std;

void three_sort(int& num_a, int& num_b, int& num_c) {
    if (num_a > num_b) swap(num_a, num_b);
    if (num_a > num_c) swap(num_a, num_c);
    if (num_b > num_c) swap(num_b, num_c);
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    three_sort(a, b, c);
    
    cout << a << " " << b << " " << c;

    // system("pause");
    return 0;
}