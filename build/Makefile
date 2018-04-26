CC=g++
CV=-std=c++17
CF=-lm -lGL -lGLEW -lglfw

daemon: ../sources/daemon/*.cpp
	clear
	@read -p "Name of the exe : " name;\
	$(CC) ../sources/daemon/*.cpp -o $$name $(CV) $(CF)
