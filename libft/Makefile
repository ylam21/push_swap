# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaly <omaly@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/17 20:52:03 by omaly             #+#    #+#              #
#    Updated: 2025/09/17 21:05:59 by omaly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME := libft.a

# Compilation and flags
CC := cc
CFLAGS := -Wall -Wextra -Werror

# Commands
RM := rm -rf

# Directories
SOURCE_DIR = src
OBJECT_DIR = obj

# Source files
SOURCE_FILES =	$(SOURCE_DIR)/ft_split.c \
				$(SOURCE_DIR)/ft_strlcpy.c \
				$(SOURCE_DIR)/ft_strlen.c \
				$(SOURCE_DIR)/ft_isdigit.c

# Object files
OBJECT_FILES := $(patsubst $(SOURCE_DIR)/%.c,$(OBJECT_DIR)/%.o,$(SOURCE_FILES))

all: $(NAME)

$(NAME): $(OBJECT_FILES)
	ar rcs $(NAME) $(OBJECT_FILES)

# Create object files
$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.c|$(OBJECT_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECT_DIR):
	mkdir -p $(OBJECT_DIR)

clean:
	$(RM) $(OBJECT_FILES) $(OBJECT_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY = NAME all clean fclean
