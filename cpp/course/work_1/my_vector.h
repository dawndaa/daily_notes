# ifndef MY_VECTOR_H
# define MY_VECOTR_H
# include <vector>
# include <iostream>

template <typename T>
class my_vector {
public:
    void push_back(const T& item) { data.push_back(item); } // 尾插
    std::ostream& print(std::ostream& os) { // 打印数组
        for (int i = 0; i < data.size(); ++i) {
            os << data[i] << " ";
        }
        // for_each(data.begin(), data.end(), [&](const T& x) {os << x << " "; });

        return os;
    }
    void reverse() { // 原地翻转数组
        for (int i = 0, j = data.size() - 1; i <= j; ++i, --j) {
            T tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }
    }
    T find_least() { // 找出数组中最小元素
        T ret = data.front();
        for (int i = 0; i < data.size(); ++i) {
            if (data[i] < ret) ret = data[i];
        }

        return ret;
    }
    void delete_x(const T& x) { // 删除数组中为x的元素
        int id = 0;
        for (int i = 0; i < data.size(); ++i) {
            if (data[i] != x) {
                data[id++] = data[i];
            }
        }

        data.resize(id);
    }
    void swap(T& l, T& r) { // 交换操作
        T tmp = l;
        l = r;
        r = tmp;
    }

private:
    std::vector<T> data;
};

# endif