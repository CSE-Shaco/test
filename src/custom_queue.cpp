#include "custom_queue.h"
#include <cstdlib>
#include <stdexcept>

custom_queue::custom_queue()
    : _buf(nullptr), _cap(0), _head(0), _tail(0), _count(0) {}

custom_queue::~custom_queue() {
    std::free(_buf);
}

bool custom_queue::empty() const { return _count == 0; }
std::size_t custom_queue::size() const { return _count; }

void custom_queue::push(int v) {
    ensure_capacity_for_one();
    _buf[_tail] = v;
    _tail = next(_tail);
    ++_count;
}

void custom_queue::pop() {
    if (_count == 0) return;
    _head = next(_head);
    --_count;
}

int& custom_queue::front() { return _buf[_head]; }
const int& custom_queue::front() const { return _buf[_head]; }

int& custom_queue::back() { return _buf[prev(_tail)]; }
const int& custom_queue::back() const { return _buf[prev(_tail)]; }

void custom_queue::clear() { _head = _tail = _count = 0; }

std::size_t custom_queue::next(std::size_t i) const { return (i + 1) % _cap; }
std::size_t custom_queue::prev(std::size_t i) const { return (i + _cap - 1) % _cap; }

void custom_queue::ensure_capacity_for_one() {
    if (_cap == 0) reallocate(4);
    else if (_count == _cap) reallocate(_cap * 2);
}

void custom_queue::reallocate(std::size_t c) {
    int* new_buf = static_cast<int*>(std::malloc(sizeof(int) * c));
    for (std::size_t i = 0; i < _count; ++i) {
        new_buf[i] = _buf[(_head + i) % _cap];
    }
    std::free(_buf);
    _buf = new_buf;
    _cap = c;
    _head = 0;
    _tail = _count;
}