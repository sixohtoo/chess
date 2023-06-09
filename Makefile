SRC_DIR = src
BUILD_DIR = build/debug
CC = gcc
SRC_FILES = ${wildcard ${SRC_DIR}/*.c}
OBJ_NAME = play
INCLUDE_PATHS = -Iinclude 
LIBRARY_PATHS = -Llib -lSDL2_image
COMPILER_FLAGS = -Wall -g -O0
LINKER_FLAGS = -lsdl2

all:
	${CC} ${COMPILER_FLAGS} ${LINKER_FLAGS} ${INCLUDE_PATHS} ${LIBRARY_PATHS} ${SRC_FILES} -o ${BUILD_DIR}/${OBJ_NAME}