/**
 *@author: ayersz127
 *@time: 2023-04-29
 */

#ifndef PPTAS_zvector_H
#define PPTAS_zvector_H

#include <cassert>
#include <iostream>

template <typename T>
class zvector {
public:
  zvector();                               // 默认构造函数
  zvector(int);
  zvector(int, const T&);                  // 构造函数
  zvector(const zvector&);                 // 拷贝构造
  ~zvector();                              // 析构函数

  T& operator[](const int&);               // 取出指定下标的元素
  bool operator==(const zvector&) const;   // 判断两个 zvector 是否相同
  void push_back(const T& val);            // 将元素插入到 zvector 尾部
  void pop_back();                         // 删除 zvector 尾部的元素

  T* begin();                              // zvector 头指针
  T* end();                                // zvector 尾指针

  zvector& operator=(const zvector&);

  T* find(const T&) const;  // 寻找指定元素，如果找不到返回尾指针

  const int size() const;   // 返回 zvector 的大小
  void resize(const int&);  // 修改 zvector 的 size

  bool empty();  // 返回 zvector 是否为空

  private:
  void expandCapacity(const int&);  // 扩大 zvector 容量

  T* array;       // zvector 元素
  int _capacity;  // zvector 容器容量
  int _size;      // zvector 容器的元素个数
};

template <typename T>
zvector<T>::zvector() {
  _capacity = 5;  // 固定初始的容量大小
  _size = 0;
  array = new T[_capacity];
}

template <typename T>
zvector<T>::zvector(int x) {
  _capacity = x;  // 固定初始的容量大小
  _size = x;
  array = new T[_capacity];
}

template <typename T>
zvector<T>::zvector(int x, const T& val) {
  _capacity = x;
  _size = x;
  array = new T[_capacity];

  for (int i = 0; i < _size; i++) {
    array[i] = val;
  }
}

template <typename T>
zvector<T>::zvector(const zvector<T>& rhs) {
  _capacity = rhs._capacity * 2 + 1;
  _size = rhs._size;
  array = new T[_capacity];

  for (int i = 0; i < rhs._size; i++) {
    array[i] = rhs.array[i];
  }
}

template <typename T>
zvector<T>::~zvector() {
  delete[] array;
  array = nullptr;
  _size = _capacity = 0;
}

template <typename T>
T& zvector<T>::operator[](const int& i) {
  assert(i >= 0 && i < _size);
  return array[i];
}

template <typename T>
bool zvector<T>::operator==(const zvector<T>& rhs) const {
  if (_size != rhs._size) {
    return false;
  }
  for (int i = 0; i < rhs._size; i++) {
    if (array[i] != rhs.array[i]) {
      return false;
    }
  }
  return true;
}

template <typename T>
void zvector<T>::push_back(const T& val) {
  if (_size == _capacity) {
    expandCapacity(_size * 2 + 1);
  }
  array[_size++] = val;
}

template <typename T>
void zvector<T>::pop_back() {
  assert(_size > 0);
  _size--;
}

template <typename T>
T* zvector<T>::begin() {
  return array;
}

template <typename T>
T* zvector<T>::end() {
  return array + _size;
}

template <typename T>
zvector<T>& zvector<T>::operator=(const zvector<T>& rhs) {
  if (this == &rhs) {
    return *this;
  }
  T* buf = new T[rhs._capacity];  // 因为已经存在数据，所以得考虑数据安全
  for (int i = 0; i < rhs._size; i++) {
    buf[i] = rhs.array[i];
  }
  delete[] array;
  array = buf;
  _size = rhs._size;
  _capacity = rhs._capacity;
  return *this;
}

template <typename T>
T* zvector<T>::find(const T& val) const {
  T* pos = array;
  while (pos < end()) {
    if (*pos == val) {
      break;
    }
    pos++;
  }
  return pos;
}

template <typename T>
const int zvector<T>::size() const {
  return _size;
}

template <typename T>
void zvector<T>::resize(const int& newSize) {
  if (_size < newSize) {
    expandCapacity(newSize);
    _size = newSize;
  } else {
    _size = newSize;
  }
}

template <typename T>
bool zvector<T>::empty() {
  return _size == 0;
}

template <typename T>
void zvector<T>::expandCapacity(const int& newCapacity) {
  if (_capacity < newCapacity) {
    _capacity = newCapacity;
    T* buf = new T[_capacity];
    for (int i = 0; i < _size; i++) {
      buf[i] = array[i];
    }
    delete[] array;
    array = buf;
  }
}

#endif  // zvector_H