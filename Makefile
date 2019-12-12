GCC = g++
GXX = $(GCC)

STD = -std=c++11
FLAGS = -Wall
ifdef DEBUG
	FLAGS += -DDEBUG
endif

# SFML = -lsfml-graphics -lsfml-window -lsfml-system

COMPILE = $(GXX) $(STD) $(FLAGS)

SRC = src
OBJ = obj
BUILDS = builds
TESTS = tests

all: labo09 compile_tests

main: labo09

compile_tests:

documentation:
	mkdir -p doc && cd doc && mkdir -p doxy && doxygen Doxyfile && make -C doxy/latex && cp doxy/latex/refman.pdf doc.pdf

build_dir:
	mkdir -p $(BUILDS)

obj_dir:
	mkdir -p $(OBJ)

setup: build_dir obj_dir

matrice.o: setup $(SRC)/matrice.h $(SRC)/matrice.cpp
	$(COMPILE) -c $(SRC)/matrice.cpp -o $(OBJ)/matrice.o

labo09.o: setup labo_09_riesen_florian_gallay_david.cpp
	$(COMPILE) -c labo_09_riesen_florian_gallay_david.cpp -o $(OBJ)/labo09.o

labo09: setup matrice.o labo09.o
	$(COMPILE) $(SRC)/matrice.h $(OBJ)/matrice.o $(OBJ)/labo09.o -o $(BUILDS)/labo09

# TESTS
# display_game: $(TESTS)/display_game.cpp game_of_life.o
# 	$(COMPILE) src/game_of_life.h $(OBJ)/game_of_life.o $(TESTS)/display_game.cpp -o $(BUILDS)/display_game

# compute_multiple_gens: $(TESTS)/compute_multiple_gens.cpp game_of_life.o
# 	$(COMPILE) src/game_of_life.h $(OBJ)/game_of_life.o $(TESTS)/compute_multiple_gens.cpp -o $(BUILDS)/compute_multiple_gens

# EXTRA

# sfml.o: extra/sfml.cpp
# 	$(COMPILE) -c extra/sfml.cpp -o $(OBJ)/sfml.o

# sfml: setup game_of_life.o sfml.o
# 	$(COMPILE) $(SRC)/game_of_life.h $(OBJ)/game_of_life.o $(OBJ)/sfml.o -o $(BUILDS)/sfml $(SFML)