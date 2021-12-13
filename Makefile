NAME	=	libftprintf.a

SRCS	=	ft_printf.c\
			ft_printf_conv_char_null_c_s.c\
			ft_printf_conv_i_d.c\
			ft_printf_conv_p_x.c\
			ft_printf_conv_xx.c\
			ft_printf_conv_u.c

HEADER	=	ft_printf.h
OBJ		=	$(patsubst %.c, %.o, $(SRCS))

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME) : 	$(OBJ) $(HEADER)
	ar rcs $(NAME) $?

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJ)

fclean	: clean
	@$(RM) $(NAME)

re		:	fclean all