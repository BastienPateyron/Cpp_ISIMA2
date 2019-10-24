
SRC=$(class/ wildcard *.cpp)  
CXX=g++
EXE=prog.exe

MACOS=
#MACOS=-isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk
CXXFLAGS+=-Wall -Wextra -MMD -g $(MACOS)
LDFLAGS=$(MACOS)

OBJ=$(addprefix build/,$(SRC:.cpp=.o))
DEP=$(addprefix build/,$(SRC:.cpp=.d))

all: $(OBJ)
	@mkdir -p class
	@mkdir -p header
	[ ! -f *.cpp ] || mv *.cpp class
	echo "Ok"
	@mv *.hpp header
	$(CXX) -o $(EXE) $^ $(LDFLAGS)

build/%.o: class/%.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf build core *.gch $(EXE)

-include $(DEP)
