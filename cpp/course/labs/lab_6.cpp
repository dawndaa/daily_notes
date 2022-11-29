# include <iostream>
# include <vector>
# include <utility>
# include <fstream>
# include <queue>
# include <unordered_map>
using namespace std;

void print(const vector<string>& id, const vector<int>& score, 
const vector<vector<int>>& adj, const vector<int>& in) {
    for (int i = 0; i < id.size(); ++i) {
        cout << id[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < score.size(); ++i) {
        cout << score[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < adj.size(); ++i) {
        for (int j = 0; j < adj[i].size(); ++j) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < in.size(); ++i) {
        cout << i << ": " << in[i] << endl;
    }
}

void input(int& t, int& s, int& n, vector<string>& id, vector<int>& ss, 
vector<vector<int>>& adj, vector<int>& in, unordered_map<int, int>& pre) {
    ifstream infile;
    string infile_name = "./6_in.txt";
    infile.open(infile_name, ios::in);
    if (!infile) {
        cout << "open failed!" << endl;
    }

    
    infile >> t >> s >> n;
    adj.assign(n, vector<int>());
    in.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        string tmp;
        infile >> tmp;
        id.push_back(tmp);
    }
    for (int i = 0; i < n; ++i) {
        int tmp;
        infile >> tmp;
        ss.push_back(tmp);
    }
    while(!infile.eof()) {
        int a, b;
        infile >> a >> b;
        adj[a - 1].push_back(b - 1);
        ++in[b- 1];
        pre[b - 1] = a - 1;
    }
}

vector<int> findOrder(int n, vector<int>& indegree, const vector<vector<int>>& adj) {
    vector<int> ret;
    
    queue<int> que;
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) {
            que.push(i);
        }
    }
    while (!que.empty()) {
        int node = que.front();
        que.pop();
        ret.emplace_back(node);

        for (const int& n : adj[node]) {
            --indegree[n];
            if (indegree[n] == 0) {
                que.push(n);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (indegree[i]) return {};
    }

    return ret;
}

void arrange_course(const vector<int>& ret, vector<int>& course_term, const vector<int>& course_score, 
vector<int>& term_score, unordered_map<int, int>& pre, int max_s, int t) {
    for (int i = 0; i < ret.size(); ++i) {
        int  term_id = 0;
        if (pre.find(ret[i]) != pre.end()) {
            term_id = course_term[pre[ret[i]]] + 1;
        }

        while (term_id < t && term_score[term_id] + course_score[ret[i]] > max_s) {
            ++term_id;
        }

        course_term[ret[i]] = term_id;
        term_score[term_id] += course_score[ret[i]];
    }
}

void write_error() {
    ofstream outfile;
    string outfile_name = "./6_out.txt";
    outfile.open(outfile_name, ios::out | ios::trunc);
    if (!outfile) {
        cout << "open failed!" << endl;
    }

    outfile << "排课失败！" << endl;
}

void write_table(const vector<vector<int>>& tc, const vector<int>& ts, const vector<string>& cid, const vector<int>& cs) {
    ofstream outfile;
    string outfile_name = "./6_out.txt";
    outfile.open(outfile_name, ios::out | ios::trunc);
    if (!outfile) {
        cout << "open failed!" << endl;
    }

    for (int i = 0; i < tc.size(); ++i) {
        outfile << "第" << i + 1 << "个学期的课程如下：";
        for (int j = 0; j < tc[i].size(); ++j) {
            if (j % 3 == 0) {
                outfile << endl << "    ";
            }
            outfile << cid[tc[i][j]] << "  " << cs[tc[i][j]] << "学分" << "        ";
        }

        outfile << endl << "第" << i + 1 << "个学期的总学分为" << ts[i] << endl << endl;
    }
}

int main() {
    int term_sum, max_score, course_num;
    vector<string> course_id;
    vector<int> course_score, indegree, ret;
    vector<vector<int>> adj;
    unordered_map<int, int> pre;
    input(term_sum, max_score, course_num, course_id, course_score, adj, indegree, pre);

    print(course_id, course_score, adj, indegree);

    ret = findOrder(course_num, indegree, adj);
    for (int i = 0; i < ret.size(); ++i) {
        cout << course_id[ret[i]] << " ";
    }

    vector<int> course_term(course_num), term_score(term_sum, 0);
    arrange_course(ret, course_term, course_score, term_score, pre, max_score, term_sum);

    vector<vector<int>> term_course(term_sum, vector<int>());
    for (int i = 0; i < course_term.size(); ++i) {
        if (course_term[i] >= term_sum) {
            write_error();
            return 0;
        }

        term_course[course_term[i]].push_back(i);
    }

    write_table(term_course, term_score, course_id, course_score);

    system("pause");
    return 0;
}