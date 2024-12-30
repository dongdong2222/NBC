#include <iostream>
#include "SimpleVector.h"
#include "SimpleVector.cpp"
using namespace std;

int main() {
   SimpleVector<int> sv(2);

   cout << sv.size() << '\n';
   cout << sv.capacity() << '\n';

   sv.push_back(3);
   sv.push_back(7);
   sv.push_back(1);
   sv.push_back(11);

   cout << sv.size() << '\n';
   cout << sv.capacity() << '\n';

   sv.sortData();
   sv.pop_back();

   cout << sv.size() << '\n';
   cout << sv.capacity() << '\n';

   sv.resize(20);
   cout << sv.size() << '\n';
   cout << sv.capacity() << '\n';
}