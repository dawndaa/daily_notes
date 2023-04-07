#ifndef PERSON_H
#define PERSON_H
# include <string>
# include <iostream>
using namespace std;

class Person{
    friend istream& read(istream&, Person&);
    friend ostream& print(ostream&, const Person&);
private:
    string name;
    string address;
public:
    Person(const string& nam = " ", const string& add = " "): name(nam), address(add) { };
    explicit Person(istream& is) {read(is, *this);};
    string get_name() const {return name;};
    string get_address() const {return address;};
};

istream& read(istream& is, Person& p) {
    is >> p.name >> p.address;

    return is;
}

ostream& print(ostream& os, const Person& p) {
    os << p.name << " " << p.address;

    return os;
}

#endif