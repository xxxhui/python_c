import cffi

# 回调函数使用
def callback_fun(value):
    print("Callback function is called with value: %d" % value)
    return value


ffi = cffi.FFI()
ffi.cdef("""
int setCallback(void*);
""")

callback_obj = ffi.callback("int (*)(int)", callback_fun)
lib = ffi.dlopen('libtest.so.0')
lib.setCallback(callback_obj)