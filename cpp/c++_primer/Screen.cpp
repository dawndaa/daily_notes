# include <iostream>
# include "Screen.h"
using namespace std;

int main() {
    Screen myScreen(5, 3, '^');
    cout << to_string('^') << endl;
    const Screen blank(5, 3);   
    myScreen.set('9').display(cout);
    cout << endl;
    blank.display(cout);

    system("pause");
    return 0;
}