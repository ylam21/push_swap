# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaly <omaly@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/19 10:58:32 by omaly             #+#    #+#              #
#    Updated: 2025/09/19 11:43:19 by omaly            ###   ########.fr        #
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
SRC_DIR = ./
BONUS_DIR = ./
OBJ_DIR = objs

SRC = ft_isalpha \
	ft_memset \
	ft_bzero \
	ft_memcpy \
	ft_memmove \
	ft_memchr \
	ft_memcmp \
	ft_strlen \
	ft_isdigit \
	ft_isalnum \
	ft_isascii \
	ft_isprint \
	ft_strlcpy \
	ft_strlcat \
	ft_toupper \
	ft_tolower \
	ft_strchr \
	ft_strrchr \
	ft_strncmp \
	ft_strnstr \
	ft_atoi \
	ft_itoa \
	ft_calloc \
	ft_strdup \
	ft_split \
	ft_substr \
	ft_strjoin \
	ft_strtrim \
	ft_strmapi \
	ft_striteri \
	ft_putchar_fd \
	ft_putstr_fd \
	ft_putendl_fd \
	ft_putnbr_fd

BONUS_SRC = ft_lstnew_bonus \
	ft_lstadd_front_bonus \
	ft_lstsize_bonus \
	ft_lstlast_bonus \
	ft_lstadd_back_bonus \
	ft_lstdelone_bonus \
	ft_lstclear_bonus \
	ft_lstiter_bonus \
	ft_lstmap_bonus

SRCS = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC)))
BONUS_SRCS = $(addprefix $(BONUS_DIR)/, $(addsuffix .c, $(BONUS_SRC)))
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS = $(BONUS_SRCS:$(BONUS_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I . -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
