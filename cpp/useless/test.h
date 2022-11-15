# ifndef TEST_H
# define TEST_H

# include <iostream>
# include <string>

class out{
public:
    out(const std::string& s): content(s) { }
    void print(void);
private:
    std::string content;
};

# endif