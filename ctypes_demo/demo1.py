from ctypes import *


lib = CDLL("libtest.so.0")


def CallbackFunc(param):
    return 100 + param


CallbackFuncDef = CFUNCTYPE(c_int, c_int)
callback = CallbackFuncDef(CallbackFunc)

# lib.setCallback(callback)

c_setCallback = lib.setCallback
c_setCallback.argtypes = [CallbackFuncDef]
c_setCallback.restype = None
c_setCallback(callback)