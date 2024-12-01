NAME = libftprintf.a
SRC = ft_printf.c helpers.c
FLAGS = -Wall -Wextra -Werror
CC = cc
OBJ = $(SRC:%.c=%.o)
AR = ar rc
RM = rm -f

all: $(NAME)

$(NAME) : $(OBJ)
	$(AR) $@ $^

%.o: %.c ft_printf.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean