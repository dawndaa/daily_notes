# include "ex13_4.h"

void Folder::addMsg(Message* m) {
    messages.insert(m);
}

void Folder::remMsg(Message* m) {
    messages.erase(m);
}

void Message::save(Folder& f) { // 这里的& 是引用
    folders.insert(&f); // 这里的& 是取址
    f.addMsg(this); 
}

void Message::remove(Folder& f) {
    folders.erase(&f);
    f.remMsg(this);
}

// add_to_Folders的作用是 让包含m的所有文件夹都包含 this
void Message::add_to_Folders(const Message& m) {
    for (auto f: m.folders)
        f->addMsg(this);
}

// 拷贝构造
Message::Message(const Message& m):
    contents(m.contents), folders(m.folders){
        add_to_Folders(m);
    }

// 将本消息从所有包含本消息的文件夹中删除
void Message::remove_from_Folders() {
    for (auto f: folders) 
        f->remMsg(this);
}

Message::~Message() {
    remove_from_Folders();
}

// 重载赋值运算符
Message& Message::operator=(const Message& rhs) {
    remove_from_Folders(); 
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    
    return *this;
}

void swap(Message& lhs, Message& rhs) {
    using std::swap; 
    // 先在所有文件夹中删除 lhs 和 rhs
    for (auto f: lhs.folders)
        f->remMsg(&lhs);
    for (auto f: rhs.folders)
        f->remMsg(&rhs);
    
    // 再交换
    swap(lhs.folders, rhs.folders);
    swap(rhs.contents, rhs.contents);

    // 再将lhs rhs 添加进文件夹 
    for (auto f: lhs.folders)
        f->addMsg(&lhs);
    for (auto f: rhs.folders)
        f->addMsg(&rhs);
}