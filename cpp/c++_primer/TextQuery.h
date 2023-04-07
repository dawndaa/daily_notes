# ifndef TEXTQUERY_H
# define TEXTQUERY_H

# include <vector>
# include <string>
# include <memory>
# include <iostream>
# include <fstream>
# include <sstream>
# include <set>
# include <map>
using namespace std;

class QueryResult;
class TextQuery {
public:
    using line_no = vector<string>::size_type; // 定义别名

    TextQuery(ifstream& is): file(new vector<string>) {
    string text;
    while (getline(is, text)) { // 读取文件流中的每一行
        file->push_back(text);  // 将其保存在文件中
        int n = file->size() - 1;  // 当前行号

        istringstream line(text);  // 将行文本分解为单词
        string word;
        while (line >> word) { // 读取字符串流中的每一个单词
            // 如果单词不在wm中 则添加
            auto& lines = wm[word]; // lines是一个shared_ptr
            if (!lines) // 第一次遇到某个单词时 该指针为nullptr
                lines.reset(new set<line_no>); // 动态分配空间
            lines->insert(n);
        }
    }
}

    QueryResult query(const string& sought) const {
    // 如果未找到sought 返回一个指向此set的指针
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought); // 查找而不插入
    if (loc == wm.end()) 
        return QueryResult(sought, nodata, file);
    else 
        return QueryResult(sought, loc->second, file);
}

private:
    shared_ptr<vector<string>> file; // 输入文件的智能指针
    map<string, shared_ptr<set<line_no>>> wm; // 以单词名字为key value是包含单词出现行号的set的智能指针
};

class QueryResult {
friend ostream& print(ostream& , const QueryResult&) { }

public:
    QueryResult(const string& s, shared_ptr<set<TextQuery::line_no>> p, shared_ptr<vector<string>> f):
        sought(s), lines(p), file(f) { }

private:
    string sought;
    shared_ptr<set<TextQuery::line_no>> lines;
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