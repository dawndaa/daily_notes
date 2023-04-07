# include <iostream>
using namespace std;

int main() {
    int size;
    cin >> size;
    int* arry = new int;

    for (int i = 0; i < size; ++i) {
        int tmp;
        cin >> tmp;
        arry[i] = new int(tmp);
    }

    int sum = 0; 
    for (int i = 0; i < size; ++i) {
        sum += *arry[i];
        delete[] arry[i];
    }
    cout << sum;

    delete[] arry;

    // system("pause");
    return 0;   
}