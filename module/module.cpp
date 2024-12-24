#include <Python.h>

static PyObject *ModuleError;

// A function 'method' of the module
static PyObject *
module_sayhello(PyObject *self, PyObject *args)
{
    int sts = 10;
    return PyLong_FromLong(sts);
}

// Definition of the methods of the module
PyMethodDef methods[] = {
    {"sayhello", (PyCFunction) module_sayhello, METH_NOARGS, NULL},
    {NULL},
};

// A struct contains the definition of a module
PyModuleDef _module = {
    PyModuleDef_HEAD_INIT,
    "module", // Module name
    "This the Module's docstring",
    -1,   // Optional size of the module state memory
    methods, // Optional module methods
    NULL, // Optional slot definitions
    NULL, // Optional traversal function
    NULL, // Optional clear function
    NULL  // Optional module deallocation function
};

// Definition of a module
PyMODINIT_FUNC
PyInit_module(void)
{
    PyObject *m;

    m = PyModule_Create(&_module);
    if (m == NULL)
        return NULL;

    ModuleError = PyErr_NewException("module.error", NULL, NULL);
    if (PyModule_AddObjectRef(m, "error", ModuleError) < 0) {
        Py_CLEAR(ModuleError);
        Py_DECREF(m);
        return NULL;
    }

    return m;
}
