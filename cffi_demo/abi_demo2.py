import cffi


#传递结构体
ffi = cffi.FFI()

ffi.cdef("""
int calculate(void*);
""")

ffi.cdef("""
typedef struct {
    int x;
    int y;
} Point;
""")


point = ffi.new("Point *")
point.x = 10
point.y = 11
lib = ffi.dlopen('libtest.so.0')
ret = lib.calculate(point)
print(ret)