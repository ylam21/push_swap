# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaly <omaly@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/20 10:34:09 by omaly             #+#    #+#              #
#    Updated: 2025/09/17 21:27:59 by omaly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME := push_swap
NAME_LIBFT := libft.a

# Compilation and flags
CC := cc
CFLAGS := -Wall -Wextra -Werror

# Commands
RM := rm -rf

# Directories
SOURCE_DIR = src
OBJECT_DIR = obj
LIBFT_DIR = libft

# Source files
SOURCE_FILES =	$(SOURCE_DIR)/push_swap.c \
				$(SOURCE_DIR)/validate_args.c \
				$(SOURCE_DIR)/sort.c \
				$(SOURCE_DIR)/init/init_ps.c \
				$(SOURCE_DIR)/init/ranking.c \
				$(SOURCE_DIR)/init/strv_to_arr.c \
				$(SOURCE_DIR)/init/arr_to_list.c \
				$(SOURCE_DIR)/ops/push.c \
				$(SOURCE_DIR)/ops/reverse_rotate.c \
				$(SOURCE_DIR)/ops/rotate.c \
				$(SOURCE_DIR)/ops/swap.c \
				$(SOURCE_DIR)/utils/debug.c \
				$(SOURCE_DIR)/utils/error.c \
				$(SOURCE_DIR)/utils/free.c \
				$(SOURCE_DIR)/utils/char_utils.c \
				$(SOURCE_DIR)/utils/stack_utils.c

# Object files
OBJECT_FILES := $(patsubst $(SOURCE_DIR)/%.c,$(OBJECT_DIR)/%.o,$(SOURCE_FILES))

all: $(NAME)

$(NAME): $(OBJECT_FILES) $(NAME_LIBFT)
	$(CC) $(CFLAGS) $(OBJECT_FILES) -L$(LIBFT_DIR) -lft -o $(NAME)

$(NAME_LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

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
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY = NAME all clean fclean
