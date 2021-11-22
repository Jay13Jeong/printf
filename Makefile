NAME		= libftprintf.a
SRCS		= ./ft_printf.c ./ft_printf_util.c
OBJS		= $(SRCS:.c=.o)
RM			= rm -f
LIBC		= ar rc
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I .

$(NAME) : $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(OBJS)

re : fclean all
