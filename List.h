#pragma once

#include <cstdint>

template <typename T>
class List {
private:
    //template <typename T>
    class Node {
    public:
        Node* next;
        Node* prev;
        T value;

        explicit Node(const T &value = T(), Node *prev=nullptr, Node *next=nullptr) {
            this->value = value;
            this->prev = prev;
            this->next = next;
        }
    };

    int m_size{};
    Node* m_head;
    Node* m_tail;

public:
    List() : m_size(0) { m_head = nullptr; m_tail = nullptr; } //создание пустого списка

    explicit List(int size, const T &value=T()); //создание списка длины size заполненного значением value

    List(int number, T* items); //скопировать number элемементов из переданного массива items

    List(const List<T> &other_list); //конструктор копирования

    ~List(); //деструктор

    int size() { return m_size; } //возвращает длину списка

    T& front(); //получение первого элемента

    T& back(); //получение последнего элемента

    T& get(int index); //получение элемента по индексу i

    void set(int index, const T &value=T());

    std::unique_ptr<List<T>> get_sublist(int start, int end); //возврат части списка (от start до end)

    void push_back(const T &new_value); //добавление элемента в конец

    void push_front(const T &new_value); //добавление элемента в начало

    void insert_at(int index, const T &value);

    void concat(List<T> &other_list);

    void clear();

    void print(); //вывод списка на экран

    void print_back();

    T& operator[] (int i);
};

template<typename T>
List<T>::List(int size, const T &value) : List() {
    if (size < 0)
        throw std::runtime_error("\nList Message: Size < 0\n");
    for (int i = 0; i < size; ++i) {
        push_back(value);
    }
}

template<typename T>
List<T>::List(int number, T* items) : List() {
    if (number < 0)
        throw std::runtime_error("\nList Message: Number < 0\n");
    if (items == nullptr) {
        m_head = nullptr;
        m_tail = nullptr;
        m_size = 0;
    } else {
        for (int i = 0; i < number; ++i) {
            push_back(items[i]);
        }
    }
}

template<typename T>
List<T>::List(const List<T> &other_list) : List() {
    Node *ptr = other_list.m_head;
    for (int i = 0; i < other_list.m_size; ++i) {
        push_back(ptr->value);
        ptr = ptr->next;
    }
}

template <typename T>
List<T>::~List() {
    clear();
}

template <typename T>
T& List<T>::front() {
    if (m_size == 0)
        throw std::runtime_error("\nGet_first Message : List is empty\n");
    return m_head->value;
}

template <typename T>
T& List<T>::back() {
    if (m_size == 0)
        throw std::runtime_error("\nGet_last Message : List is empty\n");
    return m_tail->value;
}

template <typename T>
T& List<T>::get(int index) {
    if ((index >= m_size) || (index < 0))
        throw std::runtime_error("\n(List) Get Message : Index Out Of Range\n");
    if (index <= (m_size / 2)) {
        Node *ptr = m_head;
        for (int i = 0; i < index; ++i) {
            ptr = ptr->next;
        }
        return ptr->value;
    } else {
        Node *ptr = m_tail;
        for (int i = 0; i < (m_size - index - 1); ++i) {
            ptr = ptr->prev;
        }
        return ptr->value;
    }
}

template<typename T>
void List<T>::set(int index, const T &value) {
    if ((index >= m_size) || (index < 0))
        throw std::runtime_error("\n(List) Set Message : Index Out Of Range\n");
    if (index <= (m_size / 2)) {
        Node *ptr = m_head;
        for (int i = 0; i < index; ++i) {
            ptr = ptr->next;
        }
        ptr->value = value;
    } else {
        Node *ptr = m_tail;
        for (int i = 0; i < (m_size - index - 1); ++i) {
            ptr = ptr->prev;
        }
        ptr->value = value;
    }
}

template<typename T>
void List<T>::push_back(const T &new_value) {
    if (m_size == 0) {
        m_head = new Node(new_value);
        m_tail = m_head;
    } else {
        m_tail->next = new Node(new_value);
        Node *tmp = m_tail;
        m_tail = m_tail->next;
        m_tail->prev = tmp;
        m_tail->next = nullptr;
    }
    ++m_size;
}

template<typename T>
void List<T>::push_front(const T &new_value) {
    if (m_head == nullptr) {
        m_head = new Node(new_value);
        m_tail = m_head;
    } else {
        m_head->prev = new Node(new_value);
        m_head->prev->next = m_head;
        m_head = m_head->prev;
        m_head->prev = nullptr;
    }
    ++m_size;
}

template<typename T>
std::unique_ptr<List<T>> List<T>::get_sublist(int start, int end) {
    if ((start > end) || (start >= m_size) || (end >= m_size) || (start < 0) || (end < 0))
        throw std::runtime_error("\nGet_sublist Message : Index Out Of Range\n");
    std::unique_ptr<List<T>> res(new List<T>{});
    for (int i = start; i <= end; ++i) {
        res->push_back(get(i));
    }
    return res;
}

template<typename T>
void List<T>::insert_at(int index, const T &value) {
    if ((index > m_size) || (index < 0))
        throw std::runtime_error("\nInsert_at Message : Index Out Of Range\n");
    if (index == 0) {
        push_front(value);
    } else {
        Node *ptr;
        if (index <= (m_size / 2)) {
            ptr = m_head;
            for (int i = 0; i < (index - 1); ++i) {
                ptr = ptr->next;
            }
        } else {
            ptr = m_tail;
            for (int i = 0; i < (m_size - index); ++i) {
                ptr = ptr->prev;
            }
        }
        //Node *tmp = ptr->next;
        //ptr->next = new Node(value);
        //ptr->next->prev = ptr;
        //ptr->next->next = tmp;
        //tmp->prev = ptr->next;
        //++m_size;
        ptr->value = value;
    }
}

template<typename T>
void List<T>::concat(List<T> &other_list) {
    m_tail->next = other_list.m_head;
    other_list.m_head->prev = m_tail;
    m_tail = other_list.m_tail;
    m_size += other_list.m_size;
    other_list.m_head = nullptr;
    other_list.m_tail = nullptr;
    other_list.m_size = 0;
}

template <typename T>
void List<T>::clear() {
    Node *ptr = m_head;
    for (int i = 0; i < m_size; ++i) {
        ptr->value.~T();
        Node *tmp = ptr;
        ptr=ptr->next;
        delete tmp;
    }
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}

template<typename T>
void List<T>::print() {
    Node *ptr = m_head;
    for (size_t i = 0; i < m_size; ++i) {
        std::cout << ptr->value << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

template<typename T>
void List<T>::print_back() {
    Node *ptr = m_tail;
    for (size_t i = 0; i < m_size; ++i) {
        std::cout << ptr->value << " ";
        ptr = ptr->prev;
    }
    std::cout << std::endl;
}

template <typename T>
T& List<T>::operator[] (int i) {
    if ((i < 0) || (i >= m_size))
        throw std::runtime_error("\n(List) Operator [] Message: Index Out Of Range\n");
    return get(i);
}
