NAME = so_long

CC = cc

SRC = main.c
INCLUDES = includes/so_long.h

LIBX_DIR = libx
LIBX = $(LIBX_DIR)/libmlx.a

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wall -g3 -I $(LIBFT_DIR) $(LIBX_DIR) 

all: $(LIBFT) $(LIBX) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBX):
	$(MAKE) - C $(LIBX_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBX) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) $(LIBX_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) $(LIBX_DIR) fclean

re: fclean all

.PHONY: clean fclean all re