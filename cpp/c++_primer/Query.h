# include "TextQuery.h"

class Query_base { // 定义了纯虚函数的类是抽象类 无法定义该类的对象
    friend class Query;

protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default; // 虚析构函数

private:
    virtual QueryResult eval(const TextQuery&) const = 0; // 纯虚函数 
    virtual std::string rep() const = 0; // 纯虚函数 
};

class Query { // 接口类 用户通过它来调用& | ~
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);

public:
    Query(const std::string& s): q(new WordQuery(s)) { }
    QueryResult eval(const TextQuery& t) const {
        return q->eval(t);
    }
    std::string rep() const { return q->rep(); } 

private:
    Query(std::shared_ptr<Query_base> query): q(query) { }
    std::shared_ptr<Query_base> q; // 一个指向基类的智能指针
};

class WordQuery: public Query_base { // 搜索单词单词
    friend class Query;
    WordQuery(const std::string& s): query_word(s) { }
    QueryResult eval(const TextQuery& t) const {
        return t.query(query_word);
    }
    std::string rep() const { return query_word; }
    std::string query_word;
};

class NotQuery: public Query_base { // 非
    friend Query operator~(const Query&) { }
    NotQuery(const Query& q): query(q) { }
    std::string rep() const { return "~(" + query.rep() + ")";}
    QueryResult eval(const TextQuery&) const;
    Query query;
};

class BinaryQuery: public Query_base { // 二元
protected:
    BinaryQuery(const Query& l, const Query& r, std::string s): 
        lhs(l), rhs(r), opSym(s) { }
    std::string rep() const { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }
    Query lhs, rhs;
    std::string opSym;
};

class AndQuery: public BinaryQuery {  // 与
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query& left, const Query& right):
        BinaryQuery(left, right, "&") { }
    QueryResult eval(const TextQuery&) const;
};

class OrQuery: public BinaryQuery {  // 或
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query& left, const Query& right):
        BinaryQuery(left, right, "|") { }
    QueryResult eval(const TextQuery&) const;
};
