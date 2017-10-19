# Definición de macros para definir las carpetas de trabajo
BIN = ./bin
OBJ = ./obj
SRC = ./src
INC = ./include
CXX = g++
ZIP = ./zip
# Opciones de compilación
OPT = -Wall -g  -I$(INC) -O2 -std=c++11
# Nombre de la práctica
PRJ = practica2


# Las macros se usan en las reglas del makefile como si fuesen variables
# que se sustituyen por su valor definido anteriormente
all: $(BIN)/pruebacronologia

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************
# Creamos los objetos
$(OBJ)/fecha_historica.o : $(SRC)/fecha_historica.cpp $(INC)/fecha_historica.h $(INC)/vector_dinamico.h
	g++ $(OPT) -I./$(INC) -c  $(SRC)/fecha_historica.cpp -o $(OBJ)/fecha_historica.o

$(OBJ)/cronologia.o : $(SRC)/cronologia.cpp $(INC)/cronologia.h $(INC)/fecha_historica.h $(INC)/vector_dinamico.h
	g++ $(OPT) -I./$(INC) -c $(SRC)/cronologia.cpp -o $(OBJ)/cronologia.o

# Creamos pruebacronologia
$(OBJ)/pruebacronologia.o : $(SRC)/pruebacronologia.cpp $(INC)/cronologia.h $(INC)/fecha_historica.h
	g++ $(OPT) -I./$(INC) -c $(SRC)/pruebacronologia.cpp -o $(OBJ)/pruebacronologia.o

$(BIN)/pruebacronologia : $(OBJ)/pruebacronologia.o $(OBJ)/cronologia.o $(OBJ)/fecha_historica.o
	g++ $(OBJ)/pruebacronologia.o -o $(BIN)/pruebacronologia $(OBJ)/cronologia.o $(OBJ)/fecha_historica.o

# ************ Limpieza y encapsulado ************
clean :
	-rm -r $(OBJ)/* $(BIN)/* $(ZIP)/*

zip : clean
	zip -r $(ZIP)/$(PRJ).zip *
