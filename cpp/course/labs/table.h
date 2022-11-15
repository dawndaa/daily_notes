# ifndef TABLE_H
# define TABLE_H

# include <vector>
# include <iostream>
# include <windows.h>
# include <algorithm>
using namespace std;

template <typename T>
class Table {
public:
    Table(int r = 10, int c = 10): row(r), col(c), max_len(10) { datas.assign(r, vector<T>(c)); };

    void display() const {
        system("cls");
        for (int i = 0; i < row; ++i) {
            draw_line();
            for (int j = 0; j < col; ++j) {
                gotoxy(max_len * j, 2 * i + 1);
                cout << datas[i][j];
            }
            cout << endl;
        }

        cout << endl;
    }

    void resize(int r, int c) {
        row = r;
        col = c;
        datas.assign(r, vector<T>(c));
    }

    void draw_line() const{
        for (int i = 0; i < col * max_len; ++i) 
            cout << "_";
        cout << endl << endl;
    }

    void gotoxy(short x, short y) const{
        COORD pos = {x,y};
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hOut, pos);
    }

    int get_row() {
        int r;
        cout << "??????????: ";
        cin >> r;

        while (r <= 0 || r > row) {
            cout << "?????????í?ó ??????????: ";
            cin >> r;
        }

        cout << endl;
        return --r;
    }
    int get_col() {
        int c;
        cout << "??????????: ";
        cin >> c;

        while (c <= 0 || c > col) {
            cout << "?????????í?ó ??????????: ";
            cin >> c;
        }

        cout << endl;
        return --c;
    }

    void fill() {
        int r = get_row(), c = get_col();
        T item;
        cin >> item;

        datas[r][c] = item;
    }

    void fill_by_order() {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                cout << "????????" << i + 1 << "????" << j + 1 << "??????: ";
                cin >> datas[i][j];
            }
        }
        cout << endl;
    }

    void sort_in_col() {
        int c = get_col();

        vector<T> tmp;
        for (int i = 0; i < row; ++i) {
            tmp.emplace_back(datas[i][c]);
        }
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i < row; ++i) {
            datas[i][c] = tmp[i];
        }
    }

    void sort_in_row() {
        int r = get_row();

        sort(datas[r].begin(), datas[r].end());
    }

    void sum_in_col() {
        int c = get_col();

        T ret;
        for (int i = 0; i < row; ++i) {
            ret += datas[i][c];
        }

        cout << "??" << c + 1 << "????????" << ret << endl;
        cout << endl;
    }

    void sum_in_row() {
        int r = get_row();

        T ret;
        for (int i = 0; i < col; ++i) {
            ret += datas[r][i];
        }

        cout << "??" << r + 1 << "????????" << ret << endl;
        cout << endl;
    }

    void max_in_col() {
        int c = get_col();

        T ret = datas[0][c];
        for (int i = 1; i < row; ++i) {
            ret = ret > datas[i][c] ? ret : datas[i][c];
        }
        cout << "??" << c + 1 << "????×??ó????" << ret << endl;
        cout << endl;
    }

    void max_in_row() {
        int r = get_row();

        T ret = datas[r][0];
        for (int i = 1; i < col; ++i) {
            ret = ret > datas[r][i] ? ret : datas[r][i];
        }
        cout << "??" << r + 1 << "????×??ó????" << ret << endl;
        cout << endl;
    }

    void min_in_col() {
        int c = get_col();

        T ret = datas[0][c];
        for (int i = 1; i < row; ++i) {
            ret = ret < datas[i][c] ? ret : datas[i][c];
        }
        cout << "??" << c + 1 << "????×???????" << ret << endl;
        cout << endl;
    }

    void min_in_row() {
        int r = get_row();

        T ret = datas[r][0];
        for (int i = 1; i < col; ++i) {
            ret = ret < datas[r][i] ? ret : datas[r][i];
        }
        cout << "??" << r + 1 << "????×???????" << ret << endl;
        cout << endl;
    }

private:
    int row;
    int col;
    int max_len;
    vector<vector<T>> datas;
};


# endif