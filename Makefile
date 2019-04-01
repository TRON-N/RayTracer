CORE_FUNCTIONS		:=	./core_functions/find_colour.c		\
				./core_functions/start_primary_rays.c	\
				./core_functions/trace_ray.c		\
				./core_functions/main.c			\
				./core_functions/init_buff.c		\
				./core_functions/init_thread_info.c	\
				./core_functions/sdl_render.c		\
				./core_functions/show_render_progress.c	\
				./core_functions/show_progress_bar.c	\
				./core_functions/init_scene_info.c\
				./core_functions/dither_buff.c
			
COLOUR_SYSTEM		:=	./colour_system/col_diffuse.c		\
				./colour_system/col_specular.c		\
				./colour_system/col_is_shadow.c		\
				./colour_system/col_mix.c		\
				./colour_system/col_split_int.c		\
				./colour_system/col_to_int.c		\
				./colour_system/col_refract.c		\
				./colour_system/col_fresnel.c		\
				./colour_system/col_sdl_fill_surface.c	\
				./colour_system/col_apply_aa_blend.c	\
				./colour_system/col_point_bias_shift.c	\
				./colour_system/col_find_diffuse_and_specular.c\
				./colour_system/col_set_zero.c		\
				./colour_system/col_shape_c_zero.c	\
				./colour_system/col_find_transp_and_reflect.c\
				./colour_system/col_mult_const.c	\
				./colour_system/col_mult.c		\
				./colour_system/col_add.c		\
				./colour_system/col_limit.c		\
				./colour_system/col_rev_norm_and_ndoti.c\
				./colour_system/col_look_to_tex.c	\
				./colour_system/col_tex_to_look.c	\
				./colour_system/col_sphere_texture.c	\
				./colour_system/col_r_mask.c		\
				./colour_system/col_g_mask.c		\
				./colour_system/col_b_mask.c		\
				./colour_system/col_apply_bandlimit.c

LIBRT			:=	./librt/ft_clamp.c			\
				./librt/ft_max.c			\
				./librt/ft_min.c			\
				./librt/point3d_mult_matrix4_4.c	\
				./librt/product_cross.c			\
				./librt/product_dot.c			\
				./librt/rot_x_matrix4_4.c		\
				./librt/rot_y_matrix4_4.c		\
				./librt/rot_z_matrix4_4.c		\
				./librt/trans_matrix4_4.c		\
				./librt/ident_matrix4_4.c		\
				./librt/vect3d_add.c			\
				./librt/vect3d_div_const.c		\
				./librt/vect3d_len.c			\
				./librt/vect3d_mult_const.c		\
				./librt/vect3d_new.c			\
				./librt/vect3d_normalize.c		\
				./librt/vect3d_reflect.c		\
				./librt/vect3d_rev.c			\
				./librt/vect3d_sub.c			\
				./librt/vect3d_create.c			\
				./librt/point3d_create.c		\
				./librt/matrix4_4_mult_matrix.c		\
				./librt/vect3d_mult_matrix4_4.c		\
				./librt/point3d_add_vect.c

LIBOBJ			:=	./libobj/cone_info.c			\
				./libobj/cone_intsct.c			\
				./libobj/create_cone.c			\
				./libobj/create_light_distant.c		\
				./libobj/create_light_point.c		\
				./libobj/create_plane.c			\
				./libobj/create_sphere.c		\
				./libobj/delete_object.c		\
				./libobj/light_distant_info.c		\
				./libobj/light_point_info.c		\
				./libobj/plane_info.c			\
				./libobj/plane_intsct.c			\
				./libobj/point3d_on_ray.c		\
				./libobj/sphere_intsct.c		\
				./libobj/sphere_info.c			\
				./libobj/cylinder_intsct.c		\
				./libobj/cylinder_info.c		\
				./libobj/create_cylinder.c		\
				./libobj/create_cube.c			\
				./libobj/cube_intsct.c			\
				./libobj/cube_info.c

READ_FILE		:= ./file_reading/read_file.c			\
				./file_reading/read_shape.c		\
				./file_reading/read_create_shape.c	\
				./file_reading/read_str_t_pnt3d.c	\
				./file_reading/read_options.c		\
				./file_reading/option_checks.c		\
				./file_reading/option_checks_two.c	\
				./file_reading/read_c_obj_t_wrld_m.c	\
				./file_reading/read_look.c				\
				./file_reading/look_checks.c			\
				./file_reading/look_checks_two.c		\
				./file_reading/look_checks_three.c		\
				./file_reading/read_str_t_colour.c		\
				./file_reading/read_light.c				\
				./file_reading/read_create_light.c		\

SRCS			:=	$(CORE_FUNCTIONS)			\
				$(COLOUR_SYSTEM)			\
				$(LIBRT)				\
				$(LIBOBJ)				\
				$(READ_FILE)

OBJ				:=	${SRCS:.c=.o}

SDLFLAGS		:=	-L C:/SDL2/lib/x86 -lSDL2main -lSDL2
HEAD_FLAGS		:=	-I./librt -I./libobj -I./core_functions	\
				-I./libft/includes -I./colour_system\
				-I./file_reading \
				-I C:/SDL2/include

LIBFT_FLAGS		:=	-L./libft -lft
LIBFT			:=	libft/libft.a
LIBFT_DEP		:=	libft/includes/libft.h libft/Makefile

OBJFLAGS		:= $(HEAD_FLAGS) $(SDLFLAGS) $(LIBFT_FLAGS)  

CFLAGS			:=	$(HEAD_FLAGS)
NAME			:=	RT 

CC				= C:\MinGW\bin\gcc -m32

all: $(NAME)

%.o: %.c Makefile
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(OBJFLAGS) -o $(NAME)

$(LIBFT): $(LIBFT_DEP)
	make -C ./libft

.PHONY: fclean

fclean: clean
	rm -rf $(NAME)
	# make -C ./libft fclean

clean:
	rm -rf $(OBJ)
	# make -C ./libft clean

re: fclean all
