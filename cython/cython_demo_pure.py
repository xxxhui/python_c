import cython

from cython.cimports.libc.math import sin

@cython.cclass
class Function:
    @cython.ccall
    def evaluate(self, x: float) -> float:
        return 0

@cython.cclass
class SinOfSquareFunction(Function):
    @cython.ccall
    def evaluate(self, x: float) -> float:
        return sin(x)

func = SinOfSquareFunction()
ret = func.evaluate(90)
print(ret)

