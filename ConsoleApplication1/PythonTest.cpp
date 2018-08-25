#include "stdafx.h"

#include <iostream>     // std::cout

#include "PythonTest.h"
#include "Python.h"

using namespace std;

void SimpleWay(int argc, char *argv[], char * envp[])
{

	wchar_t *program = Py_DecodeLocale(argv[0], NULL);
	if (program == NULL) {
		fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
		exit(1);
	}
	Py_SetProgramName(program);  /* optional but recommended */
	Py_Initialize();

	if (false) {
		PyRun_SimpleString("from time import time,ctime\n"
			"print('Today is', ctime(time()))\n");
	}
	else {
		FILE* PythonScriptFile = fopen("c:/MyWork/Python/testCPP.py", "r");
		if (PythonScriptFile) {
			PyRun_SimpleFile(PythonScriptFile, "c:/MyWork/Python/testCPP.py");
			fclose(PythonScriptFile);
		}
	}





	if (Py_FinalizeEx() < 0) {
		exit(120);
	}
	PyMem_RawFree(program);




}



static int numargs = 0;
static double resD = 13.2;
/* Return the number of arguments of the application command line */
static PyObject*
emb_numargs(PyObject *self, PyObject *args)
{
	if (!PyArg_ParseTuple(args, ":numargs"))
		return NULL;
	return PyLong_FromLong(numargs);
}

static PyObject*
emb_set_float(PyObject *self, PyObject *args)
{
	char *s;
	//if (!PyArg_ParseTuple(args, "d", &resD))
		if (!PyArg_ParseTuple(args, "s", &s))
			return NULL;
	return PyLong_FromLong(0);
}


static PyMethodDef EmbMethods[] = {
	{ "numargs", emb_numargs, METH_VARARGS,
	"Return the number of arguments received by the process." },
	{ "emb_set_float", emb_set_float, METH_VARARGS,
	"Copy double to main c++." },
	{ NULL, NULL, 0, NULL }
};

static PyModuleDef EmbModule = {
	PyModuleDef_HEAD_INIT, "emb", NULL, -1, EmbMethods,
	NULL, NULL, NULL, NULL
};

static PyObject*
PyInit_emb(void)
{
	return PyModule_Create(&EmbModule);
}


void EmbeddedWay(int argc, char *argv[], char * envp[])
{

	wchar_t *program = Py_DecodeLocale(argv[0], NULL);
	if (program == NULL) {
		fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
		exit(1);
	}
	Py_SetProgramName(program);  /* optional but recommended */

	numargs = argc;
	PyImport_AppendInittab("emb", &PyInit_emb);

	Py_Initialize();

	if (false) {
		PyRun_SimpleString("from time import time,ctime\n"
			"print('Today is', ctime(time()))\n");
	}
	else {
		FILE* PythonScriptFile = fopen("c:/MyWork/Python/testCPP.py", "r");
		if (PythonScriptFile) {
			PyRun_SimpleFile(PythonScriptFile, "c:/MyWork/Python/testCPP.py");
			fclose(PythonScriptFile);
		}
	}





	if (Py_FinalizeEx() < 0) {
		exit(120);
	}
	PyMem_RawFree(program);




}

