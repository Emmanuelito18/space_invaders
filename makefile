main: src/main.cpp 
	g++ src/main.cpp src/bullet.cpp src/alien.cpp src/spaceship.cpp -lsfml-graphics -lsfml-window -lsfml-system -o space_invaders
# /usr/lib/libGL.so
