#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject *my_callback = NULL;

static PyObject *
mymath_setcallback(PyObject *dummy, PyObject *args)
{
    PyObject *result = NULL;
    PyObject *temp;

    if (PyArg_ParseTuple(args, "O:set_callback", &temp)) {
        if (!PyCallable_Check(temp)) {
            PyErr_SetString(PyExc_TypeError, "parameter must be callable");
            return NULL;
        }
        Py_XINCREF(temp);         /* Add a reference to new callback */
        Py_XDECREF(my_callback);  /* Dispose of previous callback */
        my_callback = temp;       /* Remember new callback */
        /* Boilerplate to return "None" */
        Py_INCREF(Py_None);
        result = Py_None;
    }
    return result;
}

static PyObject *
mymath_testcallback(PyObject *self, PyObject *args)
{
    int arg;
    PyObject *arglist;
    PyObject *result;
    arg = 123;
    /* Time to call the callback */
    arglist = Py_BuildValue("(i)", arg);
    result = PyObject_CallObject(my_callback, arglist);
    Py_DECREF(arglist);
    if (result == NULL)
        return NULL; /* Pass error back */
    /* Here maybe use the result */
    Py_DECREF(result);
    return Py_None;
}

static PyMethodDef SquareMethods[] = {
    {"setcallback", mymath_setcallback, METH_VARARGS, "setcallback"},
    {"testcallback", mymath_testcallback, METH_VARARGS, "test setcallback"},
    {NULL, NULL, 0, NULL}};


static struct PyModuleDef mymathmodule = {
    PyModuleDef_HEAD_INIT,
    "mymath",    /* name of module */
    NULL, /* module documentation, may be NULL */
    -1,          /* size of per-interpreter state of the module,
                    or -1 if the module keeps state in global variables. */
    SquareMethods};

PyMODINIT_FUNC
PyInit_mymath(void)
{
    return PyModule_Create(&mymathmodule);
}

