
CC	= gcc -g

SOURCES	= main.c \
			parser/parse_file.c parser/parse_texture.c parser/parse_texture_utils.c parser/parse_map.c\
			get_next_line/get_next_line.c  get_next_line/get_next_line_utils.c\
			util/not_empty_gnl.c util/map_util.c
		

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