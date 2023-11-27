from _extdemo import ffi, lib


point = ffi.new("Point *")
point.x = 10
point.y = 11

ret = lib.calculate(point)
print(ret)

point = lib.getPoint()
print(point.x, point.y)

pointRef = lib.getPointRef()
x = ffi.addressof(pointRef[0], "x")[0]
print(x)