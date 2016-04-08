LIB_DIR=lib
INC_DIR=inc
BIN_DIR=bin
SRC_DIR=src
.PHONY: all clean
all: $(SRC_DIR)/*.c $(LIB_DIR)/*
	cd $(SRC_DIR) && make

clean:
	cd $(SRC_DIR) && make clean
