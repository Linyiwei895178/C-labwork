#pragma once

template <unsigned N>
struct Power {
    template <class T>
    static T value(T x) {
        return x * Power<N-1>::value(x);
    }
};

template <>
struct Power<1> {
    template <class T>
    static T value(T x) {
        return x;
    }
};

template <unsigned N, class T>
T power(T x) {
    return Power<N>::value(x);
}

// template <unsigned N>
// struct Factorial {
//     enum { VALUE = N * Factorial<N-1>:: VALUE };
// };

// template <>
// struct Factorial<0> {
//     enum { VALUE = 1 };
// };