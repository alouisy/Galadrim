NAME = agar-ai

SRCS = main.c\
		parser.c\
		maths.c\
		solution.c

OBJS = $(SRCS:.c=.o)

LIBS = -L libft/ -lft

INCLUDES = -I. -I libft/includes/.

CFLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME):
	@make -C libft/
	@gcc $(CFLAGS) -c $(SRCS) $(INCLUDES)
	@gcc -o2 $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(LIBS)
	@echo "\"agar-ai\" has been succefully created !"

clean:
	@make -C libft/ clean
	@/bin/rm -f $(OBJS)
	@echo "AGAR-AI Object files deleted."

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)
	@echo "AGAR-AI Executable deleted."

re: fclean all

.PHONY: clean
