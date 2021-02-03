CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = translate.a
OPTIONS = -L<opengl_path> -lmlx -framework OpenGL -framework AppKit
SOURCES =	srcs/cal_and_init.c\
			srcs/dda.c \
			srcs/deal_key.c \
			srcs/main_hook.c \
			srcs/map.c \
			srcs/buff.c \
			srcs/draw_buffer.c \
			srcs/texX.c \
			srcs/wallX.c \
			srcs/y_tex.c \
			srcs/load_img.c \
			srcs/main.c 
all: $(NAME)

$(NAME):
		$(CC) $(OPTIONS) $(SOURCES) -o $(NAME)

fclean: clean
		$(RM) $(NAME)
re: fclean all

.PHONY: clean fclean all re
