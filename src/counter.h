#include <cstddef> // size_t
#include <exception> // std:: exception
#include <stdexcept>
#include <iostream>

struct CounterException : std::logic_error {
    CounterException () : std::logic_error("can't create more object") {}
};

template<typename T, size_t Lim> 
struct Counter {
    static size_t objects_alive;

    Counter() {
        if (objects_alive >= Lim) {
            throw CounterException();
        }
        ++objects_alive;
    }

    Counter(const Counter& other) {
        if (objects_alive >= Lim) {
            throw CounterException();
        }
        ++objects_alive;
    }

protected:
    ~Counter() {
        --objects_alive;
    }
};

template<typename T, size_t Lim> size_t Counter<T, Lim>::objects_alive(0); 
