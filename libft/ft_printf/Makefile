NAME = libftprintf.a

CC = cc

SRCS = ./ft_printf.c ./ft_printf_function.c

INCLUDES = ft_printf.h

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wall

all : $(NAME)

$(NAME) : $(OBJ)
		ar -rc $(NAME) $(OBJ)

.c.o :
		$(CC) $(CFLAGS) -c -I $(INCLUDES) $< -o $@

clean :
		rm -rf $(OBJ)

fclean : clean
		rm -rf $(NAME)

re :
		make fclean all

.PHONY: clean fclean all re