NAME = so_long.a
CFLAGS = -Wall -Wextra -Werror
MLX= -lmlx -framework OpenGL -framework AppKit
CC = cc

SRCS = MND/render.c MND/algo.c MND/control.c MND/check.c MND/more.c MND/readfile.c MND/fillmap.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR =  LIBFT
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME) clean
	clear

$(NAME): $(OBJS) $(LIBFT)
	cc so_long.c $(FLAGS) $(OBJS) -o so_long $(MLX) LIBFT/libft.a 

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all clean

run: all
	clear && ./so_long && rm -rf so_long

.PHONY: all clean fclean