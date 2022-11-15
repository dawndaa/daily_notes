# ifndef CLASS_TMEPLATE_H
# define CLASS_TMEPLATE_H
# include <vector>
# include <string>
# include <memory>

template <typename T> 
class Blob {
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    /* 
    vector<T>::size_type 可能是嵌套类型 成员函数 成员
    typename的作用是 说明vector<T>::size_type是一个类型
    */

    Blob();
    Blob(std::initializer_list<T> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const T& t) { data->push_back(t); }
    void emplace_back(T&& t) { data->emplace_back(std::move(t)); }
    void pop_back();

    T& back();
    T& operator[](size_type i);

private:    
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string& msg) const;
};

template <typename T>
void Blob<T>::check(size_type i, const std::string& msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
}

template <typename T>
T& Blob<T>::back() {
    check(0, "back on empty Bloc");
    return data->back();
}

template <typename T>
T& Blob<T>::operator[](size_type i) {
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back() {
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

template <typename T>
Blob<T>::Blob(): data(std::make_shared<std::vector<T>>()) { }

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il):
    data(std::make_shared<std::vector<T>>(il)) { }

# endif