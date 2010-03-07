#ifndef NALL_UTILITY_HPP
#define NALL_UTILITY_HPP

#include <nall/traits.hpp>

namespace nall {
  template<typename T> struct identity {
    typedef T type;
  };

  template<typename T> typename remove_reference<T>::type&& move(T &&value) {
    return value;
  }

  template<typename T> T&& forward(typename identity<T>::type &&value) {
    return value;
  }

  template<bool C, typename T = bool> struct enable_if { typedef T type; };
  template<typename T> struct enable_if<false, T> {};
  template<typename C, typename T = bool> struct mp_enable_if : enable_if<C::value, T> {};

  template<typename T> inline void swap(T &x, T &y) {
    T temp(move(x));
    x = move(y);
    y = move(temp);
  }

  template<typename T> struct base_from_member {
    T value;
    base_from_member(T value_) : value(value_) {}
  };

  template<typename T> inline T* allocate(size_t size, const T &value) {
    T *array = new T[size];
    for(size_t i = 0; i < size; i++) array[i] = value;
    return array;
  }
}

#endif