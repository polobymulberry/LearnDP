#include <iostream>

class Singleton {
public:
  static Singleton getInstance() {
    static Singleton instance;
    return instance;
  }

  void operation() { std::cout << "singleton operation" << std::endl; }

private:
  // note: 容易忘记
  Singleton() {}
};

int main() {
  std::cout << "Singleton Pattern" << std::endl;

  Singleton::getInstance().operation();

  return 0;
}
