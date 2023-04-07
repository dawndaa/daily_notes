# include "Person.h"
# include <iostream>
using namespace std;

int main() {
    Person p1 = Person(), p2 = Person("Jam"), p3 = Person("Semon", "Xi an"), p4 = Person(cin);

    read(cin, p1);
    print(cout, p1) << endl;
    print(cout, p2) << endl;
    print(cout, p3) << endl;
    print(cout, p4) << endl;

    system("pause");
    return 0;
}