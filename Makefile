SRCS = get_next_line.c get_next_line_utils.c

HEADER = get_next_line.h

NAME = get_next_line

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc $(CFLAGS) -o $(SRCS)

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
