#include "custom_vector.h"
#include <cstdlib>
#include <stdexcept>

custom_vector::custom_vector() : _data(nullptr), _size(0), _cap(0) {}

custom_vector::custom_vector(std::size_t count, int value)
    : _data(nullptr), _size(0), _cap(0) {
    reserve(count);
    for (std::size_t i = 0; i < count; ++i) {
        push_back(value);
    }
}

custom_vector::custom_vector(const custom_vector& other)
    : _data(nullptr), _size(0), _cap(0) {
    reserve(other._size);
    for (std::size_t i = 0; i < other._size; ++i) {
        push_back(other._data[i]);
    }
}

custom_vector& custom_vector::operator=(const custom_vector& other) {
    if (this == &other) return *this;
    clear();
    reserve(other._size);
    for (std::size_t i = 0; i < other._size; ++i) {
        push_back(other._data[i]);
    }
    return *this;
}

custom_vector::~custom_vector() {
    std::free(_data);
}

int& custom_vector::operator[](std::size_t i) { return _data[i]; }
const int& custom_vector::operator[](std::size_t i) const { return _data[i]; }

bool custom_vector::empty() const { return _size == 0; }
std::size_t custom_vector::size() const { return _size; }
std::size_t custom_vector::capacity() const { return _cap; }

void custom_vector::reserve(std::size_t new_cap) {
    if (new_cap <= _cap) return;
    reallocate(new_cap);
}

void custom_vector::clear() { _size = 0; }

void custom_vector::push_back(int v) {
    ensure_capacity_for_one();
    _data[_size++] = v;
}

void custom_vector::pop_back() {
    if (_size > 0) --_size;
}

int& custom_vector::back() { return _data[_size - 1]; }
const int& custom_vector::back() const { return _data[_size - 1]; }

void custom_vector::ensure_capacity_for_one() {
    if (_size == _cap) {
        std::size_t new_cap = (_cap == 0 ? 2 : _cap * 2);
        reallocate(new_cap);
    }
}

void custom_vector::reallocate(std::size_t new_cap) {
    int* new_data = static_cast<int*>(std::malloc(sizeof(int) * new_cap));
    for (std::size_t i = 0; i < _size; ++i) {
        new_data[i] = _data[i];
    }
    std::free(_data);
    _data = new_data;
    _cap = new_cap;
}