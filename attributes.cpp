
#include <cstdlib> // required for attributes

[[noreturn]] void function_no_return() { // C++11
  exit(0);
  // Applied only to functions
  // this function will not return, it only exit() or throw
};

[[deprecated]] void function_deprecated() { // C++14
  // Applied to any entity, function/type/var
  return;
};

[[nodiscard]] int dont_discard_return() { // C++17
  // warns if returned value is discarded
  // Applied to function/type
  return 0;
};

[[maybe_unused]] int suppress_unused_warning() { // C++17
  // This suppresses unused warning
  // Applied to function/var/type
  [[maybe_unused]] int myNum = 4;
  int myNum2 = 5;
  return 0;
};

int main() {

  function_deprecated();         // should show a warning for deprecation
  int r = dont_discard_return(); // should not give warning
  dont_discard_return();         // should give warning

  int v = suppress_unused_warning(); // This should NOT error

  return 0;
};

//  *** there are some other attributes, but not used as much ***
