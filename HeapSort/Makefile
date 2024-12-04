# 定义变量
CXX = g++
CXXFLAGS = -O2 -Wall
TARGET = test
REPORT = report.pdf
SRC = test.cpp
HEADER = HeapSort.h

# 目标规则：生成可执行文件
all: $(TARGET)

# 生成可执行文件test
$(TARGET): $(SRC) $(HEADER)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# 生成报告
report: $(REPORT)

# 生成report.pdf
$(REPORT): report.tex
	pdflatex report.tex

# 清理中间文件和生成的目标文件
clean:
	rm -f $(TARGET) $(REPORT) *.aux *.log

# 清理仅报告相关文件
clean-report:
	rm -f $(REPORT) *.aux *.log

.PHONY: all clean report clean-report
