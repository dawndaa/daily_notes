# include <iostream>
# include <fstream>
# include <vector>
# include <utility>
# include <unistd.h>
# include <string>
using namespace std;

/*
All the situations are consist of the following situations:
m: 6 6 8 8 8  10 10 10 12 
n: 6 8 6 8 10 8  10 12 10 
*/

struct pt {
    int x;
    int y;
};

class Horse {
public:
    Horse(int r, int c);
    ~Horse() {};
    void print(int m, int n, ofstream& out);
    bool partition(int, int, int, int);

private:
    pt *g66, *g68, *g86, *g88, *g810, *g108, *g1010, *g1012, *g1210;
    pt loop[20][20];
    int r, c;
    void get_step(int, int, const vector<vector<int>>&, pt*);
    void base(int, int, int, int);
    void build(int, int, int, int, int, pt*);
    int get_pos(int, int, int);
};

Horse::Horse(int rr, int cc) {
    cout << "Horse" << endl;
    vector<vector<int>> arr(20, vector<int> (20));
    r = rr, c = cc;

    ifstream in_0("./cpp/course/algorithm_analyse/66.txt", ios::in);
    ifstream in_1("./cpp/course/algorithm_analyse/68.txt", ios::in);
    ifstream in_2("./cpp/course/algorithm_analyse/88.txt", ios::in);
    ifstream in_3("./cpp/course/algorithm_analyse/810.txt", ios::in);
    ifstream in_4("./cpp/course/algorithm_analyse/1010.txt", ios::in);
    ifstream in_5("./cpp/course/algorithm_analyse/1012.txt", ios::in);

    g66 = new pt[36], g68 = new pt[48], g86 = new pt[48];
    g88 = new pt[64], g810 = new pt[80], g108 = new pt[80];
    g1010 = new pt[100], g1012 = new pt[120], g1210 = new pt[120];

    for (int i = 0; i < 6; ++i) 
        for (int j = 0; j < 6; ++j)
            in_0 >> arr[i][j];
    get_step(6, 6, arr, g66);

    for (int i = 0; i < 6; ++i) 
        for (int j = 0; j < 8; ++j) 
            in_1 >> arr[i][j];
    get_step(6, 8, arr, g68);
    get_step(8, 6, arr, g86);

    for (int i = 0; i < 8; ++i) 
        for (int j = 0; j < 8; ++j) 
            in_2 >> arr[i][j];
    get_step(8, 8, arr, g88);

    for (int i = 0; i < 8; ++i) 
        for (int j = 0; j < 10; ++j)   
            in_3 >> arr[i][j];
    get_step(8, 10, arr, g810);
    get_step(10, 8, arr, g108);

    for (int i = 0; i < 10; ++i) 
        for (int j = 0; j < 10; ++j) 
            in_4 >> arr[i][j];
    get_step(10, 10, arr, g1010);

    for (int i = 0; i < 10; ++i) 
        for (int j = 0; j < 12; ++j)
            in_5 >> arr[i][j];
    get_step(10, 12, arr, g1012);
    get_step(12, 10, arr, g1210);
}

bool Horse::partition(int rr, int cc, int off_x, int off_y) {
    cout << "partition" << endl;
    int r1, r2, c1, c2;
    vector<int> x(8), y(8), p(8);
    // 删除不符合条件的情况
    if (rr % 2 == 1 || cc % 2 == 1 || rr - cc > 2 || cc - rr > 2 || rr < 6 || cc < 6) return true;
    if (rr < 12 || cc < 12) { // 只有一个方向需要切割
        base(rr, cc, off_x, off_y);
        return false;
    }

    // 分成四块 并进行递归分割
    r1 = rr / 2;
    if (rr % 4 > 0) --r1;
    r2 = rr - r1;
    c1 = cc / 2;
    if (cc % 4 > 0) --c1;
    c2 = cc - c1;
    partition(r1, c1, off_x, off_y);
    partition(r1, c2, off_x, off_y + c1);
    partition(r2, c1, off_x + r1, off_y);
    partition(r2, c2, off_x + r1, off_y + c1);

    // 子块完成标号之后，合并进行父块的标号
    x[0] = off_x + r1 - 1, x[1] = x[0] - 1, x[2] = x[1] - 1, x[3] = x[2] + 2;
    x[4] = x[3] + 1, x[5] = x[4] + 1, x[6] = x[5] + 1, x[7] = x[6] - 2;
    y[0] = off_y + c1 - 3, y[1] = y[0] + 2, y[2] = y[1] + 2, y[3] = y[2] - 1;
    y[4] = y[3] + 2, y[5] = y[4] - 2, y[6] = y[5] - 2, y[7] = y[6] + 1;

    for (int i = 0; i < 8; ++i) {
        p[i] = get_pos(x[i], y[i], c);
    }
    for (int i = 1; i < 8; i += 2) {
        int j_1 = (i + 1) % 8, j_2 = (i + 2) % 8;
        if (loop[x[i]][y[i]].x == p[i - 1]) loop[x[i]][y[i]].x = p[j_1];
        else loop[x[i]][y[i]].y = p[j_1];
        if (loop[x[j_1]][y[j_1]].x == p[j_2]) loop[x[j_1]][y[j_1]].x = p[i];
        else loop[x[j_1]][y[j_1]].y = p[i];
    }

    return false;
}

// 递归的基础
void Horse::base(int rr, int cc, int offx, int offy) {
    if(rr==6 && cc==6)
		build(rr,cc,offx,offy,c,g66);
	if(rr==6 && cc==8)
		build(rr,cc,offx,offy,c,g68);
	if(rr==8 && cc==6)
		build(rr,cc,offx,offy,c,g86);
	if(rr==8 && cc==8)
		build(rr,cc,offx,offy,c,g88);
	if(rr==8 && cc==10)
		build(rr,cc,offx,offy,c,g810);
	if(rr==10 && cc==8)
		build(rr,cc,offx,offy,c,g108);
	if(rr==10 && cc==10)
		build(rr,cc,offx,offy,c,g1010);
	if(rr==10 && cc==12)
		build(rr,cc,offx,offy,c,g1012);
	if(rr==12 && cc==10)
		build(rr,cc,offx,offy,c,g1210);
}  

void Horse::build(int rr, int cc, int off_x, int off_y, int col, pt* b) {
    int k = rr * cc;
    for (int i = 0; i < k; ++i) {
        int x_1 = off_x + b[i].x, y_1 = off_y + b[i].y, 
        x_2 = off_x + b[(i + 1) % k].x, y_2 = off_y + b[(i + 1) % k].y;
        int p = get_pos(x_1, y_1, col);
        int q = get_pos(x_2, y_2, col);
        loop[x_1][y_1].x = q;
        loop[x_2][y_2].y = p;
    }
    cout << "build" << endl;
}

int Horse::get_pos(int x, int y, int col) {
    return col * x + y;
}



void Horse::get_step(int rr, int cc, const vector<vector<int>>& a, pt* b) {
    if (rr < cc) {
        for (int i = 0; i < rr; ++i)
            for (int j = 0; j < cc; ++j) {
                int tmp = a[i][j] - 1;
                b[tmp].x = i;
                b[tmp].y = j;
            }
    }
    else {
        for (int i = 0; i < rr; ++i) {
            for (int j = 0; j < cc; ++j) {
                int tmp = a[j][i] - 1;
                b[tmp].x = i;
                b[tmp].y = j;
            }
        }
    }
    cout << "get_step" << endl;
}

void Horse::print(int rr, int cc, ofstream& out) {
    int i, j, k, x, y, p, arr[20][20]{{0}};

    if (partition(rr, cc, 0, 0)) return ;
    i = 0, j = 0, k = 2;
    arr[0][0] = 1;

    out << "(0,0)" << "";
    for (p = 1; p < rr * cc; ++p) {
        x = loop[i][j].x;
        y = loop[i][j].y;
        i = x / cc, j = x % cc;
        if (arr[i][j] > 0) {
            i = y / cc;
            j = y % cc;
        }
        arr[i][j] = k;
        ++k;
        out << "(" << i << "," << j << ")";
        if ((k - 1) % cc == 0) out << endl;
    }
    out << endl;

    for (i = 0; i < rr; ++i) {
        for (j = 0; j < cc; ++j) {
            out << arr[i][j] << " ";
        }
        out << endl;
    }

    cout << "print" << endl;
}

int main() {
    int m, n;
    string file = get_current_dir_name();
    ifstream in(file + "/cpp/course/algorithm_analyse/2_2_input.txt", ios::in);
    ofstream out(file + "/cpp/course/algorithm_analyse/2_2_output.txt", ios::out);

    while (!in.eof()) {
        in >> m >> n;
        cout << m << n << endl;
        Horse h(m, n);
        h.partition(m, n, 0, 0);
        out << m << " " << n << ":" << endl;
        h.print(m, n, out);
        out << endl;
    }

    in.close();
    out.close();
    return 0;
}