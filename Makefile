all:
	gcc -Wall -Wextra -std=c11 main.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o ./build/doppler-simulator
