# Definición de macros para definir las carpetas de trabajo
BIN = ./bin
OBJ = ./obj
SRC = ./src
INC = ./include
CXX = g++
ZIP = ./zip
# Opciones de compilación
CPPFLAGS = -std=c++11 -Wall -g
# Nombre de la práctica
PRJ = practica2


# Las macros se usan en las reglas del makefile como si fuesen variables
# que se sustituyen por su valor definido anteriormente
all: $(BIN)/testVDinamico

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************
# Creamos los objetos


$(OBJ)/testVDinamico.o : $(SRC)/testVDinamico.cpp $(INC)/StackMaxVD.h $(INC)/vector_dinamico.h
	$(CXX) $(CPPFLAGS) -I$(INC) -o $(OBJ)/testVDinamico.o $(SRC)/testVDinamico.cpp

$(BIN)/testVDinamico :$(OBJ)/testVDinamico.o
	$(CXX) $(CPPFLAGS) $(OBJ)/testVDinamico.o -o $(BIN)/testVDinamico

# ************ Limpieza y encapsulado ************
clean :
	-rm -r $(OBJ)/* $(BIN)/* $(ZIP)/*

zip : clean
	zip -r $(ZIP)/$(PRJ).zip *
