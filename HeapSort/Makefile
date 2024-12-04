# 定义变量
CXX = g++
CXXFLAGS = -O2 -Wall
TARGET = test
REPORT = report.pdf

# 默认目标
all: $(TARGET)

# 编译 test.cpp 生成可执行文件 test
$(TARGET): test.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) test.cpp

# 生成报告
report: report.tex
	pdflatex report.tex

# 清理生成的文件
clean:
	rm -f $(TARGET) *.o *.log *.aux $(REPORT)

# 清理所有
distclean: clean
	rm -f $(TARGET)
