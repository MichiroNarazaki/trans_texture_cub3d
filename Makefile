CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = translate.a
OPTIONS = -L../cub_git/opengl -lmlx -framework OpenGL -framework AppKit
SOURCES =	tmp/cal_and_init.c\
			tmp/dda.c \
			tmp/deal_key.c \
			srcs/main_hook.c \
			srcs/main.c \
			srcs/map.c \
			srcs/buff.c \
			srcs/draw_buffer.c \
			srcs/texX.c \
			srcs/wallX.c \
			srcs/y_tex.c \
			srcs/load_img.c
all: $(NAME)

$(NAME):
		$(CC) $(OPTIONS) $(SOURCES) -o $(NAME)

fclean: clean
		$(RM) $(NAME)
re: fclean all

.PHONY: clean fclean all re
