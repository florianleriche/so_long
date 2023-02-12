SRCS = srcs/so_long.c \
	   srcs/read_map.c \
	   srcs/verif_map.c \
	   srcs/render.c \
	   srcs/player_init.c \
	   srcs/hooks.c \
	   srcs/move_player.c \
	   srcs/img_init.c \
	   srcs/event.c \
	   srcs/change_map.c \
	   srcs/pnj.c \
	   srcs/anim_collectible.c \
	   srcs/anim_water.c

OBJS = ${SRCS:.c=.o}

FLAGS = -Wall -Wextra -Werror
FLAGS_MLX = -framework AppKit -framework OpenGL -Lmlx -Imlx
NAME = so_long

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

.c.o :
	@gcc ${FLAGS} -I so_long.h -c $< -o ${<:.c=.o}

all: ${OBJS}
	@make -C ./libft/
	@make -C ./ft_printf/
	@make -C ./mlx/
	@mv ./libft/libft.a ./libft.a
	@mv ./mlx/libmlx.a ./libmlx.a
	@mv ./ft_printf/libftprintf.a ./libftprintf.a
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc ${FLAGS} ${FLAGS_MLX} -o ${NAME} libft.a libftprintf.a libmlx.a ${OBJS}
	@echo $(GREEN)"     - Compiled -"$(NONE)
	@rm -f $(OBJS)
	@rm ./libft.a
	@rm ./libmlx.a
	@rm ./libftprintf.a
	@make fclean -C ./libft/
	@make fclean -C ./ft_printf
	@echo $(CURSIVE)$(GRAY) "     - Deleted object files" $(NONE)

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -f ${OBJS}
	@echo $(GREEN)"     - Removed -"$(NONE)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -f $(NAME) libft.a libftprintf.a libmlx.a
	@make fclean -C ./libft/
	@make fclean -C ./ft_printf/
	@echo $(GREEN)"     - Removed -"$(NONE)

re: fclean all

.PHONY : .c.o all bonus clean fclean re