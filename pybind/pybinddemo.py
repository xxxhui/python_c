import example

ret = example.add(1, 2)

print(ret)

p = example.Pet("Molly")

print(p.getName())

p.setName("Charly")

print(p.getName())

point = example.getPoint()

print(point.x)


def square(i):
    return i * i


ret = example.func_arg(square)

print(ret)

square_plus_1 = example.func_ret(square)

ret = square_plus_1(4)

print(ret)

plus_1 = example.func_cpp()

plus_1(number=43)

example.test_invoke_py()