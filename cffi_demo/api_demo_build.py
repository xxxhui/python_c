from cffi import FFI

ffibuilder = FFI()
ffibuilder.cdef("""
                int add(int a, int b);
                int calculate(void *point);
                void setCallback(void*);
                typedef struct {
                    int x;
                    int y;
                } Point;
                Point getPoint();
                Point *getPointRef();
                """)
ffibuilder.set_source('_extdemo',
    """
        #include "api_test.h"
    """,
    sources=['api_test.c'],
    include_dirs=["./"],
    libraries=[])


if __name__ == "__main__":
    ffibuilder.compile(verbose=True)