# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Iheader

# Output Executable Name
OUT = travel_agency

# Directories
AUTH_DIR = auth
FUNCTIONS_DIR = functions
MAIN_DIR = main

# Source Files
MAIN_SRC = $(MAIN_DIR)/main.c
AUTH_SRCS = $(wildcard $(AUTH_DIR)/*.c)
FUNCTIONS_SRCS = $(wildcard $(FUNCTIONS_DIR)/*.c)

# Build Rules
all: $(OUT)

$(OUT): $(MAIN_SRC)
	$(CC) $(CFLAGS) $(MAIN_SRC) $(AUTH_SRCS) $(FUNCTIONS_SRCS) -o $(OUT)

clean:
	rm -f $(OUT)

# Convenience target
run: all
	./$(OUT)
