
NAME = so_long
BONUS_NAME = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit


SRCS = MND/render.c MND/algo.c MND/control.c MND/check.c MND/more.c \
	   MND/readfile.c MND/fillmap.c so_long.c

BONUS_SRCS = BNS/render_bonus.c BNS/algo_bonus.c BNS/control_bonus.c \
			 BNS/more_bonus.c so_long_bonus.c \
			 MND/readfile.c MND/fillmap.c MND/check.c

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

.PHONY: all clean fclean re bonus
