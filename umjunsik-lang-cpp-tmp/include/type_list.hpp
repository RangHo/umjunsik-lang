#ifndef __TYPE_LIST_HPP__
#define __TYPE_LIST_HPP__

#include <type_traits>

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

template <typename TList1, typename TList2>
struct concat;

template <typename TList1>
struct concat<TList1, nil> {
    using type = TList1;
};

template <typename TList2>
struct concat<nil, TList2> {
    using type = TList2;
};

template <typename TCar, typename TCdr, typename TList2>
struct concat<cons<TCar, TCdr>, TList2> {
    using type = cons<TCar, typename concat<TCdr, TList2>::type>;
};

template <typename TList1, typename TList2>
using concat_t = typename concat<TList1, TList2>::type;

template <typename THaystack, typename TNeedle>
struct starts_with;

template <typename THaystack>
struct starts_with<THaystack, nil> {
    using type = std::true_type;
    using rest = THaystack;
};

template <typename TCar, typename THaystackCdr, typename TNeedleCdr>
struct starts_with<cons<TCar, THaystackCdr>, cons<TCar, TNeedleCdr>> {
    using type = typename starts_with<THaystackCdr, TNeedleCdr>::type;
    using rest = THaystackCdr;
};

template <typename THaystackCar, typename THaystackCdr, typename TNeedleCar, typename TNeedleCdr>
struct starts_with<cons<THaystackCar, THaystackCdr>, cons<TNeedleCar, TNeedleCdr>> {
    using type = std::false_type;
    using rest = nil;
};

template <typename THaystack, typename TNeedle>
using starts_with_t = typename starts_with<THaystack, TNeedle>::type;

}

#endif // __TYPE_LIST_HPP__
