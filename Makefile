NAME = push_swap
CC = cc

SRCS = \
	push_swap.c \
	sort.c \
	sort_sol2.c \
	handle_input.c \
	arrays/ops_1.c \
	arrays/ops_2.c \
	arrays/ps_arrays.c \
	libps/libps.c \
	libps/ps_split.c \

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME);

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re