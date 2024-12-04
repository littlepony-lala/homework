# 定义目标文件和编译器
CC = gcc
CFLAGS = -Wall -g
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

# 生成报告
report: $(REPORT)

$(REPORT): report.tex
	$(TEX) report.tex

# 清理
clean:
	rm -f $(OBJECTS) $(EXEC) $(REPORT) *.aux *.log

.PHONY: all report clean

说明：

    默认目标: all 默认会生成可执行文件 test。
    目标 $(EXEC): 通过链接 HeapSort.o 和 test.o 生成可执行文件。
    目标 report: 运行 pdflatex 命令生成 PDF 报告。
    目标 clean: 删除中间文件（.o、.aux、.log）以及生成的可执行文件和报告文件。
    自动变量和模式规则:
        $@: 表示当前目标。
        $<: 表示第一个依赖文件。
        使用了通配符规则，.c 文件自动生成 .o。

使用方法：

    生成可执行文件:

    Copymake

    或者

    Copymake test

    生成报告:

    Copymake report

    清理生成的中间文件:

    Copymake clean

加上-O2优化指令
avatar

以下是包含 -O2 优化选项的 Makefile：

Copy# 定义目标文件和编译器
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
