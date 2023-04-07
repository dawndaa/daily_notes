# include <fstream>
# include <unistd.h>
using namespace std;

int main() {
    string path = get_current_dir_name();
    string outName = "/cpp/course/algorithm_analyse/4_14_input.txt";
    ofstream out(path + outName, ios::out);

    int data_cnt = 6;

    for (int i = 0; i < data_cnt; ++i) {
        srand((unsigned)rand());
        int size = rand() % 10 + 10, k = rand() % 5 + 2;
        out << size << " " << k << endl;   
        for (int j = 0; j < size; ++j) {
            srand((unsigned)rand());
            out << (rand() % (2 * k)) + 2 << " ";
        }
        out << endl;
    }

    return 0;
}