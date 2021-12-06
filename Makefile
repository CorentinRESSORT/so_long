NAME = so_long

SRCS = so_long.c \
		sources/file_pars.c \
		sources/file_control.c

CC = gcc

FLAGS = -Wextra -Wall -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(FLAGS) $(INCLUDES) $(SRCS)

all : $(NAME)

clean :
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(NAME)
re : fclean all