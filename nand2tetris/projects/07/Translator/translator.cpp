# include <iostream>
# include <fstream>
# include <vector>
# include <unistd.h>
using namespace std;

enum Type{
    INVALID = -1,
    C_ARITHMETIC,
    C_PUSH,
    C_POP,
    C_LABEL,
    C_GOTO,
    C_IF,
    C_FUNCTION,
    C_RETURN,
    C_CALL
};

class CodeWriter;
class Parser {
public:
    Parser(string inName): inName(inName), curLine(""), words({}) { };
    void init();
    bool hasMoreCommands();
    void advance(CodeWriter&);
private:
    string inName;
    string curLine;
    vector<string> words;
    ifstream in;
    Type curType;
    Type commandType();
    string arg1();
    int arg2();
};

class CodeWriter {
public:
    CodeWriter(string outName): outName(outName), cnt(0) { };
    void init();
    void close();
private:
    friend Parser; // 声明友元
    string outName;
    ofstream out;
    int cnt;
    void initWrite();
    void writeArithmetic(string);
    void writePushPop(string, string, int);
};

void splitBySpace(const string& curLine, vector<string>& words) {
    int i = 0;
    char pre = ' ';
    string tmp = "";
    words.clear();

    while (i < curLine.size()) {
        if (pre == ' ' && tmp != "") {
            words.push_back(tmp);
            tmp.clear();
        }

        if (curLine[i] != ' ' && curLine[i] != '\n' && 
        curLine[i] != '\r' && curLine[i] != '\t') tmp.push_back(curLine[i]);
        if (curLine[i] == '/' && pre == '/') break;
        pre = curLine[i];

        ++i;
    }
    if (tmp != "//" && tmp != "") words.push_back(tmp);
}

void Parser::init() {
    in.open(inName, ios::in);
}
bool Parser::hasMoreCommands() {
    return !in.eof();
}
void Parser::advance(CodeWriter& cw) {
    getline(in, curLine);
    curType = commandType();
    if (curType == INVALID) return ;

    string arg_1;
    int arg_2;
    if (curType != C_RETURN) arg_1 = arg1();
    if (curType == C_PUSH || curType == C_POP ||
    curType == C_FUNCTION || curType == C_CALL) arg_2 = arg2();

    if (curType == C_ARITHMETIC) cw.writeArithmetic(words[0]);
    else if (curType == C_POP || curType == C_PUSH) cw.writePushPop(words[0], words[1], stoi(words[2]));
}
Type Parser::commandType() {
    splitBySpace(curLine, words);

    if (words.empty()) return INVALID;
    else if (words[0] == "add" || words[0] == "sub" || words[0] == "neg" ||
    words[0] == "eq" || words[0] == "gt" || words[0] == "lt" || 
    words[0] == "and" || words[0] == "or" || words[0] == "not") return C_ARITHMETIC;
    else if (words[0] == "pop") return C_POP;
    else if (words[0] == "push") return C_PUSH;
    else if (words[0] == "call") return C_CALL;
    else if (words[0] == "goto") return C_GOTO;
    else if (words[0] == "label") return C_LABEL;
    else if (words[0] == "return") return C_RETURN;
    else if (words[0] == "if-goto") return C_IF;
    else if (words[0] == "function") return C_FUNCTION;
    else return INVALID;
}
string Parser::arg1() {
    if (curType == C_ARITHMETIC) return words[0];
    else return words[1];
}
int Parser::arg2() {
    return stoi(words[2]);
}

void CodeWriter::init() {
    out.open(outName, ios::out | ios::trunc);
    initWrite();
}
void CodeWriter::initWrite() {
    out << "@256" << endl << "D = A" << endl 
    << "@0" << endl << "M = D" << endl 
    << "@300" << endl << "D = A" << endl
    << "@1" << endl << "M = D" << endl
    << "@400" << endl << "D = A" << endl
    << "@2" << endl << "M = D" << endl
    << "@3000" << endl << "D = A" << endl
    << "@3" << endl << "M = D" << endl
    << "@3010" << endl << "D = A" << endl
    << "@4" << endl << "M = D" << endl;
}
void CodeWriter::writeArithmetic(string command) {
    if (command == "not" || command == "neg") {
        out << "@0" << endl << "M = M - 1" << endl
        << "A = M" << endl;
        
        if (command == "not") out << "M = !M" << endl;
        else out << "M = -M" << endl;
    }
    else {
        out << "@0" << endl << "M = M - 1" << endl
        << "A = M" << endl << "D = M" << endl
        << "@0" << endl << "M = M - 1" << endl 
        << "A = M" << endl;

        if (command == "add") out << "M = D + M" << endl;
        else if (command == "sub") out << "M = M - D" << endl;
        else if (command == "and") out << "M = D & M" << endl;
        else if (command == "or") out << "M = D | M" << endl;
        else { // eq gt lt
            out << "D = M - D" << endl << "@TRUE" + to_string(cnt) << endl;

            if (command == "eq") out << "D;JEQ" << endl;
            else if (command == "gt") out << "D;JGT" << endl;
            else out << "D;JLT" << endl; // lt

            out << "@0" << endl << "A = M" << endl 
            << "M = 0" << endl << "@END" + to_string(cnt) << endl
            << "0;JMP" << endl << "(TRUE" + to_string(cnt) + ")"<< endl
            << "@0" << endl << "A = M" << endl
            << "M = -1" << endl << "(END" + to_string(cnt) + ")"<< endl;

            ++cnt;
        }
    }
    out << "@0" << endl << "M = M + 1" << endl;
}
void CodeWriter::writePushPop(string command, string segment, int index) {
    if (command == "push") {
        if (segment == "constant") {
            out << "@" + to_string(index) << endl << "D = A" << endl;
        }
        else if (segment == "local") {
            out << "@" + to_string(index) << endl << "D = A" << endl
            << "@1" << endl << "A = D + M" << endl << "D = M" << endl;
        }
        else if (segment == "argument") {
            out << "@" + to_string(index) << endl << "D = A" << endl
            << "@2" << endl << "A = D + M" << endl << "D = M" << endl;
        }
        else if (segment == "this") {
            out << "@" + to_string(index) << endl << "D = A" << endl
            << "@3" << endl << "A = D + M" << endl << "D = M" << endl;
        }
        else if (segment == "that") {
            out << "@" + to_string(index) << endl << "D = A" << endl
            << "@4" << endl << "A = D + M" << endl << "D = M" << endl;
        }
        else if (segment == "temp") {
            out << "@" + to_string(index) << endl << "D = A" << endl
            << "@5" << endl << "A = D + A" << endl << "D = M" << endl;
        }
        else if (segment == "pointer") {
            out << "@" + to_string(index) << endl << "D = A" << endl
            << "@3" << endl << "A = D + A" << endl << "D = M" << endl;
        }

        out << "@0" << endl << "A = M" << endl 
        << "M = D" << endl << "@0" << endl
        << "M = M + 1" << endl;
    }
    else { // pop
        out << "@0" << endl << "M = M - 1" << endl
        << "@0" << endl << "A = M" << endl
        << "D = M" << endl;

        if (segment == "local") {
            out << "@" + to_string(index) << endl << "D = A" << endl
            << "@1" << endl << "A = D + M" << endl;
        }
        else if (segment == "argument") {
            out << "@" + to_string(index) << endl << "D = A" << endl
            << "@2" << endl << "A = D + M" << endl << "M = D" << endl;
        }
        else if (segment == "this") {
            out << "@" + to_string(index) << endl << "D = A" << endl
            << "@3" << endl << "A = D + M" << endl << "M = D" << endl;
        }
        else if (segment == "that") {
            out << "@" + to_string(index) << endl << "D = A" << endl
            << "@4" << endl << "A = D + M" << endl << "M = D" << endl;
        }
        else if (segment == "temp") {
            out << "@" + to_string(index) << endl << "D = A" << endl
            << "@5" << endl << "A = D + A" << endl << "M = D" << endl;
        }
        else if (segment == "pointer") {
            out << "@" + to_string(index) << endl << "D = A" << endl
            << "@3" << endl << "A = D + A" << endl << "M = D" << endl;
        }
    }
}
void CodeWriter::close() {
    out.close();
}

int main() {
    string path = get_current_dir_name();
    Parser p(path + "/nand2tetris/projects/07/StackArithmetic/StackTest/StackTest.vm");
    CodeWriter cw(path + "/nand2tetris/projects/07/StackArithmetic/StackTest/StackTest.asm");
    p.init();
    cw.init();

    while (p.hasMoreCommands()) p.advance(cw);
    cw.close();

    return 0;
}