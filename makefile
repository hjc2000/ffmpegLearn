# 指定编译器
CXX = g++
# 指定编译器选项
EX_CXXFLAGS = -g -Wall -I./include
# 指定链接最终目标文件时的额外链接选项
ex_final_link_flags = -L. -l:dll_test.dll
# 指定要链接的库
used_libs = "libavutil libavformat libavcodec libavdevice libswresample"
# 通过 pkg-config 获取包的头文件、库对应的 gcc 选项
PKG_CONFIG_CFLAGS = $(shell pkg-config -cflags $(used_libs))
PKG_CONFIG_LIBS = $(shell pkg-config -libs $(used_libs))
# 设置最终生成的可执行文件的文件名
TARGET = test.exe
# 需要编译的源文件
# 使用 wildcard 函数，查找当前目录下的所有 cpp 文件，将文件名储存到变量
# SRC 中。变量 SRC 相当于一个数组，本质是一个字符串，数组各个元素用空格
# 分隔
SRC = $(wildcard *.cpp)
# 对变量 SRC 中储存的所有元素进行遍历。% 是通配符。下面这行代码会将
# SRC 中所有元素与 %.cpp 进行匹配，如果符合，则 % 会被赋予对应的值，
# 例如匹配到 main.cpp，则 % 的值变成 main，然后将 % 的值填充到后面
# 的 obj/%.o 中，变成 obj/main.o ，以此类推，对数组 SRC 中的所有
# 元素都会执行此操作，最后，OBJ 也是一个数组。
OBJ = $(patsubst %.cpp,obj/%.o,$(SRC))
# 和上面一样，只不过这里是查找 src 目录下的 cpp 文件
SRC1 = $(wildcard src/*.cpp)
OBJ1 = $(patsubst src/%.cpp,obj/%.o,$(SRC1))
# 在这里汇总最终目标所依赖的所有 o 文件
OBJS = $(OBJ) $(OBJ1)
# 最终目标
$(TARGET):$(OBJS)
	@echo "link $^ --> $@"
	@$(CXX) $^ -o $@ $(PKG_CONFIG_LIBS) $(ex_final_link_flags)

# 下面是各个 OBJ 变量 中的 o 文件的生成规则
$(OBJ):obj/%.o:%.cpp
	@echo "compile $< --> $@"
	@$(CXX) -c $< -o $@ $(EX_CXXFLAGS) $(PKG_CONFIG_CFLAGS)

$(OBJ1):obj/%.o:src/%.cpp
	@echo "compile $< --> $@"
	@$(CXX) -c $< -o $@ $(EX_CXXFLAGS) $(PKG_CONFIG_CFLAGS)

# 清理所有 o 文件和最终目标文件
.PHONY:clean
clean:
	rm -f $(TARGET) obj/*.o
