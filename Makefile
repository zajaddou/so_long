
NAME = so_long
BONUS_NAME = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit


SRCS = MND/render.c MND/algo.c MND/control.c MND/check.c MND/more.c \
	   MND/readfile.c MND/fillmap.c MND/start.c so_long.c

BONUS_SRCS = so_long_bonus.c BNS/render_bonus.c BNS/algo_bonus.c BNS/control_bonus.c \
			 BNS/more_bonus.c BNS/readfile_bonus.c BNS/fillmap_bonus.c \
			 BNS/check_bonus.c BNS/monsters_bonus.c BNS/start_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX) $(LIBFT)

bonus: $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME) $(MLX) $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

run : bonus
	clear && ./so_long_bonus "maps/bonus.ber"

.PHONY: all clean fclean re bonus
