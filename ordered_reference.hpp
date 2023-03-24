#ifndef ORDERED_REFERENCE_HPP
#define ORDERED_REFERENCE_HPP

#include <compare>
#include <set>

namespace ordered_reference {
using std::reference_wrapper, std::strong_ordering, std::three_way_comparable;

template <typename T, three_way_comparable U> struct ordered_reference_t {
  reference_wrapper<T> reference;

  ordered_reference_t<T, U>(const T &referenced, const U &weight) noexcept {
    this->reference = referenced;
    this->_weight = weight;
  }

  friend constexpr strong_ordering
  operator<=>(const ordered_reference_t &lhs,
              const ordered_reference_t &rhs) noexcept {
    return lhs._weight <=> rhs._weight;
  }

private:
  U _weight;
};
} // namespace ordered_reference
#endif
