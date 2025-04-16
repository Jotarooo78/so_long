NAME = libft.a

CC = cc

SRCS = ./ft_atoi.c ./ft_bzero.c ./ft_calloc.c ./ft_isalnum.c ./ft_isalpha.c ./ft_isascii.c ./ft_isdigit.c \
		./ft_isprint.c ./ft_itoa.c ./ft_memchr.c ./ft_memcmp.c ./ft_memcpy.c ./ft_memmove.c ./ft_memset.c \
		./ft_putchar_fd.c ./ft_putendl_fd.c ./ft_putnbr_fd.c ./ft_putstr_fd.c ./ft_split.c ./ft_strchr.c \
		./ft_strdup.c ./ft_striteri.c ./ft_strjoin.c ./ft_strlcat.c ./ft_strlcpy.c ./ft_strlen.c ./ft_strmapi.c\
		./ft_strncmp.c ./ft_strnstr.c ./ft_strrchr.c ./ft_strtrim.c ./ft_substr.c ./ft_tolower.c ./ft_toupper.c \
		./ft_printf.c ./ft_printf_function.c ./get_next_line.c ./get_next_line_utils.c

BONUS = ./ft_lstadd_back_bonus.c ./ft_lstadd_front_bonus.c ./ft_lstclear_bonus.c ./ft_lstdelone_bonus.c \
		./ft_lstiter_bonus.c ./ft_lstlast_bonus.c ./ft_lstmap_bonus.c ./ft_lstnew_bonus.c ./ft_lstsize_bonus.c

INCLUDES = -I.

ifdef BONUS_FLAG
    SRCS += $(BONUS)
endif

ALL_SRCS = $(SRCS)

OBJ = $(SRCS:.c=.o)
ALL_OBJ = $(OBJ)

OBJ_BONUS = $(BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(ALL_OBJ)
	ar -rc $(NAME) $(ALL_OBJ)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus:
	$(MAKE) BONUS_FLAG=1

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: bonus clean fclean all re