CPPSRCS=$(wildcard *.cpp)
CSRCS=$(wildcard *.c)

HSRCS=$(wildcard *.h)

OBJS=$(CPPSRCS:.cpp=.o)
COBJS=$(CSRCS:.c=.o)

LDFLAGS=-lboost_thread -lboost_system -lboost_filesystem -lboost_regex -shared
TESTLDFLAGS=-pthread $$PUGIXML_ROOT/build/make-g++-debug-standard/src/pugixml.cpp.o 

CXXFLAGS=$(EXTRACXXFLAGS) -Wall -pedantic -O4 -I$$JAVA_HOME/include -I$$JAVA_HOME/include/linux -fPIC -DPIC
CFLAGS=$(EXTRACFLAGS) -O4 -fPIC -DPIC -DHAVE_CONFIG_H -I. -DPROJ_LIB=\"/usr/local/share/proj\" -DMUTEX_pthread
TESTCXXFLAGS=-pthread -I $$GTEST_ROOT -I$$GTEST_ROOT/include -I$$PUGIXML_ROOT
MAINBIN=bin/com_bjt_ShapeAnalyzer_App.so
TESTBIN=bin/tests

all : $(MAINBIN)

bin : 
	mkdir -p bin

clean :
	$(RM) -f *.gch *.o *.d

sources.d: $(CPPSRCS) $(HSRCS) makefile
	$(CXX) -MM $(CPPSRCS) | sed ':x; /\\$$/ { N; s/\\\n//; tx }' | sed -r -e 's/^(.*)\.o:(.*)$$/\1.o:\2\n\t$$(CXX) $$(CXXFLAGS) -c \1.cpp\n/'>sources.d
#                         ^ combines line continuations                ^ inserts compile command after line 

csources.d: $(CSRCS) $(HSRCS) makefile
	$(CXX) -MM $(CSRCS) | sed ':x; /\\$$/ { N; s/\\\n//; tx }' | sed -r -e 's/^(.*)\.o:(.*)$$/\1.o:\2\n\t$$(CC) $$(CFLAGS) -c \1.c\n/'>csources.d
#                         ^ combines line continuations                ^ inserts compile command after line 

-include sources.d
-include csources.d

$(MAINBIN) : sources.d csources.d $(OBJS) $(COBJS) makefile bin
	$(CXX) $(OBJS) $(COBJS) $(LDFLAGS) -o $(MAINBIN)

printvars : 
	@echo CPPSRCS=$(CPPSRCS)
	@echo CC=$(CC)

always:
