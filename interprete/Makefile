Gram=sql.tab.c sql.tab.h

all: $(Gram) 
	@g++ -std=c++11 -o calc sql.tab.c sql.c -lm -Wall
	@echo Compiled

$(Gram): sql.y
	@bison -d sql.y

clean:
	@rm -f *.out  *.tab.* calc
	@echo Clean
