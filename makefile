all:
	g++ main.cpp game.cpp shader.cpp texture.cpp resource_manager.cpp stb_image.cpp glad.c -lglfw -ldl -o main
