#include <compare>
#include <set>

using std::reference_wrapper;
using std::strong_ordering;

template <typename T> struct ordered_reference_t {
  reference_wrapper<T> reference;
  int _weight;

  friend constexpr strong_ordering
  operator<=>(const weighted_reference_t &lhs,
              const weighted_reference_t &rhs) {
    return lhs._weight <=> rhs._weight;
  }
};
