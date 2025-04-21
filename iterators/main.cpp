#include <algorithm>
#include <iostream> // добавлено
#include <catch2/catch_test_macros.hpp>
template <typename T, size_t N>
class SimpleArray {
public:
    class Iterator {
    public:
        using iterator_category = std::random_access_iterator_tag; // исправлено
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        explicit Iterator(pointer ptr) : current(ptr) {}

        reference operator*() const { return *current; }
        pointer operator->() { return current; }

        Iterator& operator++() { ++current; return *this; }
        Iterator operator++(int) { Iterator tmp = *this; ++current; return tmp; }
        Iterator& operator--() { --current; return *this; }
        Iterator operator--(int) { Iterator tmp = *this; --current; return tmp; }

        bool operator==(const Iterator& other) const { return current == other.current; }
        bool operator!=(const Iterator& other) const { return current != other.current; }
        bool operator<(const Iterator& other) const { return current < other.current; }
        bool operator>(const Iterator& other) const { return current > other.current; }
        bool operator<=(const Iterator& other) const { return current <= other.current; }
        bool operator>=(const Iterator& other) const { return current >= other.current; }

        difference_type operator-(const Iterator& other) const { return current - other.current; }
        Iterator operator+(difference_type n) const { return Iterator(current + n); }
        Iterator operator-(difference_type n) const { return Iterator(current - n); }
        Iterator& operator+=(difference_type n) { current += n; return *this; }
        Iterator& operator-=(difference_type n) { current -= n; return *this; }
        reference operator[](difference_type n) const { return *(current + n); }

    private:
        pointer current;
    };

    Iterator begin() { return Iterator(data); }
    Iterator end() { return Iterator(data + N); }
    const Iterator begin() const { return Iterator(data); }
    const Iterator end() const { return Iterator(data + N); }

    T& operator[](size_t index) { return data[index]; }
    const T& operator[](size_t index) const { return data[index]; }

private:
    T data[N];
};

TEST_CASE("My iterators") {
    SimpleArray<int, 5> arr;
    arr[0] = 5; arr[1] = 3; arr[2] = 1; arr[3] = 4; arr[4] = 2;

    for (int num : arr) {
        std::cout << num << " ";
    }
    std::sort(arr.begin(), arr.end());
    REQUIRE(arr[0] == 1);
    REQUIRE(arr[4] == 5);
}
