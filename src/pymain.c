#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "structmember.h"

typedef struct {
    PyObject_HEAD
    psych_item_market_t market;
} PsychItemMarketObject;

static PyObject* psych_version(PyObject* self, PyObject *Py_UNUSED(ignored))
{
#ifdef PSYCH_VERSION
    return Py_BuildValue("III", PSYCH_MAJOR_VERSION, PSYCH_MINOR_VERSION, PSYCH_PATCH_VERSION);
#else
    Py_INCREF(Py_None);
    return Py_None;
#endif
}
/**
 * These are tool-util functions packaged with Royal
 */
static PyMethodDef myMethods[] = {
    { "version", psych_version, METH_NOARGS, "Returns a tuple representing the version of psych" },
    { NULL, NULL, 0, NULL }
};

// Our Module Definition struct
static struct PyModuleDef myModule = {
    PyModuleDef_HEAD_INIT,
    "psych",
    "Stock market modeling of the future",
    -1,
    myMethods
};

// Initializes our module using our above struct
PyMODINIT_FUNC PyInit_psych(void)
{
    return PyModule_Create(&myModule);
}