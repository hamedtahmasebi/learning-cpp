// smart pointer vs raw pointer
#include <iostream>
#include <memory>

struct Foo {
  Foo() { std::cout << "Foo Created" << std::endl; };
  ~Foo() { std::cout << "Foo Destroyed" << std::endl; };
};

int main() {
  {
    Foo foo1 = Foo();
  }

  {
    std::unique_ptr<Foo> foo2 = std::make_unique<Foo>();
  }

  {
    std::shared_ptr<Foo> foo3 = std::make_shared<Foo>();

    long used_count = foo3.use_count();
    auto foo4 =
        foo3; // shared ownership here, this increases the reference use count
    std::cout << "Use count:" << used_count << std::endl;
  }
}

// clang-format off
/*
 *
Key Takeaways
* Don’t `new` and `delete` unless you’re writing low-level code.
* Prefer stack allocation (Foo f;) or smart pointers.
* RAII ensures cleanup even on exceptions.
* Smart pointers make C++ closer to Go’s garbage-collected world — but more explicit.
*/

// clang-format on
