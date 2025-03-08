CC = cc
CFLAGS = -I . -Wall -Wextra -Werror

NAME = push_swap

FILES = push_swap.c utils_functions.c push_swap_utils.c input_value.c test/sa.c test/sb.c test/ss.c test/pa.c test/pb.c test/ra.c test/rb.c test/rr.c test/rra.c test/rrb.c test/rrr.c push_to_b.c push_to_a.c 
OB = $(FILES:.c=.o)

all : $(NAME)

$(NAME) : $(OB)
	$(CC) $(CFLAGS) -o $(NAME) $(OB)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OB)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
