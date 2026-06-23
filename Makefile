all: | build
	gcc -Wall -Wextra -std=c11 -O2 main.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o ./build/doppler-simulator

build:
	mkdir -p build

install:
	./install.sh

windows: | build
	gcc -Wall -Wextra -std=c11 -O2 main.c -lraylib -lopengl32 -lgdi32 -lwinmm -o ./build/doppler-simulator.exe

run:
	./build/doppler-simulator

Wrun:
	./build/doppler-simulator.exe
