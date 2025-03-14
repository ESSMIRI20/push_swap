CC = cc
CFLAGS = -I . -Wall -Wextra -Werror

NAME = push_swap
BONUS_NAME = checker

FILES = push_swap.c utils_functions.c push_swap_utils.c input_value.c files/sa.c\
		files/sb.c files/ss.c files/pa.c files/pb.c files/ra.c files/rb.c files/rr.c\
		files/rra.c files/rrb.c files/rrr.c push_to_b.c push_to_a.c

bonus_files = bonus/push_swap_bonus.c  bonus/utils_functions_bonus.c  bonus/push_swap_utils_bonus.c bonus/input_value_bonus.c\
		bonus/files_bonus/sa_bonus.c  bonus/files_bonus/sb_bonus.c  bonus/files_bonus/ss_bonus.c  bonus/files_bonus/pa_bonus.c\
		bonus/files_bonus/pb_bonus.c  bonus/files_bonus/ra_bonus.c  bonus/files_bonus/rb_bonus.c  bonus/files_bonus/rr_bonus.c\
		bonus/files_bonus/rra_bonus.c  bonus/files_bonus/rrb_bonus.c bonus/files_bonus/rrr_bonus.c\
		bonus/get_next_line/get_next_line.c bonus/get_next_line/get_next_line_utils.c

OB = $(FILES:.c=.o)
BONUS_OB = $(bonus_files:.c=.o)

all : $(NAME)
bonus : $(BONUS_NAME)

$(NAME) : $(OB)
	$(CC) $(CFLAGS) -o $(NAME) $(OB)

$(BONUS_NAME) : $(BONUS_OB)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OB)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OB) $(BONUS_OB)

fclean : clean
	rm -f $(NAME) $(BONUS_NAME)

re : fclean all

.PHONY : clean
