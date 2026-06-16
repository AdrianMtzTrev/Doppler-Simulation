all: | build
	gcc -Wall -Wextra -std=c11 -O2 main.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o ./build/doppler-simulator

build:
	mkdir -p build

install:
	./install.sh
