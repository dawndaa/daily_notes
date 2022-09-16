# ifndef QUERYRESULT_H
# define QUERYRESULT_H

# include "TextQuery.h"
# include <iostream>
# include <sstream>
# include <string>
# include <memory>
# include <vector>
# include <set>
using namespace std;

class QueryResult {
friend ostream& print(ostream&, const QueryResult&);
public:
    QueryResult(const string& s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f):
        sought(s), lines(p), file(f) { }

private:
    string sought;
    shared_ptr<vector<line_no>> lines;
    shared_ptr<vector<string>> file;
};

ostream& print(ostream& os, const QueryResult& qr) {
    // 如果找到单词 打印出现次数和所有位置
    os << qr.sought << "出现了" << qr.lines->size() << " " << 
    qr.lines->size() << (qr.lines->size() > 1 ? "times" : "time")  << endl;
    // 打印单词出现的每一行
    for (auto num: *qr.lines) 
        os << "\t(line" << num + 1 << ") " << *(qr.file->begin() + num) << endl;

    return os;
}

# endif