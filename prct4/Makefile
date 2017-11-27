SRC = ./src
INC = ./include
OBJ = ./obj
BIN = ./bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c
OPT = -std=c++17

all: $(BIN)/test execute

execute: $(BIN)/test
	$(BIN)/test /datos/timeline_algorithms.txt /datos/timeline_movies.txt

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************
# Creamos los objetos
$(OBJ)/historic_date.o : $(SRC)/historic_date.cpp $(INC)/historic_date.h
	g++ $(OPT) -I./$(INC) -c  $(SRC)/historic_date.cpp -o $(OBJ)/historic_date.o

$(OBJ)/cronology.o : $(SRC)/cronology.cpp $(INC)/cronology.h $(INC)/historic_date.h
	g++ $(OPT) -I./$(INC) -c $(SRC)/cronology.cpp -o $(OBJ)/cronology.o

# Creamos test
$(OBJ)/test.o : $(SRC)/test.cpp $(INC)/cronology.h $(INC)/historic_date.h
	g++ $(OPT) -I./$(INC) -c $(SRC)/test.cpp -o $(OBJ)/test.o

$(BIN)/test : $(OBJ)/test.o $(OBJ)/cronology.o $(OBJ)/historic_date.o
	g++ $(OBJ)/test.o -o $(BIN)/test $(OBJ)/cronology.o $(OBJ)/historic_date.o

# ************ Limpieza ************
clean :
	rm -f $(OBJ)/* $(BIN)/* $(LIB)/*

mrproper : clean
	rm $(BIN)/* doc/html/*
