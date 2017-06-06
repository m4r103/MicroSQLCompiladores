Gram=sql.tab.cpp sql.tab.h

all: $(Gram)
	@g++ -std=c++11 -o calc *.cpp
	@echo Compiled

$(Gram):sql.ypp
	@bison -d sql.ypp

clean:
	@rm -f *.out  *.tab.* calc
	@echo Clean