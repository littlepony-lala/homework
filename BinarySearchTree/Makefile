all: run

run: $(TARGET)
	./$(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCE)

report: $(REPORT_SRC)
	pdflatex $(REPORT_SRC)
	pdflatex $(REPORT_SRC)

clean:
	rm -f $(TARGET) *.o *.log *.aux *.pdf

.PHONY: all run report clean