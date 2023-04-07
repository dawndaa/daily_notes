# include <iostream>
# include <fstream>
# include "table.h"
using namespace std;

int choose(ifstream& infile) {
    int id;
    cout << "��ѡ���Ƿ��Զ���������(Ĭ��10*10 1Ϊ�� 0Ϊ�� ): ";
    infile >> id;
    while (id != 0 && id != 1) {
        cout << "������� ����������: ";
        infile >> id;
    } 

    cout << endl;
    return id;
}

int init() {
    cout << "1. �˳�" << endl;
    cout << "2. չʾ���" << endl;
    cout << "3. ��䵥����Ԫ��" << endl;
    cout << "4. ����Ĭ��˳�����" << endl;
    cout << "5. ������" << endl;
    cout << "6. ������" << endl;
    cout << "7. �����" << endl;
    cout << "8. �����" << endl;
    cout << "9. �������ֵ" << endl;
    cout << "10. �������ֵ" << endl;
    cout << "11. ������Сֵ" << endl;
    cout << "12. ������Сֵ" << endl;
    cout << "���������ѡ��: ";

    int id;
    cin >> id;
    while (id < 0 && id > 12) {
        cout << "������� ����������: ";
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
        cout << "�������к�: ";
        infile >> r;
        cout << "�������к�: ";
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
                cout << "�������" << endl;
        }
    }

    cout << "��л����ʹ�� ��������ѱ�����3_out.txt��" << endl;
    
    system("pause");
    return 0;
}