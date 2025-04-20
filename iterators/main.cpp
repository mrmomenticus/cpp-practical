#include <iostream>
#include <array>
//TODO: сделать итератор для array, который будет возвращать зачения умноженные на 2


template <typename T>
    requires std::integral<T>
class Iterator final
{
    using iterator_category = std::input_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_tupe = T;
    using pointer = T *;
    using reference = T &;

public:
    Iterator(T *ptr) : _ptr(ptr) {};
    int &operator*() const { return *_ptr; }
    int *operator->() { return _ptr; }
    // Prefix increment
    Iterator &operator++()
    {
        (&_ptr*2)++;
        return *this;
    }

    // Postfix increment
    Iterator operator++(int)
    {
        Iterator tmp = *this;
        (&_ptr*2)++;
        return tmp;
    }

    Iterator begin() { return &_ptr[0]; };
    Iterator end(){ return &_ptr[10]; };

    friend bool operator==(const Iterator &a, const Iterator &b) { return a._ptr == b._ptr; };
    friend bool operator!=(const Iterator &a, const Iterator &b) { return a._ptr != b._ptr; };

private:
    T *_ptr;
};

int main(int, char **)
{
    std::array <int, 10> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Iterator<int> it;
    for (auto &i : it)
    {
        std::cout << i << " ";
    }
    return 0;
}
