Right now whenever we want C++ code to call Python code , we need to write lots of code for this.
Need to take care of de-referencing of Python C API object.

All these can be handled in one Interface in the form of a library, which can be used for embedding Python code into C++.
For this purpose a C++ dynamic library is created, which has interface methods to let C++ code call python code.

This library uses Python 3.4.

Any C++ code can load this binary and use it's methods to communicate with Python code. Such code does not need to write it's own
Python code as all such internal calls are embedded into this dynamic library.


Library Name : libCppPython.so

---------------------------------------------------------------------------------------------------------------------

# Cpp To Python
Embedding Python Into C++
---------------------------------------------------------------------------------------------------------------------
System Requirement;-

Ubuntu 16,04 LTSx64
---------------------------------------------------------------------------------------------------------------------
Prerequisites for Development machine;-

To prepare the development machine to compile and create debian package, run following script;-

bash documents/prerequisite/dev_prerequisite.sh
---------------------------------------------------------------------------------------------------------------------
