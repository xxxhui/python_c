from demo_ext import *

ret = add(10, 20)

print(ret)

def callback(value):
    print("python callback", value)
    return 1000 + value

ret = setCallback(callback, 1000)

print(ret)

cls = MyClass()
cls.freq = 2
print(cls.get_period())
cls.set_period(10)
print(cls.freq)
print(cls.get_period())


ret = calResult(90.0)
print(ret)
