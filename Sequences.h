#pragma once

#include "Vector.h"
#include "List.h"

template <typename T>
class Sequence {
public:
    virtual void concat(Sequence<T> &other_seq) = 0;

    virtual T Get_First() = 0;
    virtual T Get_Last() = 0;
    virtual T Get(int index) = 0;
    virtual int Size() = 0;

    virtual void Prepend(const T& value) = 0;
    virtual void Append(const T& value) = 0;
    virtual void InsertAt(const T& value, int index) = 0;
    virtual void set(int index, const T& value) = 0;

    virtual void print() = 0;

    virtual ~Sequence() = default;
};

template<typename T>
class ArraySequence : public Sequence<T> {
private:
    Vector<T> array_data;
public:
    ArraySequence() : array_data() {} //конструктор по умолчанию

    explicit ArraySequence(unsigned int size, const T &value=T()) : array_data(size, value) {} //создание sequence длины size и заполнение её значением value

    ArraySequence(unsigned int number, T* items) : array_data(number, items) {} //скопировать number элемементов из переданного массива items

    explicit ArraySequence(const Sequence<T> &other_seq) : array_data(other_seq.array_data) {} //конструктор копирования

    explicit ArraySequence(const Vector<T> &other_vector) : array_data(other_vector) {}

    ~ArraySequence() = default;

    T Get_First() { return array_data.front(); }

    T Get_Last() { return array_data.back(); }

    T Get(int index) { return array_data.get(index); }

    void concat(Sequence<T> &other_seq);

    void InsertAt(const T& value, int index);

    int Size() { return array_data.size(); }

    void set(int index, const T &value = T()) { array_data.set(index, value); }

    void Prepend(const T &value){ array_data.push_front(value); }

    void Append(const T &value){ array_data.push_back(value); }

    void print() { array_data.print(); }

    void Resize(int new_size){array_data.resize(new_size);}

    void Read_vector(std::vector<T> vec);
};

template<typename T>
void ArraySequence<T>::Read_vector(std::vector<T> vec) {
    array_data.resize(vec.size());
    for (int i=0;i<vec.size();i++)
        array_data[i] = vec.at(i);
}

template<typename T>
void ArraySequence<T>::concat(Sequence<T> &other_seq) {
    unsigned int tmp_size = array_data.size();
    array_data.resize(array_data.size() + other_seq.Size());
    for (int i = 0; i < other_seq.Size(); ++i) {
        new(&(array_data.get(i + tmp_size))) T(other_seq.Get(i));
    }
}

template<typename T>
void ArraySequence<T>::InsertAt(const T &value, int index) {
    /*if ((index < 0) || (index >= array_data.size()))
        throw std::runtime_error("\n(ArraySequence) Insert_at Message : Index Out Of Range\n");
    array_data.resize(array_data.size() + 1);
    for (int i = array_data.size() - 2; i >= index ; i--) {
        array_data.set(i + 1, array_data.get(i));
    }
    array_data.set(index, value);*/
    array_data[index] = value;
}


template<typename T>
class ListSequence : public Sequence<T> {
private:
    List<T> list_data;
public:
    ListSequence() : list_data() {} //конструктор по умолчанию

    explicit ListSequence(unsigned int size, const T &value=T()) : list_data(size, value) {} //создание sequence длины size и заполнение её значением value

    ListSequence(unsigned int number, T* items) : list_data(number, items) {} //скопировать number элемементов из переданного массива items

    explicit ListSequence(const Sequence<T> &other_seq) : list_data(other_seq.list_data) {} //конструктор копирования

    explicit ListSequence(const List<T> &other_list) : list_data(other_list) {}

    ~ListSequence() = default;

    T Get_First() { return list_data.front(); }

    T Get_Last() { return list_data.back(); }

    T Get(int index) { return list_data.get(index); }

    void concat(Sequence<T> &other_seq);

    void InsertAt(const T& value, int index) {list_data.insert_at(index+1, value); }

    int Size() { return list_data.size(); }

    void set(int index, const T &value = T()) { list_data.set(index, value); }

    void Prepend(const T &value){ list_data.push_front(value); }

    void Append(const T &value){ list_data.push_back(value); }

    void print() { list_data.print(); }

    void Read_vector(std::vector<T> vec);
};

template<typename T>
void ListSequence<T>::Read_vector(std::vector<T> vec){
    for(int i=0;i < vec.size();i++){
        list_data.push_back(vec.at(i));
    }
}

template<typename T>
void ListSequence<T>::concat(Sequence<T> &other_seq) {
    for (int i = 0; i < other_seq.Size(); ++i) {
        list_data.push_back(other_seq.Get(i));
    }
}