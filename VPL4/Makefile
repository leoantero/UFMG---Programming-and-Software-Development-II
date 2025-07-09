CC = g++
CFLAGS = -std=c++11 -Wall
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = build


all: vpl_execution


$(OBJ_DIR)/list.o: $(SRC_DIR)/list.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/list.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/list.o


$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/main.o


vpl_execution: $(OBJ_DIR)/main.o $(OBJ_DIR)/list.o
	$(CC) $(CFLAGS) $(OBJ_DIR)/main.o $(OBJ_DIR)/list.o -o vpl_execution


clean:
	rm -f vpl_execution $(OBJ_DIR)/*.o