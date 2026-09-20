NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I.

SRCS        = push_swap.c \
              src/stack/stack.c \
              src/stack/stack_utils.c \
              src/operations/swap.c \
              src/operations/push.c \
              src/operations/rotate.c \
              src/operations/reverse_rotate.c \
              src/utils/utils.c \
              src/algorithms/simple.c \
              src/algorithms/medium.c \
              src/algorithms/complex.c \
              src/algorithms/adaptive.c \
              src/disorder/disorder.c \
              src/parser/parser.c \
              src/benchmark/benchmark.c

OBJS        = $(SRCS:.c=.o)

HEADER      = push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re