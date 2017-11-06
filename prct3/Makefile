# Definición de macros para definir las carpetas de trabajo
BIN = ./bin
OBJ = ./obj
SRC = ./src
INC = ./include
CXX = g++
ZIP = ./zip
# Opciones de compilación
CPPFLAGS = -std=c++14 -Wall -g
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

$(BIN)/testVDinamico : $(SRC)/testVDinamico.cpp $(INC)/StackMaxVD.h  $(SRC)/StackMaxVD.cpp
	$(CXX) $(CPPFLAGS) -I$(INC) $(SRC)/testVDinamico.cpp -o $(BIN)/testVDinamico


# ************ Limpieza y encapsulado ************
clean :
	-rm -r $(OBJ)/* $(BIN)/* $(ZIP)/*

zip : clean
	zip -r $(ZIP)/$(PRJ).zip *
