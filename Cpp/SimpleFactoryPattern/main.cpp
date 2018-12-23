// https://design-patterns.readthedocs.io/zh_CN/latest/creational_patterns/simple_factory.html

#include <iostream>
#include <memory>
#include <string>

class Product {
public:
  virtual ~Product() {}
  virtual void use() = 0;
};

class ConcreteProductA : public Product {
public:
  virtual ~ConcreteProductA() override {
    std::cout << "~ConcreteProductA" << std::endl;
  }

  // Product interface
  virtual void use() override {
    std::cout << "Use ConcreteProductA" << std::endl;
  }
};

class ConcreteProductB : public Product {
public:
  virtual ~ConcreteProductB() override {
    std::cout << "~ConcreteProductB" << std::endl;
  }

  // Product interface
  virtual void use() override {
    std::cout << "Use ConcreteProductB" << std::endl;
  }
};

class Factory {
public:
  std::shared_ptr<Product> createProduct(std::string name) {
    if (name == "ConcreteProductA") {
      return std::make_shared<ConcreteProductA>();
    } else if (name == "ConcreteProductB") {
      return std::make_shared<ConcreteProductB>();
    }
    return nullptr;
  }
};

int main() {
  std::cout << "Simple Factory Pattern" << std::endl;

  Factory factory;
  std::shared_ptr<Product> productA = factory.createProduct("ConcreteProductA");
  if (productA) {
    productA->use();
  }

  std::shared_ptr<Product> productB = factory.createProduct("ConcreteProductB");
  if (productB) {
    productB->use();
  }

  return 0;
}
