#ifndef __INTEGRAL_HPP__
#define __INTEGRAL_HPP__

#include <type_traits>

namespace umm {

template <char C>
using char_t = std::integral_constant<char, C>;

template <int I>
using int_t = std::integral_constant<int, I>;

}

#endif // __INTEGRAL_HPP__
