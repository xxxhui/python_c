from setuptools import setup
from Cython.Build import cythonize

setup(
    name='demo_ext',
    ext_modules=cythonize("demo_ext.pyx"),
)
