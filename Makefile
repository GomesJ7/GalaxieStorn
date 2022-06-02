NAME	=	Runner

SRC		=	source/main.c\
			source/draw.c\
			source/init.c\
			source/input.c\

OBJ		=	$(SRC:.c=.o)

RM = rm -f

CFLAGS +=	-I include
CFLAGS +=	-W -Werror -Wall -Wextra

LIBS	+=	-l SDL2	-l SDL2_image


$(NAME):	$(OBJ)
			$(CC) $(OBJ) $(LIBS) -o $(NAME)
all:		$(NAME)

clean:		
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean