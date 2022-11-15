// 用于将中缀表达式 转化为 后缀表达式
// 然后根据后缀表达式求出值


/*
测试用例
4+3^2-(5+1)
8+3*4-(3+5-(5/5))
1+2+3+4
(5+6/3)-8/4+(2-1)
可在test_datas中添加用例
未进行表达式是否合法的检测
*/

# include <iostream>
# include <string>
# include <vector>
# include <unordered_map>
# include <stack>
# include <unordered_set>
# include <algorithm> 
using namespace std;

int back_to_val(const vector<string>& back) {
    stack<int> nums;
    unordered_set<string> ops{"+", "-", "*", "/", "^"};
    
    for (const auto& s: back) {
        if (ops.count(s)) {
            int l, r;
            r = nums.top(), nums.pop();
            l = nums.top(), nums.pop();
            
            if (s == "+") 
                nums.push(l + r);
            else if (s == "-") 
                nums.push(l - r);
            else if (s == "*")
                nums.push(l * r);
            else if (s == "/")
                nums.push(l / r);
            else if (s == "^")
                nums.push(pow(l, r));
            else 
                cout << "error operator";
        }
        else {
            nums.push(stoi(s));
        }
    }

    return nums.top();
}

vector<string> in_to_back(const string& in, unordered_map<char, int>& val) {
    vector<string> out;
    stack<char> st;
    st.push('#');

    int id = 0;
    while (id != in.size()) {
        string tmp = "";
        if (isdigit(in[id])) { // 数字 
            tmp += in[id];
            while (id + 1 != in.size() && isdigit(in[id + 1])) {
                ++id;
                tmp += in[id];
            }
            out.emplace_back(tmp);
        }
        else { // 运算符
            if (in[id] != ')') { // 不是右括号
                if (in[id] != '(') // '(' 不应弹出任何元素
                    while (val[st.top()] >= val[in[id]]) { // 将优先级更高的都弹出
                        tmp += st.top();
                        st.pop();
                        out.emplace_back(tmp);
                        tmp = "";
                    }
                st.push(in[id]);
            }
            else {
                while (st.top() != '(') {
                    tmp += st.top();
                    st.pop();
                    out.emplace_back(tmp);
                    tmp = "";
                }
                st.pop();
            }
        }

        ++id;
    }
    while (st.size() > 1) {
        string tmp = "";
        tmp += st.top();
        st.pop();
        out.emplace_back(tmp);
    }

    return out;
}   

int main() {
    unordered_map<char, int> val;
    val['#'] = 0, val['('] = 1, val['+'] = val['-'] = 2,
    val['*'] = val['/'] = 3, val['^'] = 4;

    vector<string> test_datas = {"4+3^2-(5+1)", "8+3*4-(3+5-(5/5))", "1+2+3+4", "(5+6/3)-8/4+(2-1)"};

    for (const auto& in: test_datas) {
        vector<string> back = in_to_back(in, val);
        cout << in << endl;
        for_each(back.begin(), back.end(), [] (const string& s) {cout << s << " "; });
        cout << endl;

        int ret = back_to_val(back);
        cout << ret << endl << endl;
    }

    system("pause");
    return 0;
}