#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject *
mymath_mysquare(PyObject *self, PyObject *args)
{
    int value;
    if (!PyArg_ParseTuple(args, "i", &value))
    {
        return NULL;
    }
    int ret = value * value;
    return Py_BuildValue("i", ret);
}

static PyMethodDef SquareMethods[] = {
    {"mysquare", mymath_mysquare, METH_VARARGS, "math sqrt"},
    {NULL, NULL, 0, NULL}};

static char mymath_docs[] = {
    "calculate the square"};

static struct PyModuleDef mymathmodule = {
    PyModuleDef_HEAD_INIT,
    "mymath",    /* name of module */
    mymath_docs, /* module documentation, may be NULL */
    -1,          /* size of per-interpreter state of the module,
                    or -1 if the module keeps state in global variables. */
    SquareMethods};

PyMODINIT_FUNC
PyInit_mymath(void)
{
    return PyModule_Create(&mymathmodule);
}


// int
// main(int argc, char *argv[])
// {
//     wchar_t *program = Py_DecodeLocale(argv[0], NULL);
//     if (program == NULL) {
//         fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
//         exit(1);
//     }

//     /* Add a built-in module, before Py_Initialize */
//     if (PyImport_AppendInittab("spam", PyInit_mymath) == -1) {
//         fprintf(stderr, "Error: could not extend in-built modules table\n");
//         exit(1);
//     }

//     /* Pass argv[0] to the Python interpreter */
//     Py_SetProgramName(program);

//     /* Initialize the Python interpreter.  Required.
//        If this step fails, it will be a fatal error. */
//     Py_Initialize();

//     /* Optionally import the module; alternatively,
//        import can be deferred until the embedded script
//        imports it. */
//     PyObject *pmodule = PyImport_ImportModule("mymath");
//     if (!pmodule) {
//         PyErr_Print();
//         fprintf(stderr, "Error: could not import module 'mymath'\n");
//     }

//     PyMem_RawFree(program);
//     return 0;
// }