#!/usr/bin/python

import mymath

def callback(value):
    print("from c ", value)

mymath.setcallback(callback)
mymath.testcallback()