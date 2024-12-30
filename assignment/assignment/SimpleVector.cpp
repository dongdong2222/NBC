#include "SimpleVector.h"
#include <algorithm>
using namespace std;

template <class T>
SimpleVector<T>::SimpleVector() {
   data = new T[10];
   currentSize = 0;
   currentCapacity = 10;
}

template <class T>
SimpleVector<T>::SimpleVector(int size) {
   data = new T[size];
   currentSize = 0;
   currentCapacity = size;
}

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector& other) {
   data = other.data;
   currentSize = other.currentSize;
   currentCapacity = other.currentCapacity;
}

template <class T>
SimpleVector<T>::~SimpleVector() {
   if (data == nullptr) {
      delete[] data;
      data = nullptr;
   }
}

template <class T>
void SimpleVector<T>::push_back(const T& value) {
   if (currentCapacity == currentSize) {
      T* temp = new T[currentCapacity + 5];
      for (int i = 0; i < currentSize; i++)
         temp[i] = data[i];
      delete[] data;
      data = temp;
      currentCapacity += 5;
   }
   data[currentSize++] = value;
}

template <class T>
void SimpleVector<T>::pop_back() {
   if (currentSize <= 0) return;
   currentSize--;
}

template <class T>
int SimpleVector<T>::size() {
   return currentSize;
}

template <class T>
int SimpleVector<T>::capacity() {
   return currentCapacity;
}

template <class T>
void SimpleVector<T>::resize(int newCapacity) {
   if (currentCapacity >= newCapacity) return;
   T* temp = new T[newCapacity];
   for (int i = 0; i < currentSize; i++)
      temp[i] = data[i];
   delete[] data;
   data = temp;
   currentCapacity = newCapacity;
}

template <class T>
void SimpleVector<T>::sortData() {
   sort(data, data + currentSize);
}