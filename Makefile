CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

SRC = ft_printf.c ft_putnbr_base.c

LIBFTCS = ft_putchar_fd.c ft_putnbr_fd.c ft_strlen.c \
			ft_strchr.c ft_putstr_fd.c

LIBFTSRC = $(addprefix ./libft/, $(LIBFTCS))

OBJ = $(SRC:.c=.o) $(LIBFTCS:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(LIBFTSRC) $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
