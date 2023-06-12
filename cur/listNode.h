#ifndef PPTAS_LIST_NODE_H
#define PPTAS_LIST_NODE_H

template <typename T>
class ListNode {
public:
  ListNode();
  ListNode(T, ListNode*);
  ~ListNode();

  T getData() const;
  ListNode<T> *getNxt();              // 获取后继节点

  void setData(const T&);  // 设置节点的权值
  void setNxtNode(ListNode<T>*);      // 设置后继节点

private:
  T val;
  ListNode *nxt;
};

template <typename T> 
ListNode<T>::ListNode() : nxt(nullptr) {}

template <typename T>
ListNode<T>::ListNode(T val, ListNode *nxt) : val(val), nxt(nxt) {}

template <typename T>
ListNode<T>::~ListNode() {
  nxt = nullptr;
}

template <typename T>
T ListNode<T>::getData() const {
  return val;
}

template <typename T>
ListNode<T> *ListNode<T>::getNxt() {
  return nxt;
}

template <typename T>
void ListNode<T>::setData(const T &x) {
  val = x;
}

template <typename T>
void ListNode<T>::setNxtNode(ListNode<T> *nt) {
  nxt = nt;
}

#endif