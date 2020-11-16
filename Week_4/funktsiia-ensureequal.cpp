#include <exception>
#include <string>
#include <stdexcept>
#include <iostream>
#include <sstream>

// using namespace std;

void EnsureEqual(const std::string& left, const std::string& right){
    if (left != right)
    {
        std::string err;
        err += left + " != " + right;

        throw std::runtime_error(err);
    }
}

int main() {
  try {
    EnsureEqual("C++ White", "C++ White");
    EnsureEqual("C++ White", "C++ Yellow");
} catch (std::runtime_error& exc) {
    std::cout << exc.what() << std::endl;
  }
  return 0;
}
