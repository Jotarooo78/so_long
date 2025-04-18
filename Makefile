NAME = so_long

CC = cc

SRC = src/main.c src/errors.c src/parcing.c src/check_map.c

INCLUDES = includes/so_long.h

LIBX_DIR = libx
LIBX = $(LIBX_DIR)/libmlx.a

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g3 -I$(LIBFT_DIR) -I$(LIBX_DIR)

LDFLAGS = -L$(LIBX_DIR) -lmlx -lX11 -lXext -lm

all: $(LIBFT) $(LIBX) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBX):
	$(MAKE) -C $(LIBX_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LDFLAGS) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(LIBX_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean all re