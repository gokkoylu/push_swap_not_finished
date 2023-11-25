
CC = gcc
CFLAGS = -Wall -Werror -Wextra


NAME = push_swap


SRCS = checks.c operations1.c operations2.c operations3.c push_swap.c sort.c utils.c
OBJS = $(SRCS:.c=.o)


HEADERS = operations.h sort.h utils.h

all: $(NAME)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)


%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS)


fclean: clean
	rm -f $(NAME)


re: fclean all


.PHONY: all clean fclean re