#pragma once

template <class T>
class SimpleVector
{
   T* data;
   int currentSize;
   int currentCapacity;
public:
   SimpleVector();
   SimpleVector(int size);
   SimpleVector(const SimpleVector& other);
   ~SimpleVector();

   void push_back(const T& value);
   void pop_back();
   int size();
   int capacity();
   void resize(int newCapacity);
   void sortData();


};

