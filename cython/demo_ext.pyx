def add(a, b):
    return a + b

cpdef int setCallback(object context, int value):
    try:
        # recover Python function object from void* argument
        func = <object>context
        return func(value)
    except:
        return -1


cdef class MyClass:

    # Not available in Python-space:
    cdef double offset

    # Available in Python-space:
    cdef public double freq

    # Available in Python-space, but only for reading:
    cdef readonly double scale

    # Available in Python-space:
    #@property
    def get_period(self):
        return 1.0 / self.freq

    #@period.setter
    def set_period(self, value):
        print('from pyx ', value)
        self.freq = 1.0 / value



from libc.math cimport sin


cdef double f(double x):
    return sin(x)

def calResult(value):
    return f(value)