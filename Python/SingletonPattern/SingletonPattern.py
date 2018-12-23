class Singleton(object):
    # __member 表示该成员是private，但这不是限制死的
    # Python会将__member解析为_Singleto__member
    __inst = None
    # 这里不能使用__init__，因为__init__是在__inst已经生成以后才去调用的
    def __new__(cls):
        if cls.__inst is None:
            # super方法解释
            # 1.获取cls的MRO列表
            # 2.查找Singleton在当前MRO列表中的index，并返回它的下一个类
            cls.__inst = super(Singleton, cls).__new__(cls)
        return cls.__inst

    def operation(self):
        print("use singleton: ", self)

if __name__ == "__main__":
    singleton0 = Singleton()
    singleton0.operation()

    singleton1 = Singleton()
    singleton1.operation()

