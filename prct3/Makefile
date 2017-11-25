# José Antonio Álvarez Ocete
# Yábir García Benchakhtir
# Definición de macros para definir las carpetas de trabajo
BIN = ./bin
OBJ = ./obj
SRC = ./src
DOC = ./doc
INC = ./include
CXX = g++
ZIP = ./zip
# Opciones de compilación
CPPFLAGS = -std=c++14 -Wall -g
# Nombre de la práctica
PRJ = practica3


# Las macros se usan en las reglas del makefile como si fuesen variables
# que se sustituyen por su valor definido anteriormente
all: $(BIN)/test

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************
# Creamos los tests

#Para elegir el stack con el que se modifica cambiar el archivo stack.h

$(BIN)/test : $(INC)/stack.h $(INC)/StackMax.h  $(INC)/StackMaxVD.h  $(SRC)/StackMaxVD.cpp  $(SRC)/StackMax.cpp $(INC)/StackMaxQueue.h  $(SRC)/StackMaxQueue.cpp $(SRC)/test.cpp
	$(CXX) $(CPPFLAGS) -I$(INC) $(SRC)/test.cpp -o $@


# ************ Limpieza y encapsulado ************
clean :
	rm -f $(OBJ)/* $(BIN)/* $(ZIP)/*
	rm -rf $(DOC)/html $(DOC)/latex $(DOC)/man

zip : clean
	zip -r $(ZIP)/$(PRJ).zip *
