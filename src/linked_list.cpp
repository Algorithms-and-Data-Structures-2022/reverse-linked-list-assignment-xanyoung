#include "assignment/linked_list.hpp"

#include <utility> // swap

namespace assignment {

  /**
   * Переворачивает связный список, используя три указателя.
   *
   * Сложность
   *    по памяти ~ O(1)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseIterative() {

    if (size_ == 0){
      return;
    }
    Node* curr = front_;
    Node* next = front_->next;
    Node* prev = nullptr;

    while (next != nullptr){
      curr -> next = prev;
      prev = curr;
      curr = next;
      next = next->next;
    }
    curr->next = prev;
    back_ = front_;
    front_ = curr;
  }

  /**
   * Переворачивает связный список, используя рекурсию.
   *
   * Сложность
   *    по памяти ~ O(N)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseRecursive() {

    if (size_ == 0){
      return;
    }
    reverse_recursive_helper(front_->next, front_);
    Node* temp = front_;
    front_ = back_;
    back_ = temp;
    back_->next = nullptr;
  }

  // вспомогательный метод для реализации рекурсии
  void LinkedList::reverse_recursive_helper(Node*& curr, Node* prev) {

    if (curr != nullptr) {
      reverse_recursive_helper(curr->next, curr);
      curr->next = prev;
    }
  }

}  // namespace assignment
