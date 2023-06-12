#ifndef PPTAS_LIST_H
#define PPTAS_LIST_H

#include <iostream>

#include "listNode.h"
#include "zvector.h"

template <typename T>
class List {
public:
  List();
  List(T);

  ListNode<T> *find(T);                // 查询链表中是否存在该元素

  void clear();
  void insert(T);                      // 在链表末尾插入一个元素
  void update(T, T);                   // 修改第一个为指定元素的的节点
  void erase(T);                       // 删除链表中的一个指定元素，如果有多个，删除第一个

  bool empty() const;                  // 判断链表是否为空

  zvector<T> port() const;
  void display();                      // 用 vector 按照顺序导出所有的元素

protected:
  ListNode<T> *head;
  int size;
};

template <typename T>
List<T>::List() {
  head = nullptr;
  size = 0;
}

template <typename T>
List<T>::List(T val) {
  head = new ListNode<T>(val, nullptr);
  size = 1;
}

template <typename T>
void List<T>::clear() {
  while (head != nullptr) {
    auto p = head;
    head = head->getNxt();
    delete p;
    size--;
  }
}

template <typename T>
void List<T>::insert(T val) {
  ListNode<T> *p = new ListNode<T>(val, nullptr);
  if (head == nullptr) {
    head = p;
  } else {
    ListNode<T> *cur = head;
    while (cur->getNxt() != nullptr) {
      cur = cur->getNxt();
    }
    cur->setNxtNode(p);
  }
  size++;
}

template <typename T>
ListNode<T> *List<T>::find(T val) {
  ListNode<T> *cur = head;
  while (cur != nullptr && cur->getData() != val) {
    cur = cur->getNxt();
  }
  return cur;
}

template <typename T>
void List<T>::update(T lhs, T rhs) {
  ListNode<T> *cur = find(lhs);
  if (cur != nullptr) {
    cur->setData(rhs);
  }
}

template <typename T>
void List<T>::erase(T val) {
  ListNode<T> *cur = head;
  if (head->getData() == val) {
    head = cur->getNxt();
    delete cur;
    size--;
  } else {
    ListNode<T> *pre = nullptr;
    while (cur != nullptr) {
      if (cur->getData() == val) {
        cur = cur->getNxt();
        delete pre->getNxt();
        pre->setNxtNode(cur);
        size--;
      } else {
        pre = cur;
        cur = cur->getNxt();
      }
    }
  }
}

template <typename T>
zvector<T> List<T>::port() const {
  zvector<T> vec;
  ListNode<T> *cur = head;
  while (cur != nullptr) {
    vec.push_back(cur->getData());
    cur = cur->getNxt();
  }
  return vec;
}

template <typename T>
void List<T>::display() {
  ListNode<T> *cur = head;
  while (cur != nullptr) {
    std::cout << cur->getData() << " ";
    cur = cur->getNxt();
  }
}

template <typename T>
bool List<T>::empty() const {
  return size == 0;
}

#endif