NAME	= miniRT

INCL	= includes/

SRCDIR	= srcs/

LIB		= lib/

FILES	=	a_main.c \
			b_check_args_errors.c \
			c_get_next_line.c \
			d_init_scene.c \
			e_parse_scene.c \
			f_parse_enviroment.c \
			g_parse_objects.c \
			h_parsing_utils.c \
			i_mlx_hooks.c \
			j_render.c \
			k_camera.c \
			l_find_closest_objects.c \
			m_color_light_shades.c \
			n_sphere.c \
			o_plane.c \
			p_triangle.c \
			q_square.c \
			r_cylinder.c \
			t_math_utils.c \
			u_color_utils.c \
			v_vect_utils.c \
			w_vector_utils2.c \
			x_save_bmp.c \
			y_error_management.c \
			z_textures_bonus.c

SRCS	= $(addprefix $(SRCDIR), $(FILES))

OBJS	= ${SRCS:.c=.o}

CC		= gcc -g

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -I $(INCL)

FLAGS = -L $(LIB)libft -lft

MACOS_LABEL = -D MACOS

LINUX_LABEL = -D LINUX

MACOS_FLAGS	= -L $(LIB)minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit 

LINUX_FLAGS = -L $(LIB)minilibx-linux -lmlx -lm -lX11 -lXext

UNAME := $(shell uname)

ifeq ($(UNAME),Darwin)
	CFLAGS += $(MACOS_LABEL)
	FLAGS += $(MACOS_FLAGS)
endif
ifeq ($(UNAME),Linux)
	CFLAGS += $(LINUX_LABEL)
	FLAGS += $(LINUX_FLAGS)
endif

${NAME}:	${OBJS} $(INCL)
			make -C $(LIB)libft
			${CC} ${CFLAGS} $(OBJS) $(FLAGS) -o ${NAME}

PHONY:		all clean fclean re

all:		${NAME}

clean:
			make clean -C $(LIB)libft
			${RM} ${OBJS}

fclean:		clean
			make fclean -C $(LIB)libft
			${RM} ${NAME}

re:			fclean all
