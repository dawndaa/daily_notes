# include <fstream>
# include <string>
# include <iostream>
# include <unordered_map>
using namespace std;

class SymbolTable;
string compress(const string&);

class Parser {
public:
    Parser(string inname, string outname):inname(inname), outname(outname) { };
    void init();
    bool hasMoreCommands();
    void advance(SymbolTable&);
    int commandType();
    string symbol();
    string dest();
    string comp();
    string jump();
private:
    string inname;
    string outname;
    ifstream in;
    ofstream out;
    string line;
};

class Code {
public:
    Code() { };
    string dest(string);
    string comp(string);
    string jump(string);
private:
    unordered_map<string, string> dest_table{{"Null", "000"}, {"M", "001"}, {"D", "010"},
    {"A", "100"}, {"AD", "110"}, {"AM", "101"}, {"MD", "011"}, {"AMD", "111"}, {"", "000"}};
    unordered_map<string, string> comp_table{{"0", "0101010"}, {"1", "0111111"}, {"-1", "0111010"},
    {"D", "0001100"}, {"A", "0110000"}, {"!D", "0001101"}, {"!A", "0110001"}, {"-D", "0001111"},
    {"-A", "0110011"}, {"D+1", "0011111"}, {"A+1", "0110111"}, {"D-1", "0001110"}, {"A-1", "0110010"},
    {"D+A", "0000010"}, {"D-A", "0010011"}, {"A-D", "0000111"}, {"D&A", "0000000"}, {"D|A", "0010101"},
    {"M", "1110000"}, {"!M", "1110001"}, {"-M", "1110011"}, {"M+1", "1110111"}, {"M-1", "1110010"}, 
    {"", "0000000"}, {"D+M", "1000010"}, {"D-M", "1010011"}, {"M-D", "1000111"}, {"D&M", "1000000"}, 
    {"D|M", "1010101"}};
    unordered_map<string, string> jump_table{{"null", "000"}, {"JGT", "001"}, {"JEQ", "010"},
    {"JGE", "011"}, {"JLT", "100"}, {"JNE", "101"}, {"JLE", "110"}, {"JMP", "111"}, {"", "000"}};
};

class SymbolTable {
public:
    SymbolTable(string filename): filename(filename) { };
    void preload();
    void addEntry(string, int);
    bool contains(string);
    int GetAddress(string);
private:
    unordered_map<string, int> symbolTable{{"SP", 0}, {"LCL", 1}, {"ARG", 2}, {"THIS", 3},
    {"THAT", 4}, {"R0", 0}, {"R1", 1}, {"R2", 2}, {"R3", 3}, {"R4", 4}, {"R5", 5},
    {"R6", 6}, {"R7", 7}, {"R8", 8}, {"R9", 9}, {"R10", 10}, {"R11", 11}, {"R12", 12},
    {"R13", 13}, {"R14", 14}, {"R15", 15}, {"SCREEN", 16384}, {"KBD", 24576}};
    string filename;
};


void SymbolTable::preload() {
    int cnt = 0;
    ifstream in;
    in.open(filename, ios::in);
    while (!in.eof()) {
        string line;
        getline(in, line);
        line = compress(line);

        if (line == "") continue;
        else if (line[0] == '(') 
            addEntry(line.substr(1, line.size() - 2), cnt);
        else ++cnt;
    }
}
void SymbolTable::addEntry(string symbol, int address) {
    symbolTable[symbol] = address;
}
bool SymbolTable::contains(string symbol) {
    return symbolTable.find(symbol) != symbolTable.end();
}
int SymbolTable::GetAddress(string symbol) {
    return symbolTable[symbol];
}


string Code::dest(string d) {
    return this->dest_table[d];
}
string Code::comp(string c) {
    return this->comp_table[c];
}
string Code::jump(string j) {
    return this->jump_table[j];
}


string d2b(int num) {
    string ret(16, '0');
    int mask = 0x1;
    for (int i = 15; i >= 0; --i) {
        if (mask & num) 
            ret[i] = '1';
        mask <<= 1;
    }

    return ret;
}
string compress(const string& line) {
    string tmp = "";
    for (int i = 0; i < line.size(); ++i) {
        if (line[i] == ' ' || line[i] == '\n'
        || line[i] == '\t' || line[i] == '\r') continue;
        else if (line[i] == '/') break;
        else tmp.push_back(line[i]);
    }

    return tmp;
}
bool num_judge(const string& s) {
    for (const auto& a: s) {
        if (!isdigit(a)) return false;
    }
    return true;
}


void Parser::init() {
    this->in.open(inname, ios::in);
    this->out.open(outname, ios::out | ios::trunc);
}
bool Parser::hasMoreCommands() {
    if (this->in.eof()) return false;
    return true;
}
void Parser::advance(SymbolTable& st) {
    Code code;
    int cnt = 16;
    while (hasMoreCommands()) {
        getline(this->in, this->line);
        int type = commandType();
        if (type == -1) 
            continue;
        else if (type == 1 || type == 3) {
            if (type == 3) continue;
            string s = symbol();
            bool isnum = num_judge(s);
            
            if (!isnum) {
                if (st.contains(s)) {
                    s = to_string(st.GetAddress(s));
                }
                else {
                    st.addEntry(s, cnt);
                    s = to_string(cnt);
                    cnt++;
                }
            }
            int num = stoi(s);
            string bs = d2b(num);            
            this->out << bs << endl;
        }
        else {
            string d = dest();
            string c = comp();
            string j = jump();
            d = code.dest(d);
            c = code.comp(c);
            j = code.jump(j);
            this->out << "111" << c << d << j << endl;
        }
    }
}
int Parser::commandType() {
    string tmp = compress(this->line);
    this->line = tmp;
    if (tmp.empty()) 
        return -1;
    else if (tmp[0] == '@')
        return 1;
    else if (tmp[0] == '(')
        return 3;
    else return 2;
}
string Parser::symbol() {
    int bit_cnt = 1;
    if (this->line[0] == '@') 
        bit_cnt = 0;
    return this->line.substr(1, this->line.size() - bit_cnt);
}
string Parser::dest() {
    for (int i = 0; i < this->line.size(); ++i) 
        if (this->line[i] == '=')
            return this->line.substr(0, i);
    return "";
}
string Parser::comp() {
    int l = 0, r = this->line.size() - 1;
    for (int i = 0; i < this->line.size(); ++i) {
        if (this->line[i] == '=')
            l = i + 1;
        else if (this->line[i] == ';')
            r = i - 1;
    }
    return this->line.substr(l, r - l + 1);
}
string Parser::jump() {
    for (int i = this->line.size() - 1; i >= 0; --i)
        if (this->line[i] == ';')
            return this->line.substr(i + 1, this->line.size() - i - 1);
    return "";
}


int main() {
    string inName = "../pong/PongL.asm", outName = "../pong/PongL.hack";
    SymbolTable s(inName);
    s.preload();
    Parser p(inName, outName);
    p.init();
    p.advance(s);

    system("pause");
    return 0;
}