Gram=sql.tab.cpp sql.tab.hpp

all: $(Gram) 
	@g++ -std=c++11 -o calc sql.tab.cpp Tabla.cpp pugixml.cpp sql.cpp -lm -Wall
	@echo Compiled

$(Gram): sql.ypp
	@bison -d sql.ypp

clean:
	@rm -f *.out  *.tab.* calc *.exe
	@echo Clean
