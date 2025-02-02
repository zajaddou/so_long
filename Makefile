
NAME = so_long
BONUS_NAME = so_long_bonus

CC = cc
MLX = -lmlx -framework OpenGL -framework AppKit
CFLAGS = -Wall -Wextra -Werror

SRCS = so_long.c MND/render.c MND/algo.c MND/control.c MND/check.c MND/more.c \
	   MND/readfile.c MND/fillmap.c MND/start.c 

BONUS_SRCS = so_long_bonus.c BNS/render_bonus.c BNS/algo_bonus.c BNS/control_bonus.c \
			 BNS/more_bonus.c BNS/readfile_bonus.c BNS/fillmap_bonus.c \
			 BNS/check_bonus.c BNS/monsters_bonus.c BNS/animation_bonus.c BNS/start_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

%.o: %.c so_long.h LIBFT/libft.h 
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX) $(LIBFT)

bonus: $(BONUS_OBJS) $(LIBFT) so_long_bonus.h
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME) $(MLX) $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean
