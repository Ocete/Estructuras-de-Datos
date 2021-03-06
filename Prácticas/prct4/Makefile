SRC = ./src
INC = ./include
OBJ = ./obj
BIN = ./bin
ZIP = ./zip
PRJ = prct4
CXX = g++
CPPFLAGS = -I$(INC) -g
OPT = -std=c++17

all: $(BIN)/test

execute: $(BIN)/test
	$(BIN)/test ./datos/timeline_algorithms.txt ./datos/timeline_movies.txt

valgrind: $(BIN)/test
	valgrind --leak-check=full $(BIN)/test ./datos/timeline_algorithms.txt ./datos/timeline_movies.txt

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
# Creamos los objetos
$(OBJ)/historic_date.o: $(SRC)/historic_date.cpp $(INC)/historic_date.h
	g++ $(CPPFLAGS) $(OPT)  -c  $(SRC)/historic_date.cpp -o $(OBJ)/historic_date.o

$(OBJ)/Chronology.o: $(SRC)/Chronology.cpp $(INC)/Chronology.h $(INC)/historic_date.h
	g++ $(CPPFLAGS) $(OPT)  -c $(SRC)/Chronology.cpp -o $(OBJ)/Chronology.o

$(OBJ)/test.o: $(SRC)/test.cpp $(INC)/Chronology.h $(INC)/historic_date.h
	g++ $(CPPFLAGS) $(OPT)  -c $(SRC)/test.cpp -o $@

$(BIN)/test: $(OBJ)/Chronology.o $(OBJ)/historic_date.o $(OBJ)/test.o
	g++ $(CPPFLAGS) $(OBJ)/test.o $(OBJ)/Chronology.o $(OBJ)/historic_date.o -o $@

# ************ Limpieza ************
clean :
	rm -rf $(OBJ)/* $(BIN)/* ./doc/html ./doc/latex $(ZIP)/*

mrproper : clean
	rm $(BIN)/* doc/html/*

zip : clean
	zip -r $(ZIP)/$(PRJ).zip *
