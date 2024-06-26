/*
 * This abstract data type minheap provides a minheap data structure.
 * This can be used in a priority queue where in this case the lowest "priority"
 * value (node with the lowest valued item_type) is in the root.
 */
#ifndef _MINHEAP_H
#define _MINHEAP_H

#include <iostream>

using namespace std;

template <typename item_type> struct minheap {
private:
  int capacity;
  int size = 0;
  item_type *items;

  int getLeftChildIndex(int parentIndex) { return 2 * parentIndex + 1; }
  int getRightChildIndex(int parentIndex) { return 2 * parentIndex + 2; }
  int getParentIndex(int childIndex) { return (childIndex - 2) / 2; }

  bool hasLeftChild(int index) { return getLeftChildIndex(index) < size; }
  bool hasRightChild(int index) { return getRightChildIndex(index) < size; }
  bool hasParent(int index) { return getParentIndex(index) >= 0; }

  item_type leftChild(int index) { return items[getLeftChildIndex(index)]; }
  item_type rightChild(int index) { return items[getRightChildIndex(index)]; }
  item_type parent(int index) { return items[getParentIndex(index)]; }

  void traverse() {}

  item_type *increaseCapAndCopy() {
    capacity *= 2;
    item_type *new_items = new item_type[capacity];
    for (int i = 0; i < size; i++) {
      new_items[i] = items[i];
    }
    return new_items;
  }

  void swap(int firstIndex, int secondIndex) {
    item_type temp = items[firstIndex];
    items[firstIndex] = items[secondIndex];
    items[secondIndex] = temp;
  }
  void ensureCapacity() {
    if (size == capacity) {
      items = increaseCapAndCopy();
    }
  }

  void heapifyDown() {
    int index = 0;

    while (hasLeftChild(index)) {
      int smallerChildIndex = getLeftChildIndex(index);
      if (hasRightChild(index) && rightChild(index) < leftChild(index)) {
        smallerChildIndex = getRightChildIndex(index);
      }

      if (items[index] < items[smallerChildIndex]) {
        break;
      } else {
        swap(index, smallerChildIndex);
      }
      index = smallerChildIndex;
    }
  }

  void heapifyUp() {
    int index = size - 1;

    while (hasParent(index) && parent(index) > items[index]) {
      swap(getParentIndex(index), index);
      index = getParentIndex(index);
    }
  }

public:
  minheap() : capacity(10) { items = new item_type[capacity]; }

  int getSize() { return size; }

  item_type *getItems() { return items; }

  void add(item_type value) {
    ensureCapacity();
    items[size] = value;
    size++;
    heapifyUp();
  }

  void priv_print(int index) {
    if (index == this->size)
      return;
    std::cout << index << " " << items[index] << std::endl;
    if (hasLeftChild(index))
      priv_print(getLeftChildIndex(index));
    if (hasRightChild(index))
      priv_print(getRightChildIndex(index));
  }

  void print() { priv_print(0); }
};

#endif
