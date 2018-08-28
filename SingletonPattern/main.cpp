#include <iostream>

class Singleton {
public:
  static Singleton getInstance() {
    static Singleton instance;
    return instance;
  }

  void use() { std::cout << "I am singleton" << std::endl; }

private:
  Singleton() {}
};

int main() {
  std::cout << "Singleton Pattern" << std::endl;

  Singleton::getInstance().use();

  return 0;
}
