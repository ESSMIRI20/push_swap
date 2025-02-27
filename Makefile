CC = cc
CFLAGS = -g -Wall -Wextra -Werror

NAME = push_swap

FILES = push_swap.c enter_value.c utils_functions.c sa.c sb.c ss.c pa.c pb.c ra.c rb.c rr.c rra.c rrb.c rrr.c
OB = push_swap.o input_value.o utils_functions.o sa.o sb.o ss.o pa.o pb.o ra.o rb.o rr.o rra.o rrb.o rrr.o

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