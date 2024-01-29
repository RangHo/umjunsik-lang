#ifndef __STRING_HPP__
#define __STRING_HPP__

#include <cstddef>
#include <type_traits>

#include "type_list.hpp"

namespace umm {

template <char C>
using char_t = std::integral_constant<char, C>;

template <char C, char... Cs>
struct char_list {
    using type = list_t<char_t<C>, typename char_list<Cs...>::type>;
};

template <char C>
struct char_list<C> {
    using type = list_t<char_t<C>, nil>;
};

template <char... Cs>
using char_list_t = typename char_list<Cs...>::type;

template <const char* S, size_t I, char CNext>
struct cstring : public std::integral_constant<const char*, S> {
    using type = cons<char_t<S[I]>, typename cstring<S, I + 1, S[I + 1]>::type>;
};

template <const char* S, size_t I>
struct cstring<S, I, '\0'> : public std::integral_constant<const char*, S> {
    using type = nil;
};

template <const char* S>
using cstring_t = typename cstring<S, 0, S[0]>::type;

}

#endif // __STRING_HPP__
