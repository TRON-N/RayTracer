SRCS	=	add_object.c		\
			delete_object.c		\
			create_plane.c		\
			plane_intsct.c		\
			plane_info.c		\
			create_sphere.c		\
			sphere_intsct.c		\
			sphere_info.c		\
			create_cone.c		\
			cone_intsct.c		\
			cone_info.c		\
			point3d_on_ray.c	\
			create_light_distant.c	\
			create_light_point.c	\
			light_distant_info.c	\
			light_point_info.c	
	
OBJ	=	${SRCS:.c=.o} \
		../librt/vect3d_rev.o\
		../librt/vect3d_len.o\
		../librt/vect3d_div.o
	
NAME		=	libobj.a
CFLAGS		=	-I../ -I../librt -Wall -Werror -Wextra -c
HEAD		=	libobj.h

all: $(NAME)

$(NAME): $(SRCS) $(HEAD) $(LIBFT)
	clang $(CFLAGS) $(SRCS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

.PHONY: fclean

fclean: clean
	rm -rf $(NAME)
clean:
	rm -rf $(OBJ)

re:	fclean all
