NAME = so_long.a
CFLAGS = -Wall -Wextra -Werror
CC = cc

SRCS = MND/fun_mnd1.c MND/fun_mnd2.c MND/fun_mnd3.c MND/fun_mnd4.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR =  LIBFT
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME) clean
	clear

$(NAME): $(OBJS) $(LIBFT)
	ar r $@ $^

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
	clear && gcc main.c -lmlx -framework OpenGL -framework AppKit LIBFT/libft.a so_long.a && ./a.out && rm -rf a.out 

.PHONY: all clean fclean