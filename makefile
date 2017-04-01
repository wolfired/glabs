build:
	gcc `pkg-config --cflags glew glfw3` -o bin/main src/main.c `pkg-config --libs glew glfw3`

run: build
	./bin/main
