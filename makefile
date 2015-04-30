BIN=./bin/
SRC=./src/
INC=./include/
OBJ=./obj/
LIB=./lib/
OPC=-Wall -g
ZIP=./zip/
PRJ=practica4

CXX = g++
CPPFLAGS = -Wall -g -c -I$(INC)


all: $(BIN)esteganografia $(BIN)testcodificar $(BIN)testimagen 

$(BIN)esteganografia: $(OBJ)esteganografia.o $(LIB)libimagen.a 
	g++ $(OBJ)esteganografia.o -limagen -o $(BIN)esteganografia -L$(LIB)

$(BIN)testcodificar: $(OBJ)testcodificar.o $(LIB)libimagen.a 
	g++ $(OBJ)testcodificar.o -limagen -o $(BIN)testcodificar -L$(LIB)

$(BIN)testimagen: $(OBJ)testimagen.o $(LIB)libimagen.a
	g++ $(OBJ)testimagen.o  -limagen -o $(BIN)testimagen -L$(LIB)

$(OBJ)esteganografia.o: $(SRC)esteganografia.cpp 
	g++ $(OPC) -c $(SRC)esteganografia.cpp -o $(OBJ)esteganografia.o -I$(INC)

$(OBJ)testcodificar.o: $(SRC)testcodificar.cpp 
	g++ $(OPC) -c $(SRC)testcodificar.cpp -o $(OBJ)testcodificar.o -I$(INC)

$(OBJ)testimagen.o: $(SRC)testimagen.cpp 
	g++ $(OPC) -c $(SRC)testimagen.cpp -o $(OBJ)testimagen.o -I$(INC)

$(LIB)libimagen.a: $(OBJ)imagen.o $(OBJ)pgm.o $(OBJ)byte.o $(OBJ)codificar.o
	ar rvs $(LIB)libimagen.a $(OBJ)imagen.o $(OBJ)pgm.o $(OBJ)byte.o $(OBJ)codificar.o

$(OBJ)imagen.o: $(SRC)imagen.cpp 
	g++ $(OPC) -c $(SRC)imagen.cpp -o $(OBJ)imagen.o -I$(INC)

$(OBJ)pgm.o: $(SRC)pgm.cpp 
	g++ $(OPC) -c $(SRC)pgm.cpp -o $(OBJ)pgm.o -I$(INC)

$(OBJ)codificar.o: $(SRC)codificar.cpp 
	g++ $(OPC) -c $(SRC)codificar.cpp -o $(OBJ)codificar.o -I$(INC)

$(OBJ)byte.o: $(SRC)byte.cpp 
	g++ $(OPC) -c $(SRC)byte.cpp -o $(OBJ)byte.o -I$(INC)

	
# ************ documentación *******

documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************
clean:
	@echo "Limpiando ficheros temporales"
	@rm -f $(BIN)/* $(OBJ)/* $(LIB)/*.a

mrproper : clean
	rm -f $(BIN)/* doc/html/*

zip: install clean
	@echo "Empaquetando el proyecto"
	@zip -r $(ZIP)$(PRJ).zip ./ -i *.cpp *.h *makefile doc/*.pdf doc/html doc/doxys/*

install:
	@echo "Creando estructura de carpetas"
	@mkdir -p $(BIN) $(SRC) $(OBJ) $(INC) $(LIB) $(ZIP)
