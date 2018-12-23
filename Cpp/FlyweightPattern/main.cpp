#include <iostream>
#include <map>
#include <string>

class Flyweight
{
  public:
    Flyweight(const std::string &extrinsic)
        : mExtrinsic(extrinsic)
    {
    }
    virtual ~Flyweight()
    {
    }

    virtual void operation() = 0;

    std::string getIntrinsic() const;
    void setIntrinsic(const std::string &intrinsic);

    std::string getExtrinsic() const;

  private:
    std::string mIntrinsic;
    std::string mExtrinsic;
};

class ConcreteFlyweight : public Flyweight
{
  public:
    ConcreteFlyweight(const std::string &extrinsic)
        : Flyweight(extrinsic)
    {
    }

    virtual ~ConcreteFlyweight()
    {
    }

    virtual void
    operation()
    {
        std::cout << "intrinsic : " << getIntrinsic() << std::endl;
        std::cout << " extrinsic : " << getExtrinsic() << std::endl;
        std::cout << " address : " << this << std::endl;
    }
};

class FlyweightFactory
{
  public:
    Flyweight *
    getFlyweight(const std::string &extrinsic)
    {
        if (mFlyweightMap.find(extrinsic) != mFlyweightMap.end()) {
            return mFlyweightMap.at(extrinsic);
        } else {
            ConcreteFlyweight *flyweight = new ConcreteFlyweight(extrinsic);
            mFlyweightMap.insert(std::make_pair(extrinsic, flyweight));
            return flyweight;
        }
    }

  private:
    std::map<const std::string, Flyweight *> mFlyweightMap;
};

int
main()
{
    std::cout << "Flyweight Pattern" << std::endl;

    FlyweightFactory factory;
    factory.getFlyweight("one");
    factory.getFlyweight("two");
    factory.getFlyweight("three");

    Flyweight *one = factory.getFlyweight("one");
    one->setIntrinsic("one intrinsic");
    one->operation();

    Flyweight *one1 = factory.getFlyweight("one");
    one1->setIntrinsic("one 1 intrinsic");
    one1->operation();

    return 0;
}

std::string
Flyweight::getIntrinsic() const
{
    return mIntrinsic;
}

void
Flyweight::setIntrinsic(const std::string &intrinsic)
{
    mIntrinsic = intrinsic;
}

std::string
Flyweight::getExtrinsic() const
{
    return mExtrinsic;
}
