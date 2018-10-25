#NAME	=	ft_printf
NAME	=	agordiyc.filler

SRCS	= 	main.c \
			filler_helper.c \
			filler_helper2.c \
			solver.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

%.o : %.c
	gcc -Wall -Wextra -c $< -o $@

$(NAME): libft $(OBJS)
	gcc -o $(NAME) $(OBJS) libft/libft.a

.PHONY: libft
libft:
	make -C libft

clean:
	rm -f *.o
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all
