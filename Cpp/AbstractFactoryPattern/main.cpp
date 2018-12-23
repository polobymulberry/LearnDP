#include <iostream>
#include <memory>
#include <string>

enum class HumanColor { BLACK, WHITE, YELLOW };
enum class HumanSex { FEMALE, MALE };

std::ostream &operator<<(std::ostream &out, const HumanColor &color) {
  switch (color) {
  case HumanColor::BLACK:
    out << "BLACK";
    break;
  case HumanColor::WHITE:
    out << "WHITE";
    break;
  case HumanColor::YELLOW:
    out << "YELLOW";
    break;
  }
  return out;
}

std::ostream &operator<<(std::ostream &out, const HumanSex &sex) {
  switch (sex) {
  case HumanSex::MALE:
    out << "MALE";
    break;
  case HumanSex::FEMALE:
    out << "FEMALE";
    break;
  }

  return out;
}

class Human {
public:
  Human() { std::cout << "Human Construct" << std::endl; }
  virtual ~Human() { std::cout << "~Human" << std::endl; }

  /**
   * @brief getColor
   * 获取肤色
   * @return 肤色
   */
  virtual HumanColor getColor() = 0;

  /**
   * @brief talk
   * 说话（区分语言）
   */
  virtual void talk() = 0;

  /**
   * @brief getSex
   * 获取性别
   * @return 性别
   */
  virtual HumanSex getSex() = 0;
};

class MaleBlackHuman : public Human {
public:
  MaleBlackHuman() { std::cout << "MaleBlackHuman Construct" << std::endl; }

  // Human interface
  virtual HumanColor getColor() override { return HumanColor::BLACK; }
  virtual void talk() override { std::cout << "I am a black man" << std::endl; }
  virtual HumanSex getSex() override { return HumanSex::MALE; }
};

class MaleWhiteHuman : public Human {
public:
  MaleWhiteHuman() { std::cout << "MaleWhiteHuman Construct" << std::endl; }

  // Human interface
  virtual HumanColor getColor() override { return HumanColor::WHITE; }
  virtual void talk() override { std::cout << "I am a white man" << std::endl; }
  virtual HumanSex getSex() override { return HumanSex::MALE; }
};

class MaleYellowHuman : public Human {
public:
  MaleYellowHuman() { std::cout << "MaleYellowHuman Construct" << std::endl; }

  // Human interface
  virtual HumanColor getColor() override { return HumanColor::YELLOW; }
  virtual void talk() override {
    std::cout << "I am a yellow man" << std::endl;
  }
  virtual HumanSex getSex() override { return HumanSex::MALE; }
};

class FemaleBlackHuman : public Human {
public:
  FemaleBlackHuman() { std::cout << "FemaleBlackHuman Construct" << std::endl; }

  // Human interface
  virtual HumanColor getColor() override { return HumanColor::BLACK; }
  virtual void talk() override {
    std::cout << "I am a black woman" << std::endl;
  }
  virtual HumanSex getSex() override { return HumanSex::FEMALE; }
};

class FemaleWhiteHuman : public Human {
public:
  FemaleWhiteHuman() { std::cout << "FemaleWhiteHuman Construct" << std::endl; }

  // Human interface
  virtual HumanColor getColor() override { return HumanColor::WHITE; }
  virtual void talk() override {
    std::cout << "I am a white woman" << std::endl;
  }
  virtual HumanSex getSex() override { return HumanSex::FEMALE; }
};

class FemaleYellowHuman : public Human {
public:
  FemaleYellowHuman() {
    std::cout << "FemaleYellowHuman Construct" << std::endl;
  }

  // Human interface
  virtual HumanColor getColor() override { return HumanColor::YELLOW; }
  virtual void talk() override {
    std::cout << "I am a yellow woman" << std::endl;
  }
  virtual HumanSex getSex() override { return HumanSex::FEMALE; }
};

class HumanFactory {
public:
  HumanFactory() { std::cout << "HumanFactory Construct" << std::endl; }
  virtual ~HumanFactory() { std::cout << "~HumanFactory" << std::endl; }

  virtual std::shared_ptr<Human> createBlackHuman() = 0;
  virtual std::shared_ptr<Human> createWhiteHuman() = 0;
  virtual std::shared_ptr<Human> createYellowHuman() = 0;
};

class MaleHumanFactory : public HumanFactory {
public:
  MaleHumanFactory() { std::cout << "MaleHumanFactory Construct" << std::endl; }
  // HumanFactory interface
  virtual std::shared_ptr<Human> createBlackHuman() override {
    return std::make_shared<MaleBlackHuman>();
  }

  virtual std::shared_ptr<Human> createWhiteHuman() override {
    return std::make_shared<MaleWhiteHuman>();
  }

  virtual std::shared_ptr<Human> createYellowHuman() override {
    return std::make_shared<MaleYellowHuman>();
  }
};

class FemaleHumanFactory : public HumanFactory {
public:
  FemaleHumanFactory() {
    std::cout << "FemaleHumanFactory Construct" << std::endl;
  }
  // HumanFactory interface
  virtual std::shared_ptr<Human> createBlackHuman() override {
    return std::make_shared<FemaleBlackHuman>();
  }

  virtual std::shared_ptr<Human> createWhiteHuman() override {
    return std::make_shared<FemaleWhiteHuman>();
  }

  virtual std::shared_ptr<Human> createYellowHuman() override {
    return std::make_shared<FemaleYellowHuman>();
  }
};

int main() {
  std::cout << "Abstract Factory Pattern" << std::endl;

  MaleHumanFactory maleHumanFactory;
  std::shared_ptr<Human> blackMan = maleHumanFactory.createBlackHuman();
  std::cout << "black man color : " << blackMan->getColor() << std::endl;
  std::cout << "black man sex: " << blackMan->getSex() << std::endl;
  blackMan->talk();

  std::shared_ptr<Human> whiteMan = maleHumanFactory.createWhiteHuman();
  std::cout << "white man color : " << whiteMan->getColor() << std::endl;
  std::cout << "white man sex: " << whiteMan->getSex() << std::endl;
  whiteMan->talk();

  std::shared_ptr<Human> yellowMan = maleHumanFactory.createYellowHuman();
  std::cout << "yellow man color : " << yellowMan->getColor() << std::endl;
  std::cout << "yellow man sex: " << yellowMan->getSex() << std::endl;
  yellowMan->talk();

  FemaleHumanFactory femaleHumanFactory;
  std::shared_ptr<Human> whiteWoman = femaleHumanFactory.createBlackHuman();
  std::cout << "white woman color : " << whiteWoman->getColor() << std::endl;
  std::cout << "white woman sex: " << whiteWoman->getSex() << std::endl;
  whiteWoman->talk();

  std::shared_ptr<Human> blackWoman = femaleHumanFactory.createWhiteHuman();
  std::cout << "black woman color : " << blackWoman->getColor() << std::endl;
  std::cout << "black woman sex: " << blackWoman->getSex() << std::endl;
  blackWoman->talk();

  std::shared_ptr<Human> yellowWoman = femaleHumanFactory.createYellowHuman();
  std::cout << "yellow woman color : " << yellowWoman->getColor() << std::endl;
  std::cout << "yellow woman sex: " << yellowWoman->getSex() << std::endl;
  yellowWoman->talk();

  return 0;
}
