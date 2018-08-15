SRCS	=	point3d_mult_matrix4_4.c	\
			rot_x_matrix4_4.c			\
			rot_y_matrix4_4.c			\
			rot_z_matrix4_4.c			\
			vect3d_new.c				\
			vect3d_normalize.c			\
			vect3d_sub.c				\
			vect3d_div.c				\
			vect3d_len.c				\
			vect3d_rev.c				\
<<<<<<< HEAD
			vect3d_mult_const.c			\
			vect3d_reflect.c			\
=======
			vect3d_scale.c				\
>>>>>>> master
			product_dot.c				\
			product_cross.c				\
			ft_min.c					\
			ft_max.c					\
			ft_clamp.c					\
	
OBJ	=	${SRCS:.c=.o}
	
NAME	=	librt.a
CFLAGS	=	-Wall -Werror -Wextra -c
HEAD	=	librt.h

all: $(NAME)

$(NAME): $(SRCS) $(HEAD)
	clang $(CFLAGS) $(SRCS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

.PHONY: fclean

fclean: clean
	rm -rf $(NAME)
clean:
	rm -rf $(OBJ)
re: fclean all
	
