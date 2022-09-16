# ifndef SCREEN_H
# define SCREEN_H
# include <string>
using namespace std;

class Screen{
    using pos = std::string::size_type;
    pos height = 0, width = 0;
    pos cursor = 0;
    string contents;
public:
    Screen() = default;
    Screen(pos ht, pos wid): height(ht), width(wid), contents((ht * wid, " ")) { };
    Screen(pos ht, pos wid, char c): height(ht), width(wid), contents(to_string(c) + (ht * wid, " ") + "end") { };

    Screen& move(pos r, pos c);
    Screen& set(char c);
    Screen& set(pos row, pos col, char c);
    Screen& display(ostream& os) {
        do_display(os); return *this;
    }
    const Screen& display(ostream& os) const {
        do_display(os); return *this;
    }
private:
    void do_display(ostream& os) const {os << contents;}
};

inline Screen& Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}
inline Screen& Screen::set(pos row, pos col, char c) {
    contents[row * width + col] = c;
    return *this;
}
inline Screen& Screen::move(pos r, pos c) {
    cursor = r * width + c;
    return *this;
}

# endif
