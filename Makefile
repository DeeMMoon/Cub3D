
CC	= gcc -g

SOURCES	= main.c parser/parse_file.c 

OBJECTS	= $(SOURCES:%.c=%.o)

HEADER	= headers

NAME 	= cub3D

LIB		= libft/libft.a

FLAGS 	=  -Werror -Wextra -Wall  -I $(HEADER)

.PHONY	: all clean fclean re

all	: $(NAME)

$(NAME)	: $(HEADER) $(OBJECTS)
	make -C libft
	make -C libft bonus
	$(CC) $(FLAGS) $(OBJECTS) $(LIB) -o $(NAME) 

%.o	: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean	:
	make -C libft clean
	rm -f $(OBJECTS)

fclean	: clean
	make -C libft fclean
	rm -f $(NAME)

re	: fclean all