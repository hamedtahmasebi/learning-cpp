#include <iostream>

// Class with templates, kinda like generics in other languages
template <typename T> class MyVector {
private:
  T *data;
  size_t capacity;
  size_t length;

public:
  // In Cpp we initialize the class using it's name as a method
  MyVector() : data(nullptr), capacity(0), length(0) {}

  void push_back(const T &value) {
    if (length == capacity) {
      size_t new_cap = (capacity == 0) ? 1 : capacity * 2;
      T *new_data = new T[new_cap];
      for (size_t i = 0; i < length; ++i) {
        new_data[i] = data[i];
      }
      delete[] data; // NOTE: delete x is for deleting an object, delete[] is
                     // for an array of objects, use them carefully
                     // int* x = new int;    delete x;
                     // int* arr = new int[5]; delete[] arr;
      data = new_data;
      capacity = new_cap;
    }
    data[length++] = value;
  }
  T &operator[](size_t index) { return data[index]; }
  size_t size() const { return length; };
};

template <typename Iterator> void printAll(Iterator start, Iterator end) {
  for (Iterator it = start; it != end; ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

template <typename T> void swap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
};

int main() {
  int x = 10, y = 20;
  std::cout << "x:" << x << ", y:" << y << std::endl;
  swap(x, y);
  std::cout << "after swap x:" << x << ", y:" << y << std::endl;

  std::vector<int> v = {1, 2, 3};
  printAll(v.begin(), v.end());
}
