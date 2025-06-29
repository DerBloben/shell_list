cc = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = shell

SRCS = main.c task.c utilis.c
OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME):$(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
