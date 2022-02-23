NAME	= libft.a

LIBFT_F	=	ft_calloc.c \
			ft_strlen.c \
			ft_lstclear.c \
			ft_lstdelone.c \
		  	ft_strcat.c \
		  	ft_strncmp.c \
		  	ft_strchr.c \
		  	ft_strrchr.c \
		  	ft_itoa.c \
			ft_lstclear.c \
			ft_lstnew.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_memset.c \
			ft_bzero.c \
			ft_strjoin.c \

SRCS	=  $(addprefix srcs/libft/, $(LIBFT_F))

OBJS	= ${SRCS:.c=.o}

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -I includes 

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
