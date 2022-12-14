# include "TextQuery.h"
#include <iostream>
using namespace std;

void runQueries(std::ifstream &infile)
{
    TextQuery tq = TextQuery(infile);
    while (true) {
        std::cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(std::cin >> s) || s == "q") break;
        print(std::cout, tq.query(s)) << std::endl;
    }
}

int main()
{
    std::ifstream file("../data/DataFile.txt");
    runQueries(file);
} 