#ifndef CUSTOM_VECTOR_H
#define CUSTOM_VECTOR_H

#include <cstddef>

class custom_vector {
public:
    custom_vector();
    explicit custom_vector(std::size_t count, int value = 0);
    custom_vector(const custom_vector& other);
    custom_vector& operator=(const custom_vector& other);
    ~custom_vector();

    // element access
    int& operator[](std::size_t i);
    const int& operator[](std::size_t i) const;

    // capacity
    bool empty() const;
    std::size_t size() const;
    std::size_t capacity() const;

    void reserve(std::size_t new_cap);
    void clear();

    // modifiers
    void push_back(int v);
    void pop_back();

    int& back();
    const int& back() const;

private:
    int* _data;
    std::size_t _size;
    std::size_t _cap;

    void ensure_capacity_for_one();
    void reallocate(std::size_t new_cap);
};

#endif // CUSTOM_VECTOR_H