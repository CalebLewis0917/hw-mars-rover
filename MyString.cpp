#include "MyString.h"
#include <iostream>

using std::cout, std::endl, std::ostream;

MyString::MyString(): _str{nullptr}, _size(0), _capacity(1){
    _str = new char[1];
    _str[0] = '\0';
}

MyString::MyString(const MyString& strToCopy): _str{nullptr}, _size(0), _capacity(1){
    if(this!=&strToCopy){
        _capacity = strToCopy.capacity();
        _size = strToCopy.size();
        _str = new char[_capacity];

        for(size_t i = 0; i < _size; i++){
            _str[i] = strToCopy.at(i);
        }
        _str[_capacity-1] = '\0';
    }
}

MyString::MyString(const char* strToCopy): _str{nullptr}, _size(0), _capacity(1){
    while(strToCopy[_size]!='\0'){
        _size++;
    }
    _capacity = _size + 1;
    _str = new char[_capacity];

    for(size_t i = 0; i < _capacity; i++){
        _str[i] = strToCopy[i];
    }
}

MyString::~MyString(){
    delete[] _str;
}

void MyString::resize (size_t n){
    char* resizedStr = new char[n+1];
    size_t tempSize = 0;
    if(this->size()<=n){
        for(size_t i = 0; i < this->size(); i++){
            resizedStr[i] = _str[i];
            tempSize++;
        }
        _size = tempSize;
    }
    else{
        for(size_t i = 0; i < n; i++){
            resizedStr[i] = _str[i];
            tempSize++;
        }
        _size = n;
    }
    resizedStr[n] = '\0';
    delete[] _str;
    _str = resizedStr;
    _capacity = n+1;
}

size_t MyString::size() const{
    return _size;
}

size_t MyString::length() const{
    return _size;
}


size_t MyString::capacity() const{
    return _capacity;
}

const char* MyString::data() const{
    return _str;
}

bool MyString::empty() const{
    if(_size==0){
        return true;
    }
    else{
        return false;
    }
}

const char& MyString::front() const{
    if(!this->empty()){
        return _str[0];
    }
    throw std::invalid_argument("front pee");
}

const char& MyString::at(size_t pos) const{
    if(pos<this->size()){
        return _str[pos];
    }
    throw std::out_of_range("at pee");
}

void MyString::clear(){
    delete[] _str;
    _size = 0;
    _capacity = 1;
    _str = new char[1];
    _str[0] = '\0';
}

MyString& MyString::operator=(const MyString& strToCopy){
    if(this!=&strToCopy){
        delete[] _str;
        _str = new char[strToCopy.size()+1];
        for(size_t i = 0; i < strToCopy.size(); i++){
            _str[i] = strToCopy.at(i);
        }
        _str[strToCopy.size()] = '\0';
        _size = strToCopy.size();
        _capacity = _size + 1;
    }
    return *this;
}

MyString& MyString::operator+=(const MyString& s){
    size_t newSize =  _size + s.size();
    size_t oldSize = _size;
    this->resize(newSize);
    for(size_t i = oldSize; i < newSize; i++){
        _str[i] = s.at(i-oldSize);
        _size++;
    }
    _str[_size] = '\0';
    return *this;
}

size_t MyString::find(const MyString& str, size_t pos) const{
    bool exists = false;
    for(size_t i = pos; i < _size; i++){
        if(_str[i]==str.at(0)){
            exists = true;
            for(size_t j = 0; j < str.size(); j++){
                if(_str[i+j]!=str.at(j)){
                    exists = false;
                }
            }
            if(exists){
                return i;
            }
        }
    }
    return -1;
}

ostream& operator<<(ostream& os, const MyString& str){
    for(size_t i = 0; i < str.size(); i++){
        os << str.at(i);
    }
    return os;
}

