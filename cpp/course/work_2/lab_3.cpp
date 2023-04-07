# include <iostream>
# include <fstream>
# include "table.h"
using namespace std;

int choose(ifstream& infile) {
    int id;
    cout << "请选择是否自定义行列数(默认10*10 1为是 0为否 ): ";
    infile >> id;
    while (id != 0 && id != 1) {
        cout << "输入错误 请重新输入: ";
        infile >> id;
    } 

    cout << endl;
    return id;
}

int init() {
    cout << "1. 退出" << endl;
    cout << "2. 展示表格" << endl;
    cout << "3. 填充单个单元格" << endl;
    cout << "4. 按照默认顺序填充" << endl;
    cout << "5. 列排序" << endl;
    cout << "6. 行排序" << endl;
    cout << "7. 列求和" << endl;
    cout << "8. 行求和" << endl;
    cout << "9. 列求最大值" << endl;
    cout << "10. 行求最大值" << endl;
    cout << "11. 列求最小值" << endl;
    cout << "12. 行求最小值" << endl;
    cout << "请输入你的选择: ";

    int id;
    cin >> id;
    while (id < 0 && id > 12) {
        cout << "输入错误 请重新输入: ";
        cin >> id;
    }

    cout << endl;
    return id;
}

int main() {
    ifstream infile;
    string infile_name = "./3_in.txt";
    infile.open(infile_name, ios::in);
    if (!infile) {
        cout << "open failed!";
    }
    
    ofstream outfile;
    string outfile_name = "./3_out.txt";
    outfile.open(outfile_name, ios::out | ios::trunc);
    if (!outfile) {
        cout << "open failed!";
    }

    Table<int> my_table = Table<int>(10, 10);
    bool flag_1 = false, flag = true;
    int id_1 = choose(infile);
    if (id_1 == 1) {
        int r, c;
        cout << "请输入行号: ";
        infile >> r;
        cout << "请输入列号: ";
        infile >> c;

        cout << endl;
        my_table.resize(r, c);
    }

    while (flag) {
        int id = init();
        switch (id) {
            case 1:
                flag = false;
                break;
            case 2:
                my_table.display();
                break;
            case 3:
                my_table.fill();
                break;
            case 4:
                my_table.fill_by_order();
                break;
            case 5:
                my_table.sort_in_col();
                break;
            case 6:
                my_table.sort_in_row();
                break;
            case 7:
                my_table.sum_in_col();
                break;
            case 8:
                my_table.sum_in_row();
                break;
            case 9:
                my_table.max_in_col();
                break;
            case 10:
                my_table.max_in_row();
                break;
            case 11:
                my_table.min_in_col();
                break;
            case 12:
                my_table.min_in_row();
                break;
            default:
                cout << "输入错误" << endl;
        }
    }

    cout << "感谢您的使用 输出数据已保存在3_out.txt中" << endl;
    
    system("pause");
    return 0;
}