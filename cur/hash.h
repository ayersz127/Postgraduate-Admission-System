#ifndef PPTAS_HASH_H
#define PPTAS_HASH_H

#include <cstring>
#include <utility>

#include "zvector.h"

constexpr int base = 127;
constexpr int N = 6967;

using u32 = uint32_t;

template <typename T>
u32 getHashValue(T x) {
  auto s = std::to_string(x);
  u32 res = 0u;
  for (int i = 0; i < s.length(); i++) {
    res = (res * base + s[i]) % N;
  }
  return res;
}

template <typename T, typename U>
class hashMap {
private:
  zvector<zvector<std::pair<T, U>>> toHashVal;

public:
  hashMap() : toHashVal(N) {}
  bool count(T, const U&);
  void insert(T, const U&);
  U find(T);
};

template <typename T, typename U>
bool hashMap<T, U>::count(T first, const U& second) {
  auto u = getHashValue(first);
  for (auto [v, val] : toHashVal) {
    if (v == first) {
      return true;
    }
  }
  return false;
}

template <typename T, typename U>
void hashMap<T, U>::insert(T first, const U& second) {
  if (!count(first)) {
    toHashVal[getHashValue(first)].push_back({first, second});
  }
}

template <typename T, typename U>
U hashMap<T, U>::find(T first) {
  auto u = getHashValue(first);
  for (auto [v, val] : toHashVal) {
    if (v == first) {
      return val;
    }
  }
}

#endif