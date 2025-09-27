
GCC = gcc
#GCC = gcc

INCLUDE_LIB = -Ilib/include
SRC_LIB = lib/src/*.c


FLAGS = -Wall -Werror -Wpedantic
OUTPUT = out.exe

DLL_FLAGS = -fPIC -shared  -Wl,--out-implib,libMemSafe.a
DLL_OUTPUT = libMemSafe.dll

default: build run


build_lib:
	@${GCC} ${SRC_LIB} -o ${DLL_OUTPUT} -DMemSafe_EXPORTS ${DLL_FLAGS} ${INCLUDE_LIB} ${FLAGS}  

build: 
	@${GCC} ${SRC_LIB} -o ${OUTPUT} -DNormal_Run ${INCLUDE_LIB} ${FLAGS}  

run:
	@${OUTPUT}