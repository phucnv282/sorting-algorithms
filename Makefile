CC = g++
CFLAGS = -std=c++14 -Wall

# header files
INCL = $(wildcard *.h)
# source files
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

main: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o main

run: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o main & main

$(OBJ): $(INCL)

clean:
	del /f main $(OBJ)

