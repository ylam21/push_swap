# Program name
NAME := push_swap

# Compilation and flags
CC := cc
CFLAGS := -Wall -Wextra -Werror

# Commands
RM := rm -rf

# Directories
SOURCE_DIR = ./
OBJECT_DIR = objects

# File names
SOURCE_FILES = main.c

# Sources
SOURCES = $(addprefix $(SOURCE_DIR)/, $(SOURCE_FILES))

# Objects
OBJECT_FILES = $(patsubst $(SOURCE_DIR)/%.c, $(OBJECT_DIR)/%.o, $(SOURCES))

all: $(NAME)

$(NAME): $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) -o $(NAME)

# Create object files
$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECT_DIR):
	mkdir -p $(OBJECT_DIR)

clean:
	$(RM) $(OBJECT_FILES) $(OBJECT_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY = NAME all clean fclean
