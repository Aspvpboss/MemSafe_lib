
GCC = gcc
#GCC = gcc

INCLUDE_LIB = -Ilib/include
SRC_LIB = lib/src/*.c


FLAGS = -Wall -Werror -Wpedantic -pedantic
OUTPUT = out.exe

DLL_FLAGS = -fPIC -shared  -Wl,--out-implib,libMemTrack.a
DLL_OUTPUT = libMemTrack.dll

default: build run


build_lib:
	@${GCC} ${SRC_LIB} -o ${DLL_OUTPUT} -DDLL_EXPORTS ${DLL_FLAGS} ${INCLUDE_LIB} ${FLAGS}  

build: 
	@${GCC} ${SRC_LIB} -o ${OUTPUT} -DSTATIC_LINK ${INCLUDE_LIB} ${FLAGS}  

run:
	@${OUTPUT}