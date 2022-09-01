#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

using std::cout, std::ostream;
class MyString{
    public:
        MyString();
        MyString(const MyString& str);
        MyString(const char* str);
        ~MyString();
        void resize (size_t n);
        size_t size() const;
        size_t length() const;
        size_t capacity() const;
        const char* data() const;
        bool empty() const;
        const char& front() const;
        const char& at(size_t pos) const;
        void clear();
        MyString& operator=(const MyString& s);
        MyString& operator+=(const MyString& s);
        size_t find(const MyString& str, size_t pos = 0) const;   
        friend ostream& operator<<(ostream& os, const MyString& str);
    private:
        char* _str;
        size_t _size;
        size_t _capacity;
};

#endif