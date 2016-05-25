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
OBJECTS = $(SOURCES:src/%.cpp=%.obj)

all: $(TARGET)

clean:
	del *.obj $(TARGET)

$(TARGET): $(OBJECTS)
	cl /EHsc $(OBJECTS) /Femain
# /MT lib/gurobi_c++mt2012.lib lib/gurobi65.lib /F268435456
	
# debug: cl /Zi /EHse
# release: cl /Ox /O2 /Ot /EHsc
%.obj: src/%.cpp $(HEADERS)
	cl /EHsc $< /c
