CC = g++
CFLAGS = -g -fsanitize=address -fsanitize=undefined -std=c++20
OBJS = model.o cursor.o main.o character.o
RAYLIB = $(shell pkg-config --cflags --libs raylib)
IRAYLIB = $(shell pkg-config --cflags raylib)

tedit: model.o cursor.o main.o character.o
	$(CC) $(CFLAGS) $(OBJS) $(RAYLIB) -o tedit

model.o: src/model.cpp src/include/model.h
	$(CC) $(CFLAGS) -c src/model.cpp $(IRAYLIB)

cursor.o: src/cursor.cpp src/include/cursor.h
	$(CC) $(CFLAGS) -c src/cursor.cpp $(IRAYLIB)

character.o: src/character.cpp src/include/character.h
	$(CC) $(CFLAGS) -c src/character.cpp $(IRAYLIB)

main.o: src/main.cpp
	$(CC) $(CFLAGS) -c src/main.cpp $(IRAYLIB)

clean:
	rm -rf *.o ./tedit