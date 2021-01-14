
NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror -c
SRCS =		ft_printf.c\
			parse_chars_to_print.c\
			parser.c\
			print_chars.c\
			print_int_digits.c\
			print_neg_ints.c\
			print_p_w_dig.c\
			print_pointers.c\
			print_strings.c\
			print_u_digits.c\
			utils_first.c\
			utils_second.c
OBJS = $(SRCS:.c=.o)
LIB = ar rc
# test: fclean
# 		@echo $(SRC)

all:	$(NAME)

$(NAME): $(OBJS)
		$(CC) $(FLAGS) $(SRCS) printfhead.h
		$(LIB) $(NAME) $(OBJS)
		ranlib $(NAME)
clean:
		rm -f $(OBJS) printfhead.h.gch a.out

fclean:		clean
		rm -f $(NAME) 

re:		fclean all

bonus: ${BONUSOBJS}	${OBJS}
		$(CC) $(FLAGS) $(BONUSSRC) printfhead.h
		$(LIB) $(NAME) $(OBJS) $(BONUSOBJS)
		ranlib $(NAME)

.PHONY: all clean fclean re bonus

