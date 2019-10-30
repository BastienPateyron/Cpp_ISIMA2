CLASSES=class
HEADERS=header
SRC=$(wildcard $(CLASSES)/*.cpp))
CXX=g++
EXE=prog.exe

MACOS=
#MACOS=-isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk
CXXFLAGS+= -Wall -Wextra -I $(HEADERS) -MMD -g $(MACOS)
LDFLAGS=$(MACOS)

OBJ=$(addprefix build/,$(notdir $(SRC:.cpp=.o)))
# DEP=$(addprefix build/,$(SRC/class:.cpp=.d))
DEP=$(wildcard header/*.hpp)

all: $(OBJ)
	@echo $(SRC)
	@echo $(OBJ)
	@echo all
	@echo $(DEP)
	$(CXX) -o $(EXE) $^ $(LDFLAGS)
	
build/%.o: class/%.cpp
	@echo build
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $@ -c $<

prepare:
	@mkdir -p class
	@mkdir -p header
	@[ ! -f *.cpp ] || mv *.cpp class
	@[ ! -f *.hpp ] || mv *.hpp header

clean:
	rm -rf build core *.gch $(EXE)
