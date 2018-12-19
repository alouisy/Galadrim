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
	@gcc $(CFLAGS) -c $(SRCS) $(INCLUDES)
	@gcc -o3 $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(LIBS)
	@echo "\"agar-ai\" has been succefully created !"

clean:
	@/bin/rm -f $(OBJS)
	@echo "AGAR-AI Object files deleted."

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "AGAR-AI Executable deleted."

re: fclean all

.PHONY: clean
