#include <iostream>


template <typename T>
requires std::is_default_constructible_v<T>
class Iterator final{
    using iterator_category = std::input_iterator_tag;
    using difference_type = std::ptrdiff_t;
    public:
        Iterator() = default;
        Iterator(Iterator&&) = default;
        Iterator &operator= (Iterator &&) = default;

    private:
        T *ptr;
};

int main(int, char**){
    
}
