NAME = push_swap

CC = gcc
FLAGS = -Wall -Werror -Wextra

DIR_SRCS = sources
DIR_OBJS = .objets
DIR_INCS = includes

DIR_LIBFT = libft

LST_SRCS = push_swap.c

LST_OBJS = $(LST_SRCS:.c=.o)

LST_INCS = push_swap.h

SRCS = $(addprefix $(DIR_SRCS)/,$(LST_SRCS))

OBJS = $(addprefix $(DIR_OBJS)/,$(LST_OBJS))

INCS = $(addprefix $(DIR_INCS)/,$(LST_INCS))

AR_LIBFT = $(DIR_LIBFT)/libft.a

all : make_libft $(NAME)

$(NAME) : $(AR_LIBFT) $(OBJS)
				$(CC) $(FLAGS) $^ -o $@

$(DIR_OBJS)/%.o : $(DIR_SRCS)/%.c $(INCS) Makefile | $(DIR_OBJS)
				$(CC) $(FLAGS) -I $(INCS) -c $< -o $@

$(AR_LIBFT) : 
			$(MAKE) -C $(DIR_LIBFT)

$(DIR_OBJS) :
			mkdir -p $@

make_libft :
		$(MAKE) -C $(DIR_LIBFT)

clean :
		rm -rf $(DIR_OBJS)
		$(MAKE) clean -C $(DIR_LIBFT)

fclean : clean
		rm -rf $(NAME)
		$(MAKE) fclean -C $(DIR_LIBFT)

re : fclean all

.PHONY : clean fclean re all make_libft