#ifndef __TYPE_LIST_HPP__
#define __TYPE_LIST_HPP__

namespace umm {
struct nil {
    using car = nil;
    using cdr = nil;
};

template <typename TCar, typename TCdr>
struct cons {
    using car = TCar;
    using cdr = TCdr;
};

template <typename T>
using car_t = typename T::car;

template <typename T>
using cdr_t = typename T::cdr;

template <typename... Ts>
struct list;

template <>
struct list<> {
    using type = nil;
};

template <typename T, typename... Ts>
struct list<T, Ts...> {
    using type = cons<T, typename list<Ts...>::type>;
};

template <typename... Ts>
using list_t = typename list<Ts...>::type;

template <typename TList, typename TElement>
struct append;

template <>
struct append<nil, nil> {
    using type = nil;
};

template <typename TElement>
struct append<nil, TElement> {
    using type = cons<TElement, nil>;
};

template <typename TCar, typename TCdr>
struct append<nil, cons<TCar, TCdr>> {
    using type = cons<TCar, TCdr>;
};

template <typename TCar, typename TCdr, typename TElement>
struct append<cons<TCar, TCdr>, TElement> {
    using type = cons<TCar, typename append<TCdr, TElement>::type>;
};

template <typename TList, typename TElement>
using append_t = typename append<TList, TElement>::type;
}

#endif // __TYPE_LIST_HPP__
