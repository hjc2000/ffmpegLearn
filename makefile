CXX=g++
EX_CXXFLAGS=-g -Wall -I./include
USED_LIBS="libavutil libavformat libavcodec libavdevice libswresample"
PKG_CONFIG_CFLAGS=$(shell pkg-config -cflags $(USED_LIBS))
PKG_CONFIG_LIBS=$(shell pkg-config -libs $(USED_LIBS))
TARGET=test.exe
SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp,obj/%.o,$(SRC))
SRC1 = $(wildcard src/*.cpp)
OBJ1 = $(patsubst src/%.cpp,obj/%.o,$(SRC1))

$(TARGET):$(OBJ) $(OBJ1)
	@echo "link $^ --> $@"
	@$(CXX) $^ -o $@ $(PKG_CONFIG_LIBS)

$(OBJ):obj/%.o:%.cpp
	@echo "compile $< --> $@"
	@$(CXX) -c $< -o $@ $(EX_CXXFLAGS) $(PKG_CONFIG_CFLAGS)

$(OBJ1):obj/%.o:src/%.cpp
	@echo "compile $< --> $@"
	@$(CXX) -c $< -o $@ $(EX_CXXFLAGS) $(PKG_CONFIG_CFLAGS)

.PHONY:clean
clean:
	rm -f $(TARGET) obj/*.o

.PHONY:dis
dis:
	@echo $(SRC)
	@echo $(OBJ)
	@echo $(SRC1)
	@echo $(OBJ1)