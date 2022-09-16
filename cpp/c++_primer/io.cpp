# include <iostream>
# include <fstream>
# include <string>
# include <vector>
using namespace std;

int main() {
/*
    cout << "hi!" << endl;
    cout << "hi!" << flush;
    cout << "hi!" << ends;
*/
    vector<string> strs;
    string file_name = "test.txt";
    fstream input;
    input.open(file_name, ios_base::in);

    while (input) {
        string tmp;
        getline(input, tmp);
        strs.emplace_back(tmp);
    }

    for (auto str: strs) {
        cout << str << endl;
    }

    system("pause");
    return 0;
}