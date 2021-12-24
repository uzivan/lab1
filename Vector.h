
#pragma once

#include <cstdint>

template <typename T>
class Vector {
private:
    T *m_array;
    unsigned int m_size;
    unsigned int m_cap;

public:
    Vector() : m_size(0), m_cap(0) { m_array = nullptr; } //создание вектора по умолчанию

    explicit Vector(unsigned int size); //создание вектора длины size

    explicit Vector(unsigned int size, const T &value); //создание вектора длины size и заполнение его значением value

    Vector(unsigned int number, T* items); //скопировать number элемементов из переданного массива items

    Vector(const Vector<T> &other_vector); //конструктор копирования

    ~Vector(); //деструктор

    int size() const { return m_size; } //возвращает длину вектора

    int capacity() const { return m_cap; } //возвращает вместимость вектора

    void reserve(int new_cap); //делает вместимость вектора равной new_cap элементов

    void resize(int new_size);

    void resize(int new_size, const T &value); //делает длину вектора равной new_size элементов, заполняет новые элементы значением value

    void shrink_to_fit(); //уменьшение m_cap до m_size

    T& get(int index); //получение элемента с номером index

    T& front(); //возращает первый элемент

    T& back(); //возвращает последний элемент

    void set(int index, const T &value = T()); //устаноить новое значение value по индексу i

    void push_back(const T &value); //добавление элемнта в конец

    void push_front(const T &value); //добавление элемента в начало

    void pop_back(); //уничтожение последнего элемента

    void clear(); //очистка вектора

    void print(); //вывод на экран

    T& operator[] (int i); //перегрузка оператора []
};

template <typename T>
Vector<T>::~Vector() {
    clear();
}

template <typename T>
Vector<T>::Vector(unsigned int size) {
    m_array = reinterpret_cast<T*>(new int8_t[size * sizeof(T)]);
    m_size = size;
    m_cap = size;
    if (size == 0) m_array = nullptr;
}

template <typename T>
Vector<T>::Vector(unsigned int size, const T &value) {
    m_array = reinterpret_cast<T*>(new int8_t[size * sizeof(T)]);
    m_size = size;
    m_cap = size;
    for (int i = 0; i < m_size; ++i) {
        new(m_array + i) T(value);
    }
    if (size == 0) m_array = nullptr;
}

template <typename T>
Vector<T>::Vector(unsigned int number, T* items) {
    if (items == nullptr) {
        m_array = nullptr;
        m_size = 0;
        m_cap = 0;
    } else {
        m_size = number;
        m_cap = number;
        m_array = reinterpret_cast<T *>(new int8_t[number * sizeof(T)]);
        for (int i = 0; i < m_size; ++i) {
            new(m_array + i) T(items[i]);
        }
    }
}

template<typename T>
Vector<T>::Vector(const Vector<T> &other_vector) {
    m_cap = other_vector.m_cap;
    m_size = other_vector.m_size;
    m_array = reinterpret_cast<T *>(new int8_t[m_cap * sizeof(T)]);
    for (int i = 0; i < m_size; ++i) {
        new(m_array + i) T(other_vector.m_array[i]);
    }
}

template <typename T>
void Vector<T>::clear() {
    for (int i = 0; i < m_size; ++i) {
        (m_array + i)->~T();
    }
    delete[] reinterpret_cast<int8_t*>(m_array);
    m_array = nullptr;
    m_size = 0;
    m_cap = 0;
}

template <typename T>
void Vector<T>::reserve(int new_cap) {
    if (new_cap < 0)
        throw std::runtime_error("\n(Vector) Reserve Message: new_cap < 0\n");
    if (new_cap <= m_cap) return;
    T *new_arr = reinterpret_cast<T*>(new int8_t[new_cap * sizeof(T)]);
    for (int i = 0; i < m_size; ++i) {
        new(new_arr + i) T(m_array[i]); //placement new
    }
    for (int i = 0; i < m_size; ++i) {
        (m_array + i)->~T();
    }
    delete[] reinterpret_cast<int8_t*>(m_array);
    m_array = new_arr;
    m_cap = new_cap;
}

template <typename T>
void Vector<T>::resize(int new_size) {
    if (new_size < 0)
        throw std::runtime_error("\n(Vector) Resize Message: new_size < 0\n");
    if (new_size > m_cap) reserve(new_size);
    if (new_size < m_size) {
        for (int i = new_size; i < m_size; ++i) {
            (m_array + i)->~T();
        }
    }
    m_size = new_size;
}

template <typename T>
void Vector<T>::resize(int new_size, const T &value) {
    if (new_size < 0)
        throw std::runtime_error("\n(Vector) Resize Message: new_size < 0\n");
    if (new_size > m_cap) reserve(new_size);
    if (new_size < m_size) {
        for (int i = new_size; i < m_size; ++i) {
            (m_array + i)->~T();
        }
    } else {
        for (int i = m_size; i < new_size; ++i) {
            new(m_array + i) T(value);
        }
    }
    m_size = new_size;
}

template <typename T>
void Vector<T>::shrink_to_fit() {
    T *new_arr = reinterpret_cast<T*>(new int8_t[m_size * sizeof(T)]);
    for (int i = 0; i < m_size; ++i) {
        new(new_arr + i) T(m_array[i]);
    }
    for (int i = 0; i < m_size; ++i) {
        (m_array + i)->~T();
    }
    delete[] reinterpret_cast<int8_t *>(m_array);
    m_array = new_arr;
    m_cap = m_size;
}

template <typename T>
T& Vector<T>::get(int i) {
    if ((i < 0) || (i >= m_size))
        throw std::runtime_error("\n(Vector) Get Message : Index Out Of Range\n");
    return m_array[i];
}

template <typename T>
T& Vector<T>::front() {
    if (m_size == 0)
        throw std::runtime_error("\n(Vector) Front Message : Vector is empty\n");
    return m_array[0];
}

template <typename T>
T& Vector<T>::back() {
    if (m_size == 0)
        throw std::runtime_error("\n(Vector) Back Message : Vector is empty\n");
    return m_array[m_size - 1];
}


template <typename T>
void Vector<T>::set(int i, const T &value) {
    if ((i < 0) || (i >= m_size))
        throw std::runtime_error("\n(Vector) Set Message : Index Out Of Range\n");
    new(m_array+i) T(value);
}

template <typename T>
void Vector<T>::push_back(const T &value) {
    resize(m_size + 1, value);
}

template <typename T>
void Vector<T>::push_front(const T &value) {
    if ((m_size + 1) > m_cap) reserve(m_size + 1);
    T *new_arr = reinterpret_cast<T*>(new int8_t[m_cap * sizeof(T)]);
    new(new_arr) T(value);
    for (int i = 1; i < (m_size + 1); ++i) {
        new(new_arr + i) T(m_array[i - 1]);
    }
    for (int i = 0; i < m_size; ++i) {
        (m_array + i)->~T();
    }
    delete[] reinterpret_cast<int8_t *>(m_array);
    m_array = new_arr;
    ++m_size;
}

template <typename T>
void Vector<T>::pop_back() {
    if (m_size == 0)
        throw std::runtime_error("\n(Vector) Pop_back Message: size = 0\n");
    resize(m_size - 1);
}

template <typename T>
T& Vector<T>::operator[] (int i) {
    if ((i < 0) || (i >= m_size))
        throw std::runtime_error("\n(Vector) Operator [] Message: Index Out Of Range\n");
    return m_array[i];
}

template<typename T>
void Vector<T>::print() {
    for (int i = 0; i < m_size; ++i) {
        std::cout << get(i) << "\n";
    }
    std::cout << std::endl;
}