#ifndef CUSTOM_QUEUE_H
#define CUSTOM_QUEUE_H

#include <cstddef>

class custom_queue {
public:
    custom_queue();
    ~custom_queue();

    bool empty() const;
    std::size_t size() const;

    void push(int v);
    void pop();

    int& front();
    const int& front() const;

    int& back();
    const int& back() const;

    void clear();

private:
    int* _buf;
    std::size_t _cap;
    std::size_t _head, _tail, _count;

    std::size_t next(std::size_t i) const;
    std::size_t prev(std::size_t i) const;
    void ensure_capacity_for_one();
    void reallocate(std::size_t c);
};

#endif // CUSTOM_QUEUE_H