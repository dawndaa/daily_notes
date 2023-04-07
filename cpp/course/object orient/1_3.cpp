# include <iostream>
# include <cstring>
using namespace std;

int main() {
    const char s1[] = "abc";
    const char* p = s1;
    cout << s1 << endl;

    char* s2 = new char[5]{'d', 'e', 'f', 0};
    char* const q = s2; // char --> const char
    cout << q << " " << strlen(s2) << endl;

    char append;
    cin >> append;
    strcpy(s2, s1);
    s2[strlen(s2)] = append;

    cout << s2;

    // system("pause");
    return 0;
}