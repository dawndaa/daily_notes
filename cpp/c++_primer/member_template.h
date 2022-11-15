# include <iostream>

class DebugDelete {
public:
    DebugDelete(std::ostream& s = std::cerr): os(s) { }
    template <typename T>
    void operator() (T* p) const {
        os << "deleting unique_ptr" << std:: endl;
        delete p;
    }

private:
    std::ostream& os;
};
template <typename T> class Blob {
    template <typename It> Blob(It b, It e);
};

template <typename T> 
template <typename It>
Blob<T>::Blob(It b, It e) :
    data(std::make_shared<std::vector<T>>(b, e)) { }