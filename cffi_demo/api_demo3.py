from _extdemo import ffi, lib
    
# 回调函数使用
def callback_fun(value):
    # print("来自c的数据", ffi.addressof(value)[0])
    return 1000

callback_obj = ffi.callback("int (*)(void *)", callback_fun)
lib.setCallback(callback_obj)