CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
TARGET = main
SOURCE = main.cpp BinarySearchTree.h
REPORT_SRC = report.tex

all: run

run: $(TARGET)
	@chmod +x $(TARGET) 
	./$(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCE)

report: $(REPORT_SRC)
	pdflatex $(REPORT_SRC)
	pdflatex $(REPORT_SRC) 

clean:
	rm -f $(TARGET) *.o *.log *.aux *.pdf

.PHONY: all run report clean
