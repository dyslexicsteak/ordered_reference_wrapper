#pragma once

#ifndef ORDERED_REFERENCE_HPP
#define ORDERED_REFERENCE_HPP

#include <compare>
#include <set>

namespace ordered_reference {
using std::reference_wrapper;
using std::strong_ordering;

template <typename T, std::three_way_comparable U> struct ordered_reference_t {
  reference_wrapper<T> reference;
  U _weight;

  friend constexpr strong_ordering operator<=>(const ordered_reference_t &lhs,
                                               const ordered_reference_t &rhs) {
    return lhs._weight <=> rhs._weight;
  }
};
} // namespace ordered_reference
#endif
