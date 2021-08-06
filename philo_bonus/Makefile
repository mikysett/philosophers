MAKEFLAGS	+=	--quiet

WHT	= \033[0;37m
BLK	= \033[0;30m
RED	= \033[0;31m
YEL	= \033[0;33m
BLU	= \033[0;34m
GRN	= \033[0;32m

NAME	=	philo_bonus

HEADERS	=	headers

DIR_S	=	srcs

DIR_O	=	obj

# Using wildcards: $(shell find $(DIR_S) -name *.c)
SRCS		:=	srcs/core_util/ft_atoi.c \
				srcs/core_util/ft_exit_error.c \
				srcs/core_util/ft_itoa.c \
				srcs/core_util/ft_memory_util.c \
				srcs/core_util/ft_save_number.c \
				srcs/core_util/ft_strlen.c \
				srcs/ft_catch_results.c \
				srcs/ft_forks_util.c \
				srcs/ft_init_data.c \
				srcs/ft_init_data_util.c \
				srcs/ft_printer.c \
				srcs/ft_single_philo.c \
				srcs/ft_single_philo_util.c \
				srcs/ft_start_philosophers.c \
				srcs/ft_time_util.c \
				srcs/main.c

OBJS		:= $(SRCS:%.c=$(DIR_O)/%.o)

SUB_DIR_O := $(shell find $(DIR_S) -type d)
SUB_DIR_O := $(SUB_DIR_O:%=$(DIR_O)/%)

# Using wildcards: $(shell find $(HEADERS) -name *.h)
DEPS	=	headers/ft_catch_results.h \
			headers/ft_core_util.h \
			headers/ft_forks_util.h \
			headers/ft_init_data.h \
			headers/ft_printer.h \
			headers/ft_single_philo.h \
			headers/ft_start_philosophers.h \
			headers/ft_time_util.h \
			headers/ft_types.h \
			headers/philosophers.h

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -pthread

INCLUDES	= -I $(HEADERS)

LIBS	=	

RM		=	rm -f

$(DIR_O)/%.o: %.c
			@mkdir -p $(DIR_O)
			@mkdir -p $(SUB_DIR_O)
			$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME):	$(DEPS) $(OBJS)
			$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBS)
			printf "$(WHT)[$(GRN)$(NAME) COMPILED$(WHT)]\n"

all:		$(NAME)

clean:
			$(RM) $(OBJS)
			$(RM) $(BONUS_OBJS)
			printf "$(WHT)[$(YEL)$(NAME) OBJS REMOVED$(WHT)]\n"

fclean:		clean
			$(RM) $(NAME)
			printf "$(WHT)[$(YEL)$(NAME) BINARIES REMOVED$(WHT)]\n"

re:			fclean all

.PHONY:		all clean fclean re
