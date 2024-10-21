all:
	g++ List.cpp -o List -std=c++20 -O2
LATEX = pdflatex
TEX_FILE = report.tex
report: report.pdf

report.pdf: $(TEX_FILE)
	$(LATEX) $(TEX_FILE)
	$(LATEX) $(TEX_FILE)
clean:
	rm -f *.aux *.log *.out *.toc *.pdf

