CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
SRC_DIR = src
BIN_DIR = bin
OBJ_DIR = obj
TARGET = $(BIN_DIR)/bbs

PREFIX = /usr/local
BINDIR = $(PREFIX)/bin
INCLUDEDIR = $(PREFIX)/include/bbsgen

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/bbs.c $(SRC_DIR)/sequence.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

install: $(TARGET)
	@echo "Installing to $(BINDIR)..."
	@mkdir -p $(BINDIR)
	@mkdir -p $(INCLUDEDIR)
	cp $(TARGET) $(BINDIR)
	cp include/*.h $(INCLUDEDIR)
	@echo "Installation complete."

uninstall:
	@echo "Removing installed files..."
	rm -f $(BINDIR)/bbs
	rm -rf $(INCLUDEDIR)
	@echo "Uninstallation complete."

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean install uninstall
