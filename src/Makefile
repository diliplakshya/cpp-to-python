CPP_TO_PYTHON_HOME = $(shell pwd)/..

INCL = -I/usr/include/python3.7
LIB = -lpython3.7m # /usr/lib/x86_64-linux-gnu

include $(CPP_TO_PYTHON_HOME)/makefile/MakeVars.in


$(objdir)/libcpptopython.so: $(objdir)/*.o
	(mkdir -p $(objdir); cd $(objdir); g++ $(LIB) -shared -o libcpptopython.so *.o; rm *.o)
$(objdir)/*.o: *.h *.cpp
	(mkdir -p $(objdir); cd $(objdir); g++ -c $(INCL) $(LIB) -fpic ../../../*.cpp)
clean:
	(rm *.gch; mkdir -p $(objdir); cd $(objdir); rm *.o libcpptopython.so)

