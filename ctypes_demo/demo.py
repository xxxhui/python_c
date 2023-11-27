import ctypes

lib = ctypes.cdll.LoadLibrary('./libtest.so.0')

addf = lib.addf
lib.addf.restype = ctypes.c_float
ret = lib.addf(ctypes.c_float(2.0), ctypes.c_float(3.0))

print(ret)
