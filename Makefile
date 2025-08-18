# Program name
NAME := push_swap

# Compilation and flags
CC := cc
CFLAGS := -Wall -Wextra -Werror

# Commands
RM := rm -rf

# Directories
SOURCE_DIR = ./
OBJECT_DIR = obj

# Source files
SOURCE_FILES =	$(SOURCE_DIR)/push_swap.c \
				$(SOURCE_DIR)/validate_args.c \
				$(SOURCE_DIR)/parse.c

# Object files
OBJECT_FILES =	$(OBJECT_DIR)/push_swap.o \
				$(OBJECT_DIR)/validate_args.o \
				$(OBJECT_DIR)/parse.o

all: $(NAME)

$(NAME): $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) -o $(NAME)

# Create object files
$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.c | $(OBJECT_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECT_DIR):
	mkdir -p $(OBJECT_DIR)

clean:
	$(RM) $(OBJECT_FILES) $(OBJECT_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY = NAME all clean fclean
