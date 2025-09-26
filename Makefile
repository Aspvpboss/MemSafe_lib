
GCC = gcc
#GCC = gcc

INCLUDE_LIB = -Ilib/include
SRC_LIB = lib/src/*.c
FLAGS = -Wall -Werror -Wpedantic
OUTPUT = out.exe

default: build run


build_lib:


build: 
	@${GCC} ${SRC_LIB} -o ${OUTPUT} ${INCLUDE_LIB} ${FLAGS}  

run:
	@${OUTPUT}