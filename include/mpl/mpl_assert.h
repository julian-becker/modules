#pragma once

namespace Assert {
    
    struct test_passed { static constexpr bool passed = true; };
    struct test_failed { static constexpr bool passed = false; };
    
    template <bool pass> struct check_true : test_failed {};
    template <> struct check_true<true> : test_passed {};
    
#pragma GCC diagnostic push
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunneeded-internal-declaration"
#pragma GCC diagnostic ignored "-Wunneeded-internal-declaration"
    auto handle_test = [](auto shouldFail) {
        static_assert(decltype(shouldFail)::passed,"assertion failed");
    };
#pragma clang diagnostic pop
#pragma GCC diagnostic pop

    
    template <bool x> using
    is_true = decltype(handle_test(check_true<x>{}));
    
    template <bool x> using
    is_false = decltype(handle_test(check_true<!x>{}));


    template <typename,typename> struct check_equal : test_failed {};
    template <typename A> struct check_equal<A,A> : test_passed {};

    template <typename A, typename B> using
    are_equal = decltype(handle_test(check_equal<A,B>{}));

    template <typename,typename> struct check_different : test_passed {};
    template <typename A> struct check_different<A,A> : test_failed {};

    template <typename A, typename B> using
    are_different = decltype(handle_test(check_different<A,B>{}));
};


