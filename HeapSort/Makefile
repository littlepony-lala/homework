# 定义目标文件和编译器
CC = gcc
CFLAGS = -Wall -g -O2
TEX = pdflatex

# 目标文件
EXEC = test
REPORT = report.pdf

# 源文件
HEADERS = HeapSort.h test.h
SOURCES = HeapSort.c test.c
OBJECTS = $(SOURCES:.c=.o)

# 默认目标
all: $(EXEC)

# 编译可执行文件
$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

# 生成 .o 文件的规则
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# 生成报告
report: $(REPORT)

$(REPORT): report.tex
	$(TEX) report.tex

# 清理
clean:
	rm -f $(OBJECTS) $(EXEC) $(REPORT) *.aux *.log

.PHONY: all report clean
