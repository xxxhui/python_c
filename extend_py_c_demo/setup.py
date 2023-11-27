from distutils.core import setup, Extension

mymathmodulel = Extension('mymath', sources=['mymathmodule2.c'])

setup(
    name='mymath', 
    version='1.0', 
    description='my math lib', 
    ext_modules=[mymathmodulel]
)
