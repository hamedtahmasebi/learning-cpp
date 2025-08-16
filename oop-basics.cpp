// OOP In CPP
#include <iostream>
#include <memory>

using namespace std;

class IDrivable { // No interfaces in CPP land, just abstract classes with pure
  // virtual methods
  virtual void drive() = 0;
};

class Car : public IDrivable {
public:
  string brand;
  int year;

  // Car(string brand, int year)
  //     : brand(brand), year(year) {} // parametrized constructor
  virtual ~Car() = default; // destructor, memory management, close files, etc.

  void honk() const { // Marking methods const: enforces read-only access.
    cout << "Boro digeee!" << endl;
  }
  void drive() final {}
};

int main() {
  Car myCar; // stack allocation, destroyed automatically
  myCar.brand = "Audi";
  myCar.year = 2022;
  Car *pCar = new Car(); // heap allocation, must delete manually
  pCar->brand = "BMW";
  pCar->year = 2023;

  // RAII principle: wrap resources in objects with proper destructors (e.g.
  // smart pointers )
  std::unique_ptr<Car> c = std::make_unique<Car>();

  // clang-format off
  // unique_ptr -> single owner, move-only
  // shared_ptr -> multiple owners, reference counting
  // weak_ptr -> non-owning observer
  //
  // | Feature                   | Description                                        |
  // | ------------------------- | -------------------------------------------------- |
  // | `explicit`   | Prevents implicit conversions for constructors                  |
  // | `mutable`    | Allows modification even in `const` method                      |
  // | `final`      | Prevents further inheritance of class or method                 |
  // | `override`   | Compiler checks that function overrides a base virtual function |
  // | `delete`     | Prevents generation of default functions (copy, move)           |
  // | `friend`     | Allows access to private members from another class/function    |
  // | `enum class` | Scoped enum values                                              |
  // clang-format on
}
