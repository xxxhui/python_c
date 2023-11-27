import cffi

ffi = cffi.FFI()

ffi.cdef("""
int add(int x, int y);
float add(float a, float b);
""")
lib = ffi.dlopen('libtest.so.0')

ret = lib.add(1, 3)
print(ret)
# ret = lib.add(1.0, 3.0)
# print(ret)
