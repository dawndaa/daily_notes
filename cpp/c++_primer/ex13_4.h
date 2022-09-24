# ifndef EX13_4_H
# define EX13_4_H

# include <set>
# include <string>

class Message;
class Folder {
    friend class Message;    
    friend void swap(Message&, Message&);
public:

private:
    std::set<Message*> messages;
    void addMsg(Message*);
    void remMsg(Message*);
};

class Message {
    // 声明友元
    friend class Folder;
    friend void swap(Message&, Message&);
public:
    // 构造函数
    explicit Message(const std::string& str = ""):
        contents(str) { }; 
    Message(const Message&);
    // 重载运算符=
    Message& operator=(const Message&);
    // 析构函数
    ~Message();
    // 向给定Folder中添加或删除本消息
    void save(Folder&);
    void remove(Folder&);
private:
    std::string contents; // 消息内容
    std::set<Folder*> folders; // 包含消息的文件夹的指针 的set
    void add_to_Folders(const Message&); // 将某个消息加入Folder
    void remove_from_Folders(); // 将某个消息从Folder中删除
};

# endif