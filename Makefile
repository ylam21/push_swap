# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaly <omaly@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/20 10:34:09 by omaly             #+#    #+#              #
#    Updated: 2025/09/16 15:19:59 by omaly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME := push_swap

# Compilation and flags
CC := cc
CFLAGS := -Wall -Wextra -Werror

# Commands
RM := rm -rf

# Directories
SOURCE_DIR = src
OBJECT_DIR = obj

# Source files
SOURCE_FILES =	$(SOURCE_DIR)/push_swap.c \
				$(SOURCE_DIR)/validate.c \
				$(SOURCE_DIR)/sort.c \
				$(SOURCE_DIR)/init/init_ps.c \
				$(SOURCE_DIR)/init/parse.c \
				$(SOURCE_DIR)/init/normalization.c \
				$(SOURCE_DIR)/operations/push.c \
				$(SOURCE_DIR)/operations/reverse_rotate.c \
				$(SOURCE_DIR)/operations/rotate.c \
				$(SOURCE_DIR)/operations/swap.c \
				$(SOURCE_DIR)/utils/debug.c \
				$(SOURCE_DIR)/utils/print_error.c \
				$(SOURCE_DIR)/utils/free.c \
				$(SOURCE_DIR)/utils/lst_utils.c \
				$(SOURCE_DIR)/utils/math_utils.c \
				$(SOURCE_DIR)/utils/char_utils.c \
				$(SOURCE_DIR)/utils/stack_utils_1.c \
				$(SOURCE_DIR)/utils/stack_utils_2.c

# Object files
OBJECT_FILES := $(patsubst $(SOURCE_DIR)/%.c,$(OBJECT_DIR)/%.o,$(SOURCE_FILES))

all: $(NAME)

$(NAME): $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) -o $(NAME)

# Create object files
$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.c|$(OBJECT_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECT_DIR):
	mkdir -p $(OBJECT_DIR)
	mkdir -p $(OBJECT_DIR)/operations
	mkdir -p $(OBJECT_DIR)/init
	mkdir -p $(OBJECT_DIR)/utils

clean:
	$(RM) $(OBJECT_FILES) $(OBJECT_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY = NAME all clean fclean
