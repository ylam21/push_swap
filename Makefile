# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaly <omaly@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/20 10:34:09 by omaly             #+#    #+#              #
#    Updated: 2025/09/16 17:33:36 by omaly            ###   ########.fr        #
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
				$(SOURCE_DIR)/init/ranking.c \
				$(SOURCE_DIR)/init/build_stack.c \
				$(SOURCE_DIR)/ops/push.c \
				$(SOURCE_DIR)/ops/reverse_rotate.c \
				$(SOURCE_DIR)/ops/rotate.c \
				$(SOURCE_DIR)/ops/swap.c \
				$(SOURCE_DIR)/utils/debug.c \
				$(SOURCE_DIR)/utils/error.c \
				$(SOURCE_DIR)/utils/free.c \
				$(SOURCE_DIR)/utils/lst_utils.c \
				$(SOURCE_DIR)/utils/char_utils.c \
				$(SOURCE_DIR)/utils/stack_utils.c

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
	mkdir -p $(OBJECT_DIR)/ops
	mkdir -p $(OBJECT_DIR)/init
	mkdir -p $(OBJECT_DIR)/utils

clean:
	$(RM) $(OBJECT_FILES) $(OBJECT_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY = NAME all clean fclean
