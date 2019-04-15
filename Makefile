CC = clang++
CFLAGS = -Wall -g
DEBUGFLAGS = -Werror -Wall -g

SRC = src/*.cpp
OBJ = build/*.o
TARGET = bin/mips

all: $(TARGET)

$(OBJ): $(SRC)
	@echo "Compiling..."
	$(CC) -c $(SRC)
	mv *.o build/

$(TARGET): $(OBJ)
	@echo "Linking..."
	$(CC) $(OBJ) -o $(TARGET)

clean:
	@echo "Cleaning..."
	rm -r build/*.o
	rm $(TARGET)

.PHONY: clean
