from ctypes import *

lib = CDLL("libtest.so.0")


class POINT(Structure):
    _fields_ = [("x", c_int), ("y", c_int)]


point = POINT(1, 2)
ret = lib.calculate(pointer(point))
print(ret)