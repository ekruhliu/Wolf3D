# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/11 16:17:09 by ekruhliu          #+#    #+#              #
#    Updated: 2018/04/11 16:17:10 by ekruhliu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wold3d

FLAGS = -c -Wall -Wextra -Werror -O3

SDL = -rpath @loader_path/libSDL/ -I libSDL/SDL2.framework/Headers -I libSDL/SDL2_image.framework/Headers -lm -framework SDL2 -framework SDL2_image -F ./libSDL

HEADER = includes/wolf.h

LIBFT = libft/libft.a

SRCS = ./srcs/cleaner.c ./srcs/create_textures.c ./srcs/draw_textures.c ./srcs/initialization.c ./srcs/moves.c \
./srcs/ray_casting.c ./srcs/read_map.c ./srcs/time_and_speed.c ./srcs/usage.c ./srcs/keys.c ./srcs/main.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@ make -C libft/
		@ gcc -o $(NAME) $(OBJ) $(LIBFT) $(SDL)

%.o: %.c $(HEADER)
	@ gcc $(FLAGS) -o  $@ $<

clean:
		@ /bin/rm -f $(OBJ)
		@ make -C libft/ clean
		@ echo "\033[1m\033[31mAll the object files have been deleted.\033[0m"

fclean: clean
		@ /bin/rm -f $(NAME)
		@ make -C libft/ fclean
		@ echo "\033[1m\033[31m$(NAME) has been deleted.\033[0m"

re: fclean all
