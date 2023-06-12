#ifndef PPTAS_KEYLIST_H
#define PPTAS_KEYLIST_H

#include "list.h"

template <typename T, typename Y>
class Info {
  T key;
  Y info;

public:
  Info() {}
  Info(T, Y);

  T getKey() const;
  Y getInfo() const;

  bool operator==(const Info&) const;
  bool operator!=(const Info&) const;
};

template <typename T, typename Y>
class KeyList : public List<Info<T, Y>> {
public:
  Y getInfo(T first) const;

  ListNode<Info<T, Y>> *find(T) const;
  void insert(T, Y);
  void update(T, Y);
  void erase(T);
};

template <typename T, typename Y> 
Info<T, Y>::Info(T x, Y y) : key(x), info(y) {}

template <typename T, typename Y> 
T Info<T, Y>::getKey() const {
  return key;
}

template <typename T, typename Y> 
Y Info<T, Y>::getInfo() const {
  return info;
}

template <typename T, typename Y>
bool Info<T, Y>::operator==(const Info& rhs) const {
  return key == rhs.key && info == rhs.info;
}

template <typename T, typename Y>
bool Info<T, Y>::operator!=(const Info& rhs) const {
  return !(*this == rhs);
}

template <typename T, typename Y> 
ListNode<Info<T, Y>> *KeyList<T, Y>::find(T x) const {
  ListNode<Info<T, Y>> *cur = List<Info<T, Y>>::head;
  while (cur != nullptr) {
    if (cur->getData().getKey() == x) {
      return cur;
    }
    cur = cur->getNxt();
  }
  return cur;
}

template <typename T, typename Y> 
void KeyList<T, Y>::insert(T key, Y info) {
  ListNode<Info<T, Y>> *p = find(key);
  if (p != nullptr) {
    List<Info<T, Y>>::update(p->getData(), Info(key, info));
  } else {
    List<Info<T, Y>>::insert(Info(key, info));
  }
}

template <typename T, typename Y> 
void KeyList<T, Y>::update(T key, Y info) {
  ListNode<Info<T, Y>> *p = find(key);
  assert(p != nullptr);
  p->setData(Info(key, info));
}

template <typename T, typename Y>
void KeyList<T, Y>::erase(T key) {
  ListNode<Info<T, Y>> *p = find(key);
  assert(p != nullptr);
  List<Info<T, Y>>::erase(p->getData());
}

template <typename T, typename Y> 
Y KeyList<T, Y>::getInfo(T key) const {
  ListNode<Info<T, Y>> *p = find(key);
  assert(p != nullptr);
  return find(key)->getData().getInfo();
}

#endif