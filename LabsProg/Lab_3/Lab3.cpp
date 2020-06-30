//
// Created by Sergei on 6/28/2020.
//
#include "Lab3.h"


// int_list_t();
// O(1)
int_list_t::int_list_t() {
    head = new node_t(0, nullptr, nullptr);
    tail = new node_t(0, nullptr, head);
    head->next = tail;
    l_size = 0;
}


// node_t *get(int pos) const;
int_list_t::node_t *int_list_t::get(int pos) const {
    node_t *current;
    if (l_size / 2 > pos) {
        current = head->next;
        while (pos > 0) {
            current = current->next;
            pos--;
        }
    } else {
        current = tail;
        while (pos != l_size) {
            current = current->prev;
            pos++;
        }
        return current;
    }
}


// int_list_t(const int_list_t &other);
// COPY $other list O(other.size)
int_list_t::int_list_t(const int_list_t &other) : int_list_t() {
    l_size = 0;
    auto *current = other.head->next;
    while (current != other.tail) {
        push_back(current->value);
        current = current->next;
    }
}


// int_list_t(size_t count, int value);
// create list $count size and fill it with $value O($count)
int_list_t::int_list_t(size_t count, int value) : int_list_t() {
    for (int i = 1; i < (count - 1); ++i) {
        push_back(value);
    }
}


// O(size)
// ~int_list_t();
int_list_t::~int_list_t() {
    clear();
    delete head;
    delete tail;
}


// O(size + other.size())
// int_list_t &operator=(const int_list_t &other);
int_list_t &int_list_t::operator=(const int_list_t &other) {
    int_list_t copy_o(other);
    swap(copy_o);
    return *this;
}


// O(min($pos, size - $pos))
// int &operator[](size_t pos);
// const int operator[](size_t pos) const;
int &int_list_t::operator[](size_t pos) {
    node_t *current = get(pos);
    return current->value;
}
const int int_list_t::operator[](size_t pos) const {
    node_t *current = get(pos);
    return current->value;
}


// int &back();
// last element O(1)
//
// const int back() const;
// O(1)
int &int_list_t::back() {
    return tail->prev->value;
}
const int int_list_t::back() const {
    return tail->prev->value;
}


// int &front();
// first element O(1)
//
// const int front() const;
// O(1)
int &int_list_t::front() {
    return head->next->value;
}
const int int_list_t::front() const {
    return head->next->value;
}


//    void clear(); // O(size)
//    size_t size() const; // O(1)
//    bool empty() const; // O(1)
void int_list_t::clear() {
    if (!empty()) {
        return;
    }
    node_t *current = head->next;
    node_t *next = current->next;
    for (int i = 0; i < size(); ++i) {
        delete current;
        current = next;
        next = current->next;
    }
    head->next = tail;
    tail->prev = head;
    l_size = 0;
}
size_t int_list_t::size() const {
    return l_size;
}
bool int_list_t::empty() const {
    return l_size == 0;
}


//    void insert(size_t pos, int new_val); // insert element $new_val BEFORE element with index $pos O(min($pos, size - $pos))
//    void push_front(int new_val); // O(1)
//    void push_back(int new_val); // O(1)
void int_list_t::insert(size_t pos, int new_val) {
    node_t *current = get(pos);
    auto *new_node = new node_t(new_val, current, current->prev);
    current->prev->next = new_node;
    current->prev = new_node;
    l_size++;
}
void int_list_t::push_front(int new_val) {
    insert(0, new_val);
}
void int_list_t::push_back(int new_val) {
    insert(l_size, new_val);
}

//    void erase(size_t pos); // remove element with index $pos O(min($pos, size - $pos))
//    void pop_front(); // O(1)
//    void pop_back(); // O(1)
void int_list_t::erase(size_t pos) {
    node_t *current = get(pos);
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    l_size--;
}
void int_list_t::pop_front() {
    erase(0);
}
void int_list_t::pop_back() {
    erase(l_size - 1);
}


//    int_list_t splice(size_t start_pos, size_t count); // splice part of list into result (not copy!) O($start_pos + $count)
int_list_t int_list_t::splice(size_t start_pos, size_t count) {
    int_list_t new_list;
    node_t *current = head;
    for (int i = 0; i < start_pos + 1; i++){
        current = current->next;
    }
    node_t *end_1 = current->prev;
    new_list.head->next = current;
    current->prev = new_list.head;
    for (int i = 0; i < count - 1; i++){
        current = current->next;
    }
    new_list.tail->prev = current;
    node_t *end_2 = current->next;

    end_1->next = end_2;
    end_2->prev = end_1;
    l_size -= count;
    new_list.l_size = count;

    return new_list;
}
//     int_list_t &merge(int_list_t &other); // merge two lists, after operation $other must be valid empty list O(1)
int_list_t &int_list_t::merge(int_list_t &other) {
    if (!other.empty()) {
        tail->prev->next = other.head->next;
        other.head->next->prev = tail->prev;
        other.tail->prev->next = tail;
        tail->prev = other.tail->prev;
        other.head->next = other.tail;
        other.tail->prev = other.head;
        l_size += other.l_size;
        other.l_size = 0;
    }
    return *this;
}


//    void reverse(); // O(size)
void int_list_t::reverse() {
    if (l_size == 0 or l_size == 1){
        return;
    }
    node_t *current = head;
    while (current != nullptr){
        node_t *copy_o = current->next;
        current->next = current->prev;
        current->prev = copy_o;
        if (copy_o == nullptr){
            tail = head;
            head = current;
        }
        current = copy_o;
    }
};
//    void swap(int_list_t &other); // O(1)
void int_list_t::swap(int_list_t &other) {
    std::swap(head, other.head);
    std::swap(tail, other.tail);
    std::swap(l_size, other.l_size);
}


//    friend std::istream &operator>>(std::istream &stream, int_list_t &list); // O(size)
std::istream &operator>>(std::istream &stream, int_list_t &list) {
    int value = 0;
    list.clear();
    while (stream >> value) {
        list.push_back(value);
    }
    return stream;
}
//    friend std::ostream &operator<<(std::ostream &stream, const int_list_t &list); // O(size)
std::ostream &operator<<(std::ostream &stream, const int_list_t &list) {
    auto current = list.head->next;
    while (current != list.tail) {
        stream << current->value << " ";
        current = current->next;
    }
    return stream;
}


