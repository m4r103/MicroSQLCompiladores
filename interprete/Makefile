Gram=y.tab.c y.tab.h

all: $(Gram) 
	@gcc -o calc y.tab.c sql.c -lm -Wall
	@echo Compiled

$(Gram): sql.y
	@yacc -d sql.y

clean:
	@rm -f *.out  *.tab.* calc
	@echo Clean
