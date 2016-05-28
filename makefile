#———————————————————————
# WARNING!
#-----------------------------------------------
# This makefile should only be used in Windows
# and Visual Studio 2012. In addition, the
# "make" must run in "Developer Command Prompt
# for VS2012".
#-----------------------------------------------

TARGET = main.exe
HEADERS = $(wildcard include/*.h)
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(SOURCES:src/%.cpp=build/%.obj)

all: $(TARGET)

clean:
	rm -f build/*.obj $(TARGET)

$(TARGET): $(OBJECTS)
	cl /Zi /W4 /WX /DENABLE_ASSERT /EHsc $(OBJECTS) /Fe$@ /MT lib/gurobi_c++mt2012.lib lib/gurobi65.lib /F268435456
	
# debug: cl /Zi /EHsc
# release: cl /Ox /O2 /Ot /EHsc
build/%.obj: src/%.cpp $(HEADERS)
	cl /Zi /W4 /WX /DENABLE_ASSERT /EHsc $< /c /Fo$@
